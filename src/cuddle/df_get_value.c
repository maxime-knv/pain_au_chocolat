/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** df_get_value
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dataframe.h"
#include "cuddle.h"

void *df_get_value(dataframe_t *dataframe, int row, const char *column)
{
    int column_index = 0;

    if (dataframe == NULL || column == NULL
        || row > dataframe->nb_rows || row < 0)
        return NULL;
    column_index = get_column_index(dataframe->column_names, column);
    if (column_index == -1)
        return NULL;
    return dataframe->data[row][column_index];
}
