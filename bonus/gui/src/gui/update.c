/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** update
*/

#include <ncurses.h>
#include "corewar-gui/gui.h"

void cg_ui_update(cg_ui_t *ui)
{
    box(ui->pit_win, 0, 0);
    box(ui->main_win, 0, 0);
    refresh();
}