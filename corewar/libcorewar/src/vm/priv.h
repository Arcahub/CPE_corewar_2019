/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** priv
*/

#ifndef LIBCOREWAR_VM_PRIV_H_
#define LIBCOREWAR_VM_PRIV_H_

#include "corewar/corewar.h"

void cw_vm_destroy_program(cw_program_t *prog);
bool cw_vm_check_prog(cw_vm_t *self, cw_program_def_t *def);

#endif /* !PRIV_H_ */
