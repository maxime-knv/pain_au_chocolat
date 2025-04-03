/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** arrlen.c
*/

#include <time.h>

int arrlen(char **array)
{
    int i = 0;

    while (array[i] != NULL) {
        i += 1;
    }
    return i;
}
