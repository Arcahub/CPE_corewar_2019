/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** gui
*/

#ifndef GUI_H_
#define GUI_H_

#include <ncurses.h>
#include "corewar-gui/corewar.h"

typedef struct {
    int selected_core;
} cg_config_t;

typedef struct {
    WINDOW *main_win;
    WINDOW *pit_win;
    WINDOW *stats_win;
    cg_config_t config;
} cg_ui_t;

void cg_ui_update(cg_ui_t *ui, cw_vm_t *vm);
cg_ui_t *cg_ui_init(void);
void cg_update_pit(cg_ui_t *ui, cw_vm_t *vm);

#endif /* !GUI_H_ */
