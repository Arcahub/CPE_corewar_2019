/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** Unit tests
*/

#include <criterion/criterion.h>
#include "corewar/corewar.h"

Test(CPE_corewar_2019, it_works)
{
    cr_assert_eq(cw_add(2, 2), 4);
}
