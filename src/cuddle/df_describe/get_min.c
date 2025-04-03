/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_min.c
*/

#include <stddef.h>
#include <stdio.h>
#include "cuddle.h"
#include "dataframe.h"

double get_min(dataframe_t *df, int i)
{
    void **column = copy_column(df, i);
    double nb = 0;
    double tmp = convert_void(df, i, column[0]);

    for (int j = 0; column[j] != NULL; j++) {
        nb = convert_void(df, i, column[j]);
        if (tmp > nb)
            tmp = nb;
    }
    return tmp;
}
