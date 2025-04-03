/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** get_column_types
*/

#include "dataframe.h"
#include "cuddle.h"
#include <stdio.h>
#include <stdlib.h>

column_type_t *get_column_types(char ***parsed_data, int nb_columns)
{
    int type = 0;
    column_type_t *column_types = malloc(sizeof(column_type_t) * (nb_columns));

    if (column_types == NULL || parsed_data == NULL)
        return NULL;
    for (int i = 0; parsed_data[0][i] != NULL; i++){
        type = get_single_column_type(parsed_data, i);
        column_types[i] = type;
    }
    return column_types;
}
