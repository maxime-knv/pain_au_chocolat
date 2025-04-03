/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_multiple_rows
*/

#include "cuddle.h"
#include <stdlib.h>

void ***copy_multiple_rows(dataframe_t *df, int rows_nb, int start, int nrows)
{
    int end = start + nrows;
    int j = 0;
    void ***new_row_arr = NULL;

    if (nrows > rows_nb)
        nrows = rows_nb;
    if (end > rows_nb - 1)
        end = rows_nb;
    new_row_arr = malloc(sizeof(void **) * (rows_nb + 1));
    for (int i = start; i < end; i++){
        new_row_arr[j] = copy_row(df, df->data[i]);
        j++;
    }
    new_row_arr[j] = NULL;
    return new_row_arr;
}
