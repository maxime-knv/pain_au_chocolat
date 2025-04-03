/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** get_column_index
*/

#include <stddef.h>
#include <string.h>
#include "my.h"
#include "dataframe.h"

int get_column_index(char **column_names, const char *column_to_search)
{
    for (int i = 0; column_names[i] != NULL; i++){
        if (strcmp(column_names[i], column_to_search) == 0)
            return i;
    }
    return -1;
}
