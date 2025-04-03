/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_row
*/

#include "cuddle.h"
#include <stdlib.h>

static int get_row_size(void **row_to_copy)
{
    int counter = 0;

    for (int i = 0; row_to_copy[i] != NULL; i++){
        counter++;
    }
    return counter;
}

void **copy_row(dataframe_t *df, void **row_to_copy)
{
    int row_size = get_row_size(row_to_copy);
    void **new_row = malloc(sizeof(void *) * (row_size + 1));

    for (int i = 0; row_to_copy[i] != NULL; i++){
        new_row[i] = copy_value(row_to_copy[i], df->column_types[i]);
    }
    new_row[row_size] = NULL;
    return new_row;
}
