/*
** EPITECH PROJECT, 2025
** my.h
** File description:
** include
*/

#ifndef MY_H_
    #define MY_H_
    #include <stdarg.h>
    #include <stdbool.h>

    #define DEFAULTMODE 0
    #define KEEPMODE 1

int my_strlen(char const *);
char **my_str_to_word_array(char const *str, char const *, int);
char *my_strndup(const char *str, int n);
char *my_strdup(const char *str);
void my_free_word_array(char **);
void my_show_word_array(char **);
int my_putstr(char const *);
char *my_strdup(char const *);
int arrlen(char **array);
int my_putstr(char const *str);
void my_putchar(char c);
int my_put_nbr(int nb);
int mini_printf(const char *format, ...);
char **my_copy_word_array(char **word_array);
int my_get_array_size(char **word_array);
bool atobool(char *str);
#endif
