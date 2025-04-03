/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** transcribe_data
*/

#include <stdlib.h>
#include "dataframe.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "my.h"
#include "cuddle.h"


void *transcribe_value(char *str_value, int type)
{
    void *value = NULL;

    for (int i = 0; convert_str_to_void_func_list[i] != NULL; i++){
        if (i == type)
            value = convert_str_to_void_func_list[i](str_value);
    }
    return value;
}

void **transcribe_row(char **parsed_data, int columns_nb
    , column_type_t *column_types)
{
    void **row_data = malloc(sizeof(void *) * (columns_nb + 1));

    for (int i = 0; parsed_data[i] != NULL; i++){
        row_data[i] = transcribe_value(parsed_data[i], column_types[i]);
    }
    row_data[columns_nb] = NULL;
    return row_data;
}

void ***transcribe_data(char ***parsed_data, int columns_nb
    , int rows_nb, column_type_t *column_types)
{
    void ***ts_data = NULL;

    if (parsed_data == NULL || columns_nb < 1 || column_types == NULL)
        return NULL;
    ts_data = malloc(sizeof(void **) * (rows_nb + 1));
    for (int i = 0; parsed_data[i] != NULL; i++){
        ts_data[i] = transcribe_row(parsed_data[i], columns_nb, column_types);
    }
    ts_data[rows_nb] = NULL;
    return ts_data;
}
