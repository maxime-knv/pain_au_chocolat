/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** str_to_void_string
*/


#include <stdbool.h>
#include "my.h"
#include <stdlib.h>
#include <string.h>

void *str_to_void_string(char *str_value)
{
    return strdup(str_value);
}
