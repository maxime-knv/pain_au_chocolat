/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** calculate_mean.c
*/

#include <stddef.h>
#include <stdio.h>
#include "cuddle.h"
#include "dataframe.h"

double calculate_mean(dataframe_t *df, int i)
{
    void **column = copy_column(df, i);
    double nb = 0;

    for (int j = 0; column[j] != NULL; j++) {
        nb += convert_void(df, i, column[j]);
    }
    nb = nb / df->nb_rows;
    return nb;
}
