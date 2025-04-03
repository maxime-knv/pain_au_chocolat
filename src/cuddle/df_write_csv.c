/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_write_csv.c
*/

#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "cuddle.h"
#include "dataframe.h"

static char *convert_type(dataframe_t *df, int i, int j)
{
    char *str = malloc(sizeof(char) * 100);

    if (df->column_types[j] == BOOL)
        sprintf(str, "%s", bool_to_str(*(bool *)df->data[i][j]));
    if (df->column_types[j] == INT)
        sprintf(str, "%i", *(int *)df->data[i][j]);
    if (df->column_types[j] == UINT)
        sprintf(str, "%u", *(unsigned int *)df->data[i][j]);
    if (df->column_types[j] == FLOAT)
        sprintf(str, "%.2f", *(float *)df->data[i][j]);
    if (df->column_types[j] == STRING){
        str = strdup((char *)df->data[i][j]);
    }
    return str;
}

static int write_into_file(FILE *file, dataframe_t *df, int i, int j)
{
    char *str = convert_type(df, i, j);

    if (j == df->nb_columns - 1) {
        fprintf(file, "%s\n", str);
    } else
        fprintf(file, "%s%s", str, df->separators);
    return 0;
}

int df_write_csv(dataframe_t *dataframe, const char *filename)
{
    dataframe_t *df = dataframe;
    FILE *file = NULL;

    if (filename == NULL || df == NULL)
        return 84;
    file = fopen(filename, "wa");
    for (int i = 0; df->column_names[i] != NULL; i++) {
        if (i == df->nb_columns - 1) {
            fprintf(file, "%s\n", df->column_names[i]);
        } else {
            fprintf(file, "%s%s", df->column_names[i]
                , df->separators);
        }
    }
    for (int i = 0; df->data[i] != NULL; i++) {
        for (int j = 0; df->data[i][j] != NULL; j++)
            write_into_file(file, df, i, j);
    }
    fclose(file);
    return 0;
}
