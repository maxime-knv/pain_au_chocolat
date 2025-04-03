/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** str_to_void_bool
*/

#include <stdbool.h>
#include "my.h"
#include <stdlib.h>

void *str_to_void_bool(char *str_value)
{
    void *value = NULL;

    value = malloc(sizeof(bool));
    *(bool *)value = atobool(str_value);
    return value;
}
