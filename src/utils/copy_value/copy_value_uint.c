/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_values_uint
*/

#include <stdlib.h>

void *copy_value_uint(void *val_to_cpy)
{
    void *value = NULL;

    value = malloc(sizeof(unsigned int));
    *(unsigned int *)value = *(unsigned int *)val_to_cpy;
    return value;
}
