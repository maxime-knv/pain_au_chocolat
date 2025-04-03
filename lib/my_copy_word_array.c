/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_word_array
*/

#include <stdlib.h>
#include "my.h"

char **my_copy_word_array(char **word_array)
{
    int array_size = my_get_array_size(word_array);
    char **new_word_array = malloc(sizeof(char *) * (array_size + 1));

    if (new_word_array == NULL)
        return NULL;
    for (int i = 0; word_array[i] != NULL; i++){
        new_word_array[i] = my_strdup(word_array[i]);
        if (new_word_array[i] == NULL)
            return NULL;
    }
    new_word_array[array_size] = NULL;
    return new_word_array;
}
