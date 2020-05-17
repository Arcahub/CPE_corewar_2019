/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** init
*/

#include <stdlib.h>
#include "corewar-gui/gui.h"

cg_ui_t *cg_ui_init(void)
{
    cg_ui_t *ui = calloc(1, sizeof(ui));
    int x, y = 0;

    ui->main_win = initscr();
    getmaxyx(stdscr, y, x);
    raw();
    keypad(stdscr, true);
    noecho();
    nodelay(stdscr, true);
    cbreak();
    ui->stats_win = subwin(stdscr, y, x * 0.3, 0, 0);
    ui->pit_win = subwin(stdscr, y, x * 0.7, 0, x * 0.3);
    return (ui);
}