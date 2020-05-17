/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** update
*/

#include <ncurses.h>
#include "corewar-gui/gui.h"
#include "corewar-gui/corewar.h"

static void draw_header(cg_ui_t *ui)
{
    mvwprintw(ui->stats_win, 2, 2, " ______  ______  ______  ______  __     __  ______  ______    ");
    mvwprintw(ui->stats_win, 3, 2, "/\\  ___\\/\\  __ \\/\\  == \\/\\  ___\\/\\ \\  _ \\ \\/\\  __ \\/\\  == \\   ");
    mvwprintw(ui->stats_win, 4, 2, "\\ \\ \\___\\ \\ \\/\\ \\ \\  __<\\ \\  __\\\\ \\ \\/ \".\\ \\ \\  __ \\ \\  __<   ");
    mvwprintw(ui->stats_win, 5, 2, " \\ \\_____\\ \\_____\\ \\_\\ \\_\\ \\_____\\ \\__/\".~\\_\\ \\_\\ \\_\\ \\_\\ \\_\\ ");
    mvwprintw(ui->stats_win, 6, 2, "  \\/_____/\\/_____/\\/_/ /_/\\/_____/\\/_/   \\/_/\\/_/\\/_/\\/_/ /_/ ");
    mvwprintw(ui->stats_win, 7, 2, "                                                              ");
}

static void draw_stats(cg_ui_t *ui, cw_vm_t *vm)
{
    usize_t max_prog_name_len = 1;

    draw_header(ui);
    mvwprintw(ui->stats_win, 9, 2, "Total Cycles    : [ % -3ld ]", vm->state.cycles);
    mvwprintw(ui->stats_win, 10, 2, "Loaded Programs : [ % -3ld ]", vm->prog_count);
    for (size_t i = 0; i < vm->prog_count; i++)
        if (my_cstrlen(vm->programs[i].name) > max_prog_name_len)
            max_prog_name_len = my_cstrlen(vm->programs[i].name);
    for (size_t i = 0; i < vm->prog_count; i++) {
        mvwprintw(ui->stats_win, 11 + i, 2, "   [ % -*s ]", max_prog_name_len, vm->programs[i].name);
    }
}

void cg_ui_update(cg_ui_t *ui, cw_vm_t *vm)
{
    clear();
    cg_update_pit(ui, vm);
    draw_stats(ui, vm);
    box(ui->pit_win, 0, 0);
    box(ui->stats_win, 0, 0);
    refresh();
}