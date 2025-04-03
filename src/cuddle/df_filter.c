/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** df_filter
*/

#include <stdlib.h>
#include <string.h>
#include "dataframe.h"
#include "cuddle.h"
#include "my.h"

static int get_data_size(void ***data, int column_index
    , bool (*filter_func) (void *value))
{
    int counter = 0;

    if (column_index == -1)
        return -1;
    for (int i = 0; data[i] != NULL; i++){
        if (filter_func(data[i][column_index]))
            counter++;
    }
    return counter;
}

static void ***get_filtered_data(dataframe_t *df, int column_index
    , bool (*filter_func) (void *value), int nb_rows)
{
    void ***new_data = NULL;
    int j = 0;

    if (nb_rows == -1)
        return NULL;
    new_data = malloc(sizeof(void **) * (nb_rows + 1));
    for (int i = 0; df->data[i] != NULL; i++){
        if (filter_func(df->data[i][column_index]) == true){
            new_data[j] = copy_row(df, df->data[i]);
            j++;
        }
    }
    new_data[j] = NULL;
    return new_data;
}

dataframe_t *df_filter(dataframe_t *df, const char *column
    , bool (*filter_func) (void *value))
{
    dataframe_t *new_df = NULL;
    int column_index = 0;
    int nb_rows = 0;

    if (df == NULL || column == NULL || filter_func == NULL)
        return NULL;
    column_index = get_column_index(df->column_names, column);
    if (column_index == -1)
        return NULL;
    nb_rows = get_data_size(df->data, column_index, filter_func);
    new_df = malloc(sizeof(dataframe_t));
    new_df->separators = strdup(df->separators);
    new_df->nb_columns = df->nb_columns;
    new_df->nb_rows = nb_rows;
    new_df->column_names = my_copy_word_array(df->column_names);
    new_df->column_types = copy_column_types(df->column_types
        , df->nb_columns);
    new_df->data = get_filtered_data(df, column_index, filter_func, nb_rows);
    return new_df;
}
