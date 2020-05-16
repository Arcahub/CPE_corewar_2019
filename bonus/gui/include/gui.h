/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019 [WSL: Ubuntu]
** File description:
** gui
*/

#ifndef GUI_H_
#define GUI_H_

#include <ncurses.h>

typedef struct {
    WINDOW *main_win;
    WINDOW *pit_win;
    WINDOW *stats_win;
} cg_ui_t;

#endif /* !GUI_H_ */
