/*
** EPITECH PROJECT, 2020
** gui [WSL: Ubuntu]
** File description:
** destroy
*/

#include <ncurses.h>
#include "corewar-gui/gui.h"
#include "corewar-gui/corewar.h"

void cg_ui_destroy(cg_ui_t *ui)
{
    (void)(ui);
    endwin();
}