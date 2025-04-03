/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_column_names.c
*/

#include <sys/stat.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "my.h"

char **get_column_names(char const *filename, char const *separator)
{
    FILE *file = fopen(filename, "r");
    char *buff = NULL;
    char **arr = NULL;
    size_t len = 0;

    if (separator == NULL || file == NULL)
        return NULL;
    getline(&buff, &len, file);
    if (buff == NULL)
        return NULL;
    arr = my_str_to_word_array(buff, separator, DEFAULTMODE);
    free(buff);
    fclose(file);
    return arr;
}
