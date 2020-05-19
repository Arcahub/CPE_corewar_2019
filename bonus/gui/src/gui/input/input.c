/*
** EPITECH PROJECT, 2020
** gui [WSL: Ubuntu]
** File description:
** input
*/

#include <ncurses.h>
#include <unistd.h>
#include "corewar-gui/gui.h"
#include "corewar-gui/corewar.h"
#include "corewar-gui/input.h"

static void change_core(cg_config_t *config, cw_vm_t *vm, int key)
{
    if (key == 'b')
        config->selected_core--;
    else
        config->selected_core++;
    if (config->selected_core < 0)
        config->selected_core = vm->cores->len - 1;
    else if (config->selected_core >= vm->cores->len)
        config->selected_core = 0;
}

static void change_cursor(cg_ui_t *ui, cw_vm_t *vm, int key)
{
    int y, x = 0;

    getmaxyx(ui->pit_win, y, x);
    switch (key) {
        case 'h':
        case KEY_LEFT:
            ui->config.cursor--;
            break;
        case 'l':
        case KEY_RIGHT:
            ui->config.cursor++;
            break;
        case '^':
        case KEY_HOME:
            ui->config.cursor -= (ui->config.cursor % ((x - 2) / 3 + 1));
            break;
        case '$':
        case KEY_END:
            ui->config.cursor += ((x - 2) / 3 + 1) - (ui->config.cursor % ((x - 2) / 3 + 1)) - 1;
            break;
        case 'j':
        case KEY_DOWN:
            ui->config.cursor += ((x - 2) / 3 + 1);
            break;
        case 'k':
        case KEY_UP:
            ui->config.cursor -= ((x - 2) / 3 + 1);
            break;
        default:
            break;
    }
    if (ui->config.cursor < 0)
        ui->config.cursor = vm->config.mem_size - 1;
    else if (ui->config.cursor >= vm->config.mem_size)
        ui->config.cursor = 0;
}

bool cg_input_logic(cw_vm_t *vm, cg_ui_t *ui)
{
    int key = getch();

    switch (key) {
    case 'h':
    case KEY_LEFT:
    case 'l':
    case KEY_RIGHT:
    case '^':
    case KEY_HOME:
    case '$':
    case KEY_END:
    case 'j':
    case KEY_DOWN:
    case 'k':
    case KEY_UP:
        change_cursor(ui, vm, key);
        break;
    case 'w':
    case 'b':
        change_core(&ui->config, vm, key);
        break;
    case 'q':
        return (true);
    default:
        break;
    }
    return (false);
}