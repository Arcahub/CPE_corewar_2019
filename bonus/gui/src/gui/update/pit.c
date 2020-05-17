/*
** EPITECH PROJECT, 2020
** gui [WSL: Ubuntu]
** File description:
** pit
*/

#include "corewar-gui/gui.h"

static void draw_memory(cg_ui_t *ui, cw_vm_t *vm)
{
    int max_y, max_x = 0;
    usize_t current_mem = 0;

    getmaxyx(ui->pit_win, max_y, max_x);
    for (int y = 1; y < max_y; y++) {
        for (int x = 1; x < max_x; x += 2) {
            mvwprintw(ui->pit_win, y, x, "%02x", vm->mem[current_mem++]);
            if (x + 1 < max_x)
                x++;
        }
    }
}

void cg_update_pit(cg_ui_t *ui, cw_vm_t *vm)
{
    draw_memory(ui, vm);
}