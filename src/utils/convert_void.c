/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** convert_void.c
*/

#include <stddef.h>
#include "cuddle.h"
#include "dataframe.h"


double convert_void(dataframe_t *df, int i, void *nb)
{
    double dbl = 0;

    if (df->column_types[i] == INT)
        dbl = (double)(*(int *)nb);
    if (df->column_types[i] == UINT)
        dbl = (double)(*(unsigned int *)nb);
    if (df->column_types[i] == FLOAT)
        dbl = (double)(*(float *)nb);
    return dbl;
}
