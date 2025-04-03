/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_values_string
*/

#include <stdlib.h>
#include <string.h>

void *copy_value_string(void *val_to_cpy)
{
    return strdup(val_to_cpy);
}
