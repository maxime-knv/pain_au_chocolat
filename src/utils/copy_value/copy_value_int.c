/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_values_int
*/

#include <stdlib.h>

void *copy_value_int(void *val_to_cpy)
{
    void *value = NULL;

    value = malloc(sizeof(int));
    *(int *)value = *(int *)val_to_cpy;
    return value;
}
