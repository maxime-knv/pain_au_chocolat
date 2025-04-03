/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_values_float
*/

#include <stdlib.h>

void *copy_value_float(void *val_to_cpy)
{
    void *value = NULL;

    value = malloc(sizeof(float));
    *(float *)value = *(float *)val_to_cpy;
    return value;
}
