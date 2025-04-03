/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** df_get_values
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dataframe.h"
#include "cuddle.h"

void **df_get_values(dataframe_t *dataframe, const char *column)
{
    void **new_column = NULL;
    int column_index = 0;

    if (column == NULL || dataframe == NULL)
        return NULL;
    column_index = get_column_index(dataframe->column_names, column);
    if (column_index == -1)
        return NULL;
    new_column = malloc(sizeof(void *) * (dataframe->nb_rows + 1));
    if (new_column == NULL)
        return NULL;
    for (int i = 0; dataframe->data[i] != NULL; i++){
        new_column[i] = dataframe->data[i][column_index];
    }
    new_column[dataframe->nb_rows] = NULL;
    return new_column;
}
