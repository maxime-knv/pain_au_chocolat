/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_shape.c
*/

#include <stddef.h>
#include "dataframe.h"

dataframe_shape_t df_shape(dataframe_t *dataframe)
{
    dataframe_t *df = dataframe;
    dataframe_shape_t df_s = {0};

    df_s.nb_rows = df->nb_rows;
    df_s.nb_columns = df->nb_columns;
    return df_s;
}
