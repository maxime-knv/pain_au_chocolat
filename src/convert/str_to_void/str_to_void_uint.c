/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** str_to_void_uint
*/

#include <stdbool.h>
#include "my.h"
#include <stdlib.h>

void *str_to_void_uint(char *str_value)
{
    void *value = NULL;

    value = malloc(sizeof(unsigned int));
    *(unsigned int *)value = atoi(str_value);
    return value;
}
