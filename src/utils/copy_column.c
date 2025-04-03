/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_column
*/

#include <stdlib.h>
#include "cuddle.h"
#include "dataframe.h"

void **copy_column(dataframe_t *dataframe, int index)
{
    void **new_column = malloc(sizeof(void *) * (dataframe->nb_rows + 1));

    for (int i = 0; dataframe->data[i] != NULL; i++){
        new_column[i] = dataframe->data[i][index];
    }
    new_column[dataframe->nb_rows] = NULL;
    return new_column;
}
