/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** df_sort
*/

#include <stdlib.h>
#include <string.h>
#include "cuddle.h"
#include "my.h"

static void swap_rows(void ***row_1, void ***row_2)
{
    void **tmp = *row_1;

    *row_1 = *row_2;
    *row_2 = tmp;
}

static void iterate_through(void ***data, int column_index,
    bool (*sort_func)(void *val1, void *val2), int sort_len)
{
    for (int j = 0; j < sort_len; j++){
        if (sort_func(data[j][column_index], data[j + 1][column_index]))
            swap_rows(&data[j], &data[j + 1]);
    }
}

static void sort_data(dataframe_t *df, int column_index,
    bool (*sort_func)(void *val1, void *val2))
{
    int sort_len = df->nb_rows - 1;

    for (int i = 0; df->data[i] != NULL; i++){
        iterate_through(df->data, column_index, sort_func, sort_len);
        sort_len--;
    }
}

dataframe_t *df_sort(dataframe_t *df, const char *column,
    bool (*sort_func)(void *val1, void *val2))
{
    int column_index = 0;
    dataframe_t *new_df = NULL;

    if (df == NULL || column == NULL || sort_func == NULL)
        return NULL;
    column_index = get_column_index(df->column_names, column);
    new_df = duplicate_df(df);
    if (new_df == NULL || column_index == -1)
        return NULL;
    sort_data(new_df, column_index, sort_func);
    return new_df;
}
