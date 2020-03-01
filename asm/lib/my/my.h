/*
** EPITECH PROJECT, 2020
** PSU_navy_2019
** File description:
** my
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdbool.h>

int my_strlen(const char *);
char *my_strndup(char *, int);
char *my_strcat(char *, char *);
int my_strncmp(char const *, char const *, int);
char *my_get_line(FILE *);
char *my_strdup(char const *);
char *my_strcpy(char *, char const *);
char *my_strncpy(char *, char const *, int);
bool my_findchr(char *, char);

#endif /* !MY_H_ */
