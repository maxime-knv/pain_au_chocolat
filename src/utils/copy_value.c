/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_value
*/

#include <stdlib.h>
#include "cuddle.h"
#include "dataframe.h"
#include <stdio.h>
#include <string.h>

void *copy_value(void *val_to_cpy, int type)
{
    void *value = NULL;

    for (int i = 0; copy_value_func_list[i] != NULL; i++){
        if (i == type)
            value = copy_value_func_list[i](val_to_cpy);
    }
    return value;
}
