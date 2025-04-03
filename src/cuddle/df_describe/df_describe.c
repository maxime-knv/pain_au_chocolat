/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_describe.c
*/

#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "cuddle.h"
#include "dataframe.h"

static void print_describe(dataframe_t *df, int i)
{
    printf("Column: %s\n", df->column_names[i]);
    printf("Count: %i\n", df->nb_rows);
    printf("Mean: %.2f\n", calculate_mean(df, i));
    printf("Std: %.2f\n", get_std(df, i));
    printf("Min: %.2f\n", get_min(df, i));
    printf("Max: %.2f\n", get_max(df, i));
}

void df_describe(dataframe_t *dataframe)
{
    dataframe_t *df = dataframe;

    for (int i = 0; df->column_names[i] != NULL; i++) {
        if (df->column_types[i] == INT || df->column_types[i] == UINT ||
        df->column_types[i] == FLOAT)
            print_describe(df, i);
    }
}
