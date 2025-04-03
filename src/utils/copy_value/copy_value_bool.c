/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_values_bool
*/

#include <stdlib.h>
#include <stdbool.h>

void *copy_value_bool(void *val_to_cpy)
{
    void *value = NULL;

    value = malloc(sizeof(bool));
    *(bool *)value = *(bool *)val_to_cpy;
    return value;
}
