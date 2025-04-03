/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** get_nb_rows.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "cuddle.h"

int get_nb_rows(char const *filename)
{
    FILE *file = fopen(filename, "r");
    int nb = 0;
    char *buff = NULL;
    size_t len = 0;

    if (file == NULL)
        return ERROR;
    while (getline(&buff, &len, file) != -1) {
            nb++;
    }
    nb--;
    free(buff);
    fclose(file);
    return nb;
}
