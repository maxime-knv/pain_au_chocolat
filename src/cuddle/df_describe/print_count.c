/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** print_count.c
*/

#include <stddef.h>
#include <stdio.h>
#include "cuddle.h"
#include "dataframe.h"

void print_count(dataframe_t *df)
{
    for (int i = 0; df->column_names[i] != NULL; i++) {
        if (df->column_types[i] == INT || df->column_types[i] == UINT ||
        df->column_types[i] == FLOAT)
            printf("%i ", df->nb_rows);
    }
    printf("\n");
}
