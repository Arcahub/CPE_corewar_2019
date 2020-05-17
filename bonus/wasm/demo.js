import { VirtualMachine } from './corewar-wrapper.js';

const CONFIG_FIELDS = [
  "prog_name_length",
  "comment_length",
  "corewar_exec_magic",
  "reg_size",
  "reg_count",
  "idx_mod",
  "ind_size",
  "dir_size",
  "mem_size",
  "cycle_to_die",
  "cycle_delta",
  "nbr_live",
];

function print(msg) {
  document.getElementById("console").innerText += msg;
}

function println(msg) {
  print(msg + "\n");
}

function runDemo() {
  let config = {};

  document.getElementById("run_button").disabled = true;
  print("Reading the config...");
  for (let x of CONFIG_FIELDS) {
    let field = document.getElementById(x);

    config[x] = field.value;
    field.disabled = true;
  }

  println(" ok!");
  print("Loading the VM...");
  let vm = new VirtualMachine(config);

  println(" ok!");
  print("Destroying the VM...");
  vm.free();
  println(" ok!");
}

Module.onRuntimeInitialized = async _ => {
  console.log("SUCCESSFULLY LOADED THE WASM BINARY!!");
  document.getElementById("run_button").disabled = false;
  document.getElementById("run_button").onclick = runDemo;
};
