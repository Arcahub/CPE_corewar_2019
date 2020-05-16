/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** init
*/

#include <stdlib.h>
#include "gui.h"

cg_ui_t *cg_ui_init(void)
{
    cg_ui_t *ui = calloc(1, sizeof(ui));
    int x, y = 0;

    getmaxyx(stdscr, y, x);
    ui->main_win = initscr();
    ui->stats_win = subwin(stdscr, y, x * 0.4, 0, 0);
    ui->pit_win = subwin(stdscr, y, x * 0.6, 0, x * 0.4);
    raw();
    keypad(stdscr, true);
    noecho();
    return (ui);
}