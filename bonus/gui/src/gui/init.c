/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** init
*/

#include <stdlib.h>
#include "corewar-gui/gui.h"

static void setup_colors(void)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);
    init_pair(2, COLOR_BLACK, COLOR_BLUE);
    init_pair(3, COLOR_BLACK, COLOR_WHITE);
    init_pair(4, COLOR_RED, COLOR_MAGENTA);
}

cg_ui_t *cg_ui_init(void)
{
    cg_ui_t *ui = calloc(1, sizeof(cg_ui_t));
    int x, y = 0;

    ui->main_win = initscr();
    getmaxyx(stdscr, y, x);
    setup_colors();
    noecho();
    nodelay(stdscr, true);
    cbreak();
    ui->stats_win = subwin(stdscr, y, x * 0.3, 0, 0);
    ui->pit_win = subwin(stdscr, y, x * 0.7, 0, x * 0.3);
    nodelay(ui->stats_win, true);
    keypad(ui->stats_win, true);
    curs_set(0);
    return (ui);
}