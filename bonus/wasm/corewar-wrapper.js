const API = {
  cw_vm_new: Module.cwrap("cw_vm_new", "number", ["number", "number", "number"]),
  cw_vm_destroy: Module.cwrap("cw_vm_destroy",null, ["number"])
};

function type_bindgen(obj, name, fields) {
  if (!API[name + "_alloc"])
    API[name + "_alloc"] = Module.cwrap(name + "_alloc", "number", ["number"]);
  if (!API[name + "_free"])
    API[name + "_free"] = Module.cwrap(name + "_free", null, ["number"]);

  obj.raw = 0;

  obj.alloc = function(n) {
    if (obj.raw != 0)
      obj.free();
    obj.raw = API[name + "_alloc"](n);
  };

  obj.free = function() {
    API[name + "_free"](obj.raw);
  };

  for (let field of fields) {
    let getter = Module.cwrap(name + "_get_" + field[1], field[0], ["number"]);
    let setter = Module.cwrap(name + "_set_" + field[1], null, ["number", field[0]]);

    Object.defineProperty(obj, field[1], {
      get() { return getter(obj.raw); },
      set(value) { return setter(obj.raw, value); },
    });
  }
}

export class Config {
  constructor(obj) {
    type_bindgen(this, "cw_config", [
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

    this.alloc(1);
    this.prog_name_length = obj.prog_name_length;
    this.comment_length = obj.comment_length;
    this.corewar_exec_magic = obj.corewar_exec_magic;
    this.reg_size = obj.reg_size;
    this.reg_count = obj.reg_count;
    this.idx_mod = obj.idx_mod;
    this.ind_size = obj.ind_size;
    this.dir_size = obj.dir_size;
    this.mem_size = obj.mem_size;
    this.cycle_to_die = obj.cycle_to_die;
    this.cycle_delta = obj.cycle_delta;
    this.nbr_live = obj.nbr_live;
  }
}

export class VirtualMachine {
  constructor(config_def) {
    let config = new Config(config_def);

    this.raw = API.cw_vm_new(config, 0, 0);
    config.free();
  }

  free() {
    API.cw_vm_destroy(this.raw);
  }
}
