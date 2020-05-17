const API = {
  cw_vm_new: Module.cwrap("cw_vm_new", "number", ["number"]),
  cw_vm_destroy: Module.cwrap("cw_vm_destroy", null, ["number"]),
  cw_vm_load_programs: Module.cwrap("cw_vm_load_programs", "boolean", ["number", "number", "number"]),
};

function get_api(name, ret_type, args) {
  if (!API[name])
    API[name] = Module.cwrap(name, ret_type, args);
  return API[name];
}

function type_bindgen(cls, name, fields) {
  let alloc = get_api(name + "_alloc", "number", ["number"]);
  let free = get_api(name + "_free", null, ["number"]);
  let sizeof = get_api(name + "_sizeof", "number");
  let cached_sizeof = undefined;

  Object.defineProperty(cls, "sizeof", {
    get() {
      if (cached_sizeof)
        return cached_sizeof;
      try {
        cached_sizeof = sizeof();
      } catch (e) {
        return undefined;
      }
      return cached_sizeof;
    }
  });

  cls.wrap = function(raw) {
    let element = Object.create(cls.prototype);

    element.raw = raw;
    return element;
  };

  cls.alloc = function(n) {
    return alloc(n);
  };

  cls.wrap_new = function(n) {
    return cls.wrap(cls.alloc(n));
  };

  cls.prototype.free = function() {
    free(this.raw);
  };

  cls.prototype.idx = function(i) {
    return cls.wrap(this.raw + cls.sizeof * i);
  };

  cls.prototype.detach = function() {
    let obj = {};

    for (let field of fields) {
      let type = field[0];
      let fname = field[1];
      let is_const = field[2] === true;
      let is_stack = field[3] === true;

      obj[fname] = this[fname];
    }

    return obj;
  };

  for (let field of fields) {
    let type = field[0];
    let fname = field[1];
    let is_const = field[2] === true;
    let is_stack = field[3] === true;

    if (typeof type == "string") {
      let getter = get_api(name + "_get_" + fname, type, ["number"]);
      let setter = is_const ? null : get_api(name + "_set_" + fname, null, ["number", type]);

      Object.defineProperty(cls.prototype, fname, {
        get() { return getter(this.raw); },
        set(value) {
          if (setter === null)
            return false;
          return setter(this.raw, value);
        },
      });
    } else {
      if (is_stack) {
        let getter = get_api(name + "_get_" + fname, null, ["number", "number"]);
        let setter = is_const ? null : get_api(name + "_set_" + fname, null, ["number", "number"]);

        Object.defineProperty(cls.prototype, fname, {
          get() {
            let val = type.wrap_new(1);
            getter(val.raw, this.raw);
            let detached = val.detach();
            val.free();
            return detached;
          },
          set(value) {
            if (setter === null)
              return false;
            return setter(this.raw, value.raw);
          },
        });
      } else {
        let getter = get_api(name + "_get_" + fname, "number", ["number"]);
        let setter = is_const ? null : get_api(name + "_set_" + fname, null, ["number", "number"]);

        Object.defineProperty(cls.prototype, fname, {
          get() { return type.wrap(getter(this.raw)); },
          set(value) {
            if (setter === null)
              return false;
            return setter(this.raw, value.raw);
          },
        });
      }
    }
  }
}

export class U32Option {
  static some(val) {
    let self = U32Option.wrap_new(1);

    this.is_some = true;
    this.v = val;
  }

  static none() {
    let self = U32Option.wrap_new(1);

    this.is_some = false;
  }
}

type_bindgen(U32Option, "my_opt_u32", [
  ["boolean", "is_some"],
  ["number", "v"],
]);

export class USIZEOption {
  static some(val) {
    let self = USIZEOption.wrap_new(1);

    this.is_some = true;
    this.v = val;
  }

  static none() {
    let self = USIZEOption.wrap_new(1);

    this.is_some = false;
  }
}

type_bindgen(USIZEOption, "my_opt_usize", [
  ["boolean", "is_some"],
  ["number", "v"],
]);

export class Config {
  constructor(obj) {
    if (typeof obj !== "array") {
      obj = [obj];
    }

    this.raw = Config.alloc(obj.length);

    for (let i = 0; i < obj.length; i++) {
      let elem = this.idx(i);

      elem.prog_name_length = obj.prog_name_length;
      elem.comment_length = obj.comment_length;
      elem.corewar_exec_magic = obj.corewar_exec_magic;
      elem.reg_size = obj.reg_size;
      elem.reg_count = obj.reg_count;
      elem.idx_mod = obj.idx_mod;
      elem.ind_size = obj.ind_size;
      elem.dir_size = obj.dir_size;
      elem.mem_size = obj.mem_size;
      elem.cycle_to_die = obj.cycle_to_die;
      elem.cycle_delta = obj.cycle_delta;
      elem.nbr_live = obj.nbr_live;
    }
  }
}

type_bindgen(Config, "cw_config", [
  ["number", "prog_name_length"],
  ["number", "comment_length"],
  ["number", "corewar_exec_magic"],
  ["number", "reg_size"],
  ["number", "reg_count"],
  ["number", "idx_mod"],
  ["number", "ind_size"],
  ["number", "dir_size"],
  ["number", "mem_size"],
  ["number", "cycle_to_die"],
  ["number", "cycle_delta"],
  ["number", "nbr_live"]
]);

export class ProgramDef {
  constructor(obj) {
    if (typeof obj !== "array") {
      obj = [obj];
    }

    this.raw = ProgramDef.alloc(obj.length);

    for (let i = 0; i < obj.length; i++) {
      let elem = this.idx(i);

      elem.prog_name_length = obj.prog_name_length;
      elem.comment_length = obj.comment_length;
      elem.corewar_exec_magic = obj.corewar_exec_magic;
    }
  }
}

type_bindgen(ProgramDef, "cw_program_def", [
  [U32Option, "prog_number"],
  [USIZEOption, "load_address"],
  ["number", "data"],
  ["number", "size"],
]);

export class VirtualMachine {
  constructor(config_def) {
    let config = new Config(config_def);

    this.raw = API.cw_vm_new(config.raw);
    config.free();

    if (this.raw === 0)
      throw new Error("VM creation failed.");
  }

  destroy() {
    API.cw_vm_destroy(this.raw);
  }

  load_programs(prog_defs) {
    API.cw_vm_load_programs(this.raw, );
  }
}

type_bindgen(VirtualMachine, "cw_vm", [
  [Config, "config", true, true],
]);
