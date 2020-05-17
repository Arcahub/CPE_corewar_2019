/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** main
*/

#include <unistd.h>
#include "asm/cw_asm.h"
#include "my/my.h"

static int cw_asm_display_usage(void)
{
    write(1, "USAGE\n", 6);
    write(1, "./asm file_name[.s]\n", 20);
    write(1, "DESCRIPTION\n", 12);
    write(1, "file_name file in assembly language to be converted into" \
        " file_name.cor, an\n", 75);
    write(1, "executable in the Virtual Machine.\n", 35);
    return 0;
}

int main(int argc, char **argv)
{
    if (argc == 2 && !my_cstrcmp("-h", argv[1]))
        return cw_asm_display_usage();
    return (cw_asm(argc, argv));
}
