/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_nb_columns.c
*/

#include <stdio.h>
#include "my.h"

int get_nb_columns(char **column_names)
{
    if (column_names == NULL)
        return -1;
    return arrlen(column_names);
}
