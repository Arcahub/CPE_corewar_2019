/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "asm/cw_asm.h"
#include "asm/cw_asm_conf.h"
#include "asm/header/cw_asm_header.h"
#include "asm/instructs/cw_asm_instruct.h"

cw_asm_conf_t cw_asm_get_conf(int argc, char **argv)
{
    cw_asm_conf_t conf = {NULL, NULL};

    for (int i = 1; i < argc; i++) {
        if (my_cstreq(argv[i], "-o") && argv[i + 1] == NULL)
            exit(84);
        else if (my_cstreq(argv[i], "-o")) {
            conf.output_path = argv[i + 1];
            i += 1;
            continue;
        }
        if (!my_cstreq(argv[i], "-h"))
            conf.input_path = argv[i];
    }
    return (conf);
}

int cw_asm(int argc, char **argv)
{
    cw_asm_conf_t conf = cw_asm_get_conf(argc, argv);
    cw_asm_t *asm_s = cw_asm_create(&conf);
    int ret = 0;

    (void) argc;
    if (asm_s == NULL)
        return (84);
    cw_asm_header_load(asm_s->header, asm_s->fdin);
    ret = cw_asm_instruct_load(&asm_s->instructs, asm_s->fdin);
    if (ret == 84 ||
    asm_s->header->prog_name[0] == '\0' || asm_s->header->comment[0] == '\0') {
        my_fprintf(2, "Error: Abort.\n");
        cw_asm_destroy(asm_s);
        return (84);
    }
    cw_asm_instructs_compile(asm_s->instructs);
    cw_asm_write(asm_s);
    cw_asm_destroy(asm_s);
    return (ret);
}
