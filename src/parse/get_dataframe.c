/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** get_dataframe
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "my.h"
#include "dataframe.h"
#include "cuddle.h"

static bool check_nb_columns(void **row, int nb_columns)
{
    int columns_counter = 0;

    for (int i = 0; row[i] != NULL; i++){
        columns_counter++;
    }
    if (columns_counter != nb_columns)
        return false;
    return true;
}

static int check_dataframe(dataframe_t *df)
{
    int nb_columns = df->nb_columns;

    if (df->data == NULL)
        return ERROR;
    for (int i = 0; df->data[i] != NULL; i++){
        if (!check_nb_columns(df->data[i], nb_columns)){
            return ERROR;
        }
    }
    if (df->data == NULL || df->column_names == NULL
        || df->column_types == NULL || df->separators == NULL)
        return ERROR;
    return SUCCESS;
}

static void free_parsed_data(char ***data)
{
    if (data == NULL)
        return;
    for (int i = 0; data[i] != NULL; i++){
        for (int j = 0; data[i][j] != NULL; j++){
                free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
}

dataframe_t *get_dataframe(const char *filename, const char *separators)
{
    dataframe_t *df = malloc(sizeof(dataframe_t));
    char ***parsed_data = NULL;

    if (df == NULL || separators == NULL)
        return NULL;
    df->column_names = get_column_names(filename, separators);
    df->nb_rows = get_nb_rows(filename);
    df->nb_columns = get_nb_columns(df->column_names);
    parsed_data = parse_data(filename, separators, df->nb_rows);
    df->column_types = get_column_types(parsed_data, df->nb_columns);
    df->separators = strdup(separators);
    df->data = transcribe_data(parsed_data, df->nb_columns
        , df->nb_rows, df->column_types);
    free_parsed_data(parsed_data);
    if (check_dataframe(df) == ERROR){
        df_free(df);
        return NULL;
    }
    return df;
}
