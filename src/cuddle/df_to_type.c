/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** df_to_type
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stddef.h>
#include "cuddle.h"
#include "dataframe.h"

static char *void_to_str(void *value, column_type_t type)
{
    char *str = malloc(sizeof(char) * 100);

    if (type == BOOL)
        str = bool_to_str(value);
    if (type == INT)
        sprintf(str, "%i", *(int *)value);
    if (type == UINT)
        sprintf(str, "%u", *(unsigned int *)value);
    if (type == FLOAT)
        sprintf(str, "%.2f", *(float *)value);
    if (type == STRING)
        str = strdup((char *)value);
    return str;
}

static int handle_type_err(void *value,
    column_type_t actual_type, column_type_t change_to)
{
    if (actual_type == INT && *(int *)value < 0
            && change_to == UINT)
        return ERROR;
    return SUCCESS;
}

static int change_type(void ***data,
    column_type_t actual_type, column_type_t change_to, int column_index)
{
    char *tmp_str = NULL;

    for (int i = 0; data[i] != NULL; i++){
        tmp_str = void_to_str(data[i][column_index], actual_type);
        if (handle_type_err(data[i][column_index], actual_type
            , change_to) == ERROR)
            return ERROR;
        data[i][column_index] = transcribe_value(tmp_str, change_to);
    }
    return SUCCESS;
}

dataframe_t *df_to_type(dataframe_t *df, const char *column
    , column_type_t downcast)
{
    int column_index = 0;
    column_type_t column_type = UNDEFINED;
    dataframe_t *new_df = NULL;

    if (df == NULL || column == NULL
        || downcast < 0 || downcast > TYPE_LEN - 1)
        return NULL;
    column_index = get_column_index(df->column_names, column);
    new_df = duplicate_df(df);
    if (new_df == NULL || column_index < 0)
        return NULL;
    column_type = df->column_types[column_index];
    if (column_type == downcast)
        return new_df;
    if (change_type(new_df->data,
        column_type, downcast, column_index) == ERROR)
        return NULL;
    new_df->column_types[column_index] = downcast;
    return new_df;
}
