/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** duplicate_df
*/

#include <string.h>
#include "cuddle.h"
#include "dataframe.h"
#include "my.h"

static void ***duplicate_data(dataframe_t *df)
{
    void ***new_data = malloc(sizeof(void **) * (df->nb_rows + 1));

    if (new_data == NULL)
        return NULL;
    for (int i = 0; i < df->nb_rows; i++){
        new_data[i] = copy_row(df, df->data[i]);
    }
    new_data[df->nb_rows] = NULL;
    return new_data;
}

dataframe_t *duplicate_df(dataframe_t *df)
{
    dataframe_t *new_df = NULL;

    if (df == NULL)
        return NULL;
    new_df = malloc(sizeof(dataframe_t));
    if (new_df == NULL)
        return NULL;
    new_df->nb_rows = df->nb_rows;
    new_df->nb_columns = df->nb_columns;
    new_df->column_names = my_copy_word_array(df->column_names);
    new_df->column_types = copy_column_types(df->column_types
        , df->nb_columns);
    new_df->separators = strdup(df->separators);
    new_df->data = duplicate_data(df);
    return new_df;
}
