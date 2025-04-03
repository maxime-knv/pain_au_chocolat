/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** get_type
*/

#include "cuddle.h"
#include <stdbool.h>

int get_type(char *value)
{
    for (int i = 0; type_func_list[i] != NULL; i++){
        if ((*type_func_list[i])(value)){
            return i;
        }
    }
    return STRING;
}
