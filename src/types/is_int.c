/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_int.c
*/

#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include "cuddle.h"

bool is_int(char *str)
{
    long long int nb = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (isdigit(str[i]) == ISDIGIT_FAILURE && str[i] != '-')
            return false;
    }
    nb = atoll(str);
    if (nb < MIN_INT || nb > 0)
        return false;
    return true;
}
