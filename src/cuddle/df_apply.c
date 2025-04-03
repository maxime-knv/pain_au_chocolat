/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_apply.c
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cuddle.h"
#include "my.h"
#include "dataframe.h"

dataframe_t *create_apply_df(dataframe_t *dataframe, int nb_rows,
    char const *column, void *(*apply_func)(void *value))
{
    dataframe_t *new_df = malloc(sizeof(dataframe_t));
    int index_column = get_column_index(dataframe->column_names, column);

    new_df->data = malloc(sizeof(void **) * (dataframe->nb_rows + 1));
    for (int i = 0; i < nb_rows; i++) {
        new_df->data[i] = copy_row(dataframe, dataframe->data[i]);
    }
    new_df->data[nb_rows] = NULL;
    for (int i = 0; i < dataframe->nb_rows; i++) {
        new_df->data[i][index_column] =
            apply_func(dataframe->data[i][index_column]);
    }
    new_df->nb_rows = dataframe->nb_rows;
    new_df->nb_columns = dataframe->nb_columns;
    new_df->column_names = my_copy_word_array(dataframe->column_names);
    new_df->separators = strdup(dataframe->separators);
    new_df->column_types = copy_column_types(dataframe->column_types,
        dataframe->nb_columns);
    return new_df;
}

dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value))
{
    dataframe_t *new_df = NULL;

    if (column == NULL || dataframe == NULL || apply_func == NULL)
        return NULL;
    new_df = create_apply_df(dataframe, dataframe->nb_rows,
        column, (*apply_func));
    return new_df;
}
