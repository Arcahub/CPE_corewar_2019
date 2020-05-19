/*
** EPITECH PROJECT, 2020
** gui [WSL: Ubuntu]
** File description:
** endgame
*/

#include <ncurses.h>
#include <stdlib.h>
#include <unistd.h>
#include "corewar-gui/gui.h"
#include "corewar-gui/corewar.h"
#include "my/my.h"
#include "my/io.h"

static void print_draw_text(cw_vm_t *vm, cg_ui_t *ui,
    usize_t last_live, u64_t count, WINDOW *win)
{
    int y, x = 0;

    getmaxyx(win, y, x);
    mvwprintw(win, 2, x / 2 - 7, "Draw between: ");
    for (u64_t i = 0; i < vm->prog_count; i++) {
        if (vm->programs[i].last_live == last_live) {
            char *text = my_format("%d (%s)", vm->programs[i].prog_number,
                vm->programs[i].name);

            count--;
            mvwprintw(win, 4 + i, x / 2 - (my_cstrlen(text) / 2), text);
            free(text);
        }
    }
}

static void print_end_text(cw_vm_t *vm, cg_ui_t *ui, WINDOW *win)
{
    u64_t count = 0;
    u64_t prog_number = 0;
    usize_t last_live = 0;
    cw_program_t *prog = NULL;
    int y, x = 0;

    getmaxyx(win, y, x);
    for (u64_t i = 0; i < vm->prog_count; i++) {
        if (vm->programs[i].last_live > last_live) {
            prog_number = vm->programs[i].prog_number;
            prog = &vm->programs[i];
            last_live = vm->programs[i].last_live;
            count = 1;
        } else if (vm->programs[i].last_live == last_live)
            count += 1;
    }
    if (count > 1) {
        print_draw_text(vm, ui, last_live, count, win);
    } else {
        char *won_str = my_format("The champion %d (%s) has won.\n", prog_number,
            prog->name);
        mvwprintw(win, y / 2, x / 2 - (my_cstrlen(won_str) / 2), won_str);
        free(won_str);
    }
}

void cg_logic_endgame(cg_ui_t *ui, cw_vm_t *vm)
{
    int y, x = 0;
    getmaxyx(ui->pit_win, y, x);
    WINDOW *win = derwin(ui->pit_win, 8, 30, y / 2 - 4, x / 2 - 15);

    cg_ui_update(ui, vm);
    wclear(win);
    touchwin(win);
    box(win, 0, 0);
    print_end_text(vm, ui, win);
    refresh();
    sleep(4);
}