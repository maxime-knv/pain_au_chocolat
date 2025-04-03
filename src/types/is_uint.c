/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_uint.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "cuddle.h"

bool is_uint(char *str)
{
    long long int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]) == ISDIGIT_FAILURE)
            return false;
    }
    nb = atoll(str);
    if (nb < 0 || nb >= MAX_UINT)
        return false;
    return true;
}
