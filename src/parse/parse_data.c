/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** parse_data
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "dataframe.h"
#include "my.h"



char ***parse_data(char const *filename, char const *separator, int nb_rows)
{
    char *buffer = NULL;
    size_t size = 0;
    char ***parsed_data = malloc(sizeof(char **) * (nb_rows + 1));
    int i = 0;
    FILE *stream = fopen(filename, "r");

    if (parsed_data == NULL || stream == NULL)
        return NULL;
    getline(&buffer, &size, stream);
    while (getline(&buffer, &size, stream) != -1){
        parsed_data[i] = my_str_to_word_array(buffer, separator, KEEPMODE);
        i++;
    }
    free(buffer);
    fclose(stream);
    parsed_data[i] = NULL;
    if (parsed_data[0] == NULL)
        parsed_data = NULL;
    return parsed_data;
}
