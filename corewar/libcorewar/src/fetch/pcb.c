/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** PCB parsing and checking
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "priv.h"

bool cw__pcb_parse(cw_pcb_t *pcb, u8_t raw)
{
    pcb->raw = raw;
    pcb->count = 4;
    for (usize_t i = 0; i < 4 && ((raw >> (i * 2)) & 3) == 0; i++)
        pcb->count--;
    for (usize_t i = 0; i < pcb->count; i++) {
        switch ((raw >> (6 - i * 2)) & 3) {
        case 1:
            pcb->p[i] = CW_PARAM_REG;
            break;
        case 2:
            pcb->p[i] = CW_PARAM_DIR;
            break;
        case 3:
            pcb->p[i] = CW_PARAM_IND;
            break;
        default:
            return (true);
        }
    }
    return (false);
}

bool cw__pcb_matches(const cw_pcb_t *pcb, const char *str)
{
    bool valid = true;

    for (usize_t i = 0; valid && i < pcb->count; i++) {
        valid = false;
        while (*str && my_cstrchr("rdi", *str)) {
            valid = valid || ("rdi"[pcb->p[i] - CW_PARAM_REG] == *str);
            str++;
        }
        valid = valid && (*str == '\0' || *str == ',');
        str += *str ? 1 : 0;
    }
    valid = valid && *str == '\0';
    return (valid);
}
