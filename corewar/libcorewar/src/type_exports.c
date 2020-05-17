/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Type accessors for use from JavaScript
*/

#include "corewar/corewar.h"

CW_EXPORT_TYPE(cw_config)
CW_EXPORT_TYPE_FIELD(cw_config, prog_name_length, usize_t)
CW_EXPORT_TYPE_FIELD(cw_config, comment_length, usize_t)
CW_EXPORT_TYPE_FIELD(cw_config, corewar_exec_magic, u32_t)
CW_EXPORT_TYPE_FIELD(cw_config, reg_size, usize_t)
CW_EXPORT_TYPE_FIELD(cw_config, reg_count, usize_t)
CW_EXPORT_TYPE_FIELD(cw_config, idx_mod, i64_t)
CW_EXPORT_TYPE_FIELD(cw_config, ind_size, usize_t)
CW_EXPORT_TYPE_FIELD(cw_config, dir_size, usize_t)
CW_EXPORT_TYPE_FIELD(cw_config, mem_size, usize_t)
CW_EXPORT_TYPE_FIELD(cw_config, cycle_to_die, u64_t)
CW_EXPORT_TYPE_FIELD(cw_config, cycle_delta, u64_t)
CW_EXPORT_TYPE_FIELD(cw_config, nbr_live, u64_t)

CW_EXPORT_TYPE(cw_program_def)
CW_EXPORT_TYPE_FIELD(cw_program_def, prog_number, OPT(u32))
CW_EXPORT_TYPE_FIELD(cw_program_def, load_address, OPT(usize))
CW_EXPORT_TYPE_FIELD(cw_program_def, data, u8_t*)
CW_EXPORT_TYPE_FIELD(cw_program_def, size, usize_t)

CW_EXPORT_TYPE(cw_program)
CW_EXPORT_TYPE_FIELD(cw_program, name, char*)
CW_EXPORT_TYPE_FIELD(cw_program, comment, char*)
CW_EXPORT_TYPE_FIELD_GET(cw_program, prog_number, u32_t)

CW_EXPORT_TYPE(cw_core)
CW_EXPORT_TYPE_SFIELD(cw_core, regs.pc, regs_pc, usize_t)
CW_EXPORT_TYPE_SFIELD_GET(cw_core, regs.regs, regs_regs, i64_t*)
CW_EXPORT_TYPE_SFIELD(cw_core, regs.zero, regs_zero, bool)
CW_EXPORT_TYPE_SFIELD(cw_core, state.timeout, state_timeout, usize_t)
CW_EXPORT_TYPE_SFIELD(cw_core, state.age, state_age, u64_t)
CW_EXPORT_TYPE_SFIELD(cw_core, cache.instruct, cache_instruct, OPT(cw_instr))

CW_EXPORT_TYPE(cw_vm)
CW_EXPORT_TYPE_FIELD_GET(cw_vm, config, cw_config_t)
CW_EXPORT_TYPE_FIELD(cw_vm, cycle_to_die, u64_t)
CW_EXPORT_TYPE_FIELD(cw_vm, mem, u8_t*)
CW_EXPORT_TYPE_FIELD(cw_vm, prog_count, usize_t)
CW_EXPORT_TYPE_FIELD(cw_vm, programs, cw_program_t*)
CW_EXPORT_TYPE_SFIELD(cw_vm, state.cycles_since_check, state_cycles_since_check,
    u64_t)
CW_EXPORT_TYPE_SFIELD(cw_vm, state.live_calls, state_live_calls, u64_t)
