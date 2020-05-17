/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** update
*/

#include <ncurses.h>
#include "corewar-gui/gui.h"
#include "corewar-gui/corewar.h"


static void draw_stats(cg_ui_t *ui, cw_vm_t *vm)
{
    mvwprintw(ui->stats_win, 5, 2, "Total Cycles : [%ld]", vm->state.cycles);
}

void cg_ui_update(cg_ui_t *ui, cw_vm_t *vm)
{
    /*int c = getch();

    if (c == 'q') {
        endwin();
        exit(0);
    }*/
    clear();
    cg_update_pit(ui, vm);
    draw_stats(ui, vm);
    box(ui->pit_win, 0, 0);
    box(ui->stats_win, 0, 0);
    refresh();
}