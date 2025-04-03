/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** df_info.c
*/

#include <stdio.h>
#include <stddef.h>
#include "cuddle.h"
#include "dataframe.h"

void df_info(dataframe_t *df)
{
    char *info_list[INFO_LIST_LEN] = {"bool", "int",
    "unsigned int", "float", "string", NULL};

    if (df == NULL)
        return;
    printf("%i columns:\n", df->nb_columns);
    for (int i = 0; df->column_names[i] != NULL; i++) {
        printf("- %s: %s\n", df->column_names[i],
        info_list[df->column_types[i]]);
    }
}
