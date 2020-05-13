/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** PCB check tests
*/

#include <criterion/criterion.h>
#include "../src/fetch/priv.h"

static bool raw_match(u8_t raw, const char *str)
{
    cw_pcb_t pcb;

    return (!cw__pcb_parse(&pcb, raw) && cw__pcb_matches(&pcb, str));
}

Test(cw__pcb_matches, invalid_pcb)
{
    cr_assert(!raw_match(28, "r,r,di"));
    cr_assert(!raw_match(68, "r,ir,i"));
    cr_assert(!raw_match(27, "i,r,di"));
}

Test(cw__pcb_matches, invalid_pattern)
{
    cr_assert(!raw_match(64, "s"));
    cr_assert(!raw_match(105, "rri,diir,rr"));
}

Test(cw__pcb_matches, valid_matches)
{
    cr_assert(raw_match(64, "r"));
    cr_assert(raw_match(128, "d"));
    cr_assert(raw_match(192, "i"));
    cr_assert(raw_match(92, "ri,dr,id"));
    cr_assert(raw_match(104, "ird,d,d"));
    cr_assert(raw_match(105, "rrrridd,rdiidiiiii,rdddd,r"));
}

Test(cw__pcb_matches, invalid_matches)
{
    cr_assert(!raw_match(64, "r,di"));
    cr_assert(!raw_match(64, "i,di"));
    cr_assert(!raw_match(64, "d"));
}
