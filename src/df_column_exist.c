/*
** EPITECH PROJECT, 2025
** caca
** File description:
** caca
*/

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "dataframe.h"

bool df_column_exist(dataframe_t *df, char const *column_name)
{
    if (df == NULL) {
        printf("-> flase\n");
        return false;
    }
    for (int i = 0; df->column_names[i] != NULL; i++) {
        if (strcmp(df->column_names[i], column_name) == 0) {
            printf("-> true\n");
            return true;
        }
    }
    printf("-> false\n");
    return false;
}
