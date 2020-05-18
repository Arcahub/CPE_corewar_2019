/*
** EPITECH PROJECT, 2020
** gui [WSL: Ubuntu]
** File description:
** pit
*/

#include "corewar-gui/gui.h"
#include "corewar-gui/corewar.h"

static bool is_pc(cg_ui_t *ui, cw_vm_t *vm, usize_t current_add)
{
    for (size_t i = 0; i < vm->cores->len; i++) {
        if (((cw_core_t*)vm->cores->data[i])->regs.pc == current_add)
            return (true);
    }
    return (false);
}

static void draw_memory(cg_ui_t *ui, cw_vm_t *vm)
{
    int max_y, max_x = 0;
    usize_t current_mem = 0;

    getmaxyx(ui->pit_win, max_y, max_x);
    for (int y = 1; y < max_y; y++) {
        for (int x = 1; x < max_x; x += 2) {
            if (is_pc(ui, vm, current_mem))
                wattron(ui->pit_win, COLOR_PAIR(1));
            mvwprintw(ui->pit_win, y, x, "%02x", vm->mem[current_mem++]);
            if (x + 1 < max_x)
                x++;
            wattroff(ui->pit_win, COLOR_PAIR(1));
        }
    }
}

void cg_update_pit(cg_ui_t *ui, cw_vm_t *vm)
{
    draw_memory(ui, vm);
}