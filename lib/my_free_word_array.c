/*
** EPITECH PROJECT, 2025
** setting_up.c
** File description:
** setting_up
*/

#include "my.h"
#include <stdlib.h>

void my_free_word_array(char **word_array)
{
    if (word_array == NULL)
        return;
    for (int i = 0; word_array[i] != NULL; i++){
        free(word_array[i]);
    }
    free(word_array);
    return;
}
