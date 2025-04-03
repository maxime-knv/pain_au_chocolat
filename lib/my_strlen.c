/*
** EPITECH PROJECT, 2025
** my_strlen.c
** File description:
** returns length of string with given pointer to string
*/

#include <stddef.h>

int my_strlen(char const *str)
{
    int a = 0;

    if (str == NULL)
        return 0;
    while (*str != '\0') {
        a++;
        str++;
    }
    return a;
}
