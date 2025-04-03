/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_float.c
*/

#include <stdbool.h>
#include <ctype.h>
#include "cuddle.h"

bool is_float(char *str)
{
    int occ = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]) == ISDIGIT_FAILURE && str[i] != '.'
            && str[i] != '-')
            return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.')
            occ += 1;
        if (occ > 1)
            return false;
    }
    if (occ == 0)
        return false;
    return true;
}
