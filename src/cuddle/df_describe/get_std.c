/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_std.c
*/

#include <stddef.h>
#include <stdio.h>
#include <math.h>
#include "cuddle.h"
#include "dataframe.h"

double get_std(dataframe_t *df, int i)
{
    void **column = copy_column(df, i);
    double nb = 0;
    double tmp = 0;
    double n = df->nb_rows;
    double mean = calculate_mean(df, i);

    for (int j = 0; column[j] != NULL; j++) {
        tmp = convert_void(df, i, column[j]);
        nb += pow(tmp, 2);
    }
    nb = nb / n;
    nb = nb - pow(mean, 2);
    nb = sqrt(nb);
    return nb;
}
