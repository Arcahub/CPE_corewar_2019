/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** PCB check tests
*/

#include <criterion/criterion.h>
#include "../src/fetch/priv.h"

Test(cw_pcb_matches, invalid_pcb)
{
    cr_assert(!cw_pcb_matches(28, "r,r,di"));
    cr_assert(!cw_pcb_matches(68, "r,ir,i"));
    cr_assert(!cw_pcb_matches(27, "i,r,di"));
}

Test(cw_pcb_matches, invalid_pattern)
{
    cr_assert(!cw_pcb_matches(64, "s"));
    cr_assert(!cw_pcb_matches(105, "rri,diir,rr"));
}

Test(cw_pcb_matches, valid_matches)
{
    cr_assert(cw_pcb_matches(64, "r"));
    cr_assert(cw_pcb_matches(128, "d"));
    cr_assert(cw_pcb_matches(192, "i"));
    cr_assert(cw_pcb_matches(92, "ri,dr,id"));
    cr_assert(cw_pcb_matches(104, "ird,d,d"));
    cr_assert(cw_pcb_matches(105, "rrrridd,rdiidiiiii,rdddd,r"));
}

Test(cw_pcb_matches, invalid_matches)
{
    cr_assert(!cw_pcb_matches(64, "r,di"));
    cr_assert(!cw_pcb_matches(64, "i,di"));
    cr_assert(!cw_pcb_matches(64, "d"));
}
