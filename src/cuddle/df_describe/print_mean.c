/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** print_mean.c
*/

#include <stddef.h>
#include <stdio.h>
#include "cuddle.h"
#include "dataframe.h"

void print_mean(dataframe_t *df)
{
    double nb = 0;

    for (int i = 0; df->column_names[i] != NULL; i++) {
        if (df->column_types[i] == INT || df->column_types[i] == UINT ||
        df->column_types[i] == FLOAT) {
            nb = calculate_mean(df, i);
            printf("%.2lf ", nb);
        }
    }
    printf("\n");
}
