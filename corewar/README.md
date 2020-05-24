# Corewar - VM

This folder contains the implementation of the VM for the corewar. It is split
in two parts:
- [`libcorewar`](libcorewar): The library containing the virtual machine
  implementation.
- [`corewar-cli`](corewar-cli): The command-line interface in compliance with
  the project.

## [libcorewar](libcorewar)

This library implements the arena and virtual machine in which the cores are
running. It also exposes a high-level API to get information about the contents
of the arena and the state of the cores.

## [corewar-cli](corewar-cli)

This is a Command Line Interface (CLI) to host a corewar battle using
`libcorewar`.
