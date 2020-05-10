/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** cw_asm_error
*/

#ifndef CW_ASM_ERROR_H_
#define CW_ASM_ERROR_H_

#include <stdbool.h>

//type of error output
enum {ERROR = 0, WARNING = 1, NOTE = 2};

//possible colour output
enum {
    RESET = 0,
    RED = 1,
    GREEN = 2,
    YELLOW = 3,
    BLUE = 4,
    MAGENTA = 5,
    CYAN = 6
};

//possible type output
enum {CHAR, INT, STRING};

//color type
typedef struct cw_asm_error_color {
    char color;
    bool bold;
} cw_asm_error_color_t;

//context of the error
typedef struct cw_asm_error_context {
    int line;
    int column;
    char type;
    char *str_line;
} cw_asm_error_context_t;

typedef struct cw_asm_error_content {
    cw_asm_error_color_t color;
    char type;
    void *content;
} cw_asm_error_content_t;

//color
void cw_asm_error_color(cw_asm_error_color_t color);
void cw_asm_error_color_reset(void);

//display
void cw_asm_error_put_str(char *str, cw_asm_error_color_t color);
void cw_asm_error_put_nb(int nb, cw_asm_error_color_t color);
void cw_asm_error_put_char(char c, cw_asm_error_color_t color);
void cw_asm_error_put_var(cw_asm_error_color_t color,
    char type, va_list arg);
void cw_asm_error_put(cw_asm_error_color_t color,
    char *str, ...);

//usage
void cw_asm_error_list(cw_asm_error_context_t context, char *str, ...);
void cw_asm_error(cw_asm_error_context_t context,
    cw_asm_error_content_t content);

#endif /* !CW_ASM_ERROR_H_ */
