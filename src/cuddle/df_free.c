/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** df_free
*/

#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "dataframe.h"
#include "cuddle.h"

void df_free(dataframe_t *dataframe)
{
    if (dataframe == NULL)
        return;
    if (dataframe->column_names != NULL){
        for (int i = 0; dataframe->column_names[i] != NULL; i++){
            free(dataframe->column_names[i]);
        }
        free(dataframe->column_names);
    }
    if (dataframe->column_types != NULL)
        free(dataframe->column_types);
    if (dataframe->separators != NULL)
        free(dataframe->separators);
    if (dataframe->data != NULL)
        free_data(dataframe->data);
    free(dataframe);
}
