/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** df_tail
*/

#include <stdlib.h>
#include <string.h>
#include "cuddle.h"
#include "my.h"

dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows)
{
    int start = 0;
    dataframe_t *new_df = NULL;

    if (nb_rows < 0 || dataframe == NULL)
        return NULL;
    if (nb_rows <= dataframe->nb_rows)
        start = dataframe->nb_rows - nb_rows;
    new_df = malloc(sizeof(dataframe_t));
    new_df->nb_rows = nb_rows;
    new_df->nb_columns = dataframe->nb_columns;
    new_df->column_names = my_copy_word_array(dataframe->column_names);
    new_df->column_types = copy_column_types(dataframe->column_types
        , dataframe->nb_columns);
    new_df->separators = strdup(dataframe->separators);
    new_df->data = copy_multiple_rows(dataframe
        , dataframe->nb_rows, start, nb_rows);
    return new_df;
}
