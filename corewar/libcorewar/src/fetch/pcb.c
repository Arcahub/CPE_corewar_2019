/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** PCB parsing and checking
*/

#include "my/my.h"
#include "corewar/corewar.h"
#include "priv.h"

struct pcb {
    u8_t raw;
    usize_t count;
    u8_t p[4];
};

static bool parse_pcb(u8_t raw, struct pcb *pcb)
{
    pcb->raw = raw;
    pcb->count = 4;
    for (usize_t i = 0; i < 4 && ((raw >> (i * 2)) & 3) == 0; i++)
        pcb->count--;
    for (usize_t i = 0; i < pcb->count; i++) {
        switch ((raw >> (6 - i * 2)) & 3) {
        case 1:
        case 2:
        case 3:
            pcb->p[i] = (raw >> (6 - i * 2)) & 3;
            break;
        default:
            return (true);
        }
    }
    return (false);
}

bool cw_pcb_matches(u8_t raw, const char *str)
{
    struct pcb pcb;
    bool valid = true;

    if (parse_pcb(raw, &pcb))
        return (false);
    for (usize_t i = 0; valid && i < pcb.count; i++) {
        valid = false;
        while (*str && my_cstrchr("rdi", *str)) {
            valid = valid || ("rdi"[pcb.p[i] - 1] == *str);
            str++;
        }
        valid = valid && (*str == '\0' || *str == ',');
        str += *str ? 1 : 0;
    }
    valid = valid && *str == '\0';
    return (valid);
}
