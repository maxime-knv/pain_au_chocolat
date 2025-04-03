/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** my_get_array_size
*/

#include <stddef.h>

int my_get_array_size(char **word_array)
{
    int counter = 0;

    for (int i = 0; word_array[i] != NULL; i++){
        counter++;
    }
    return counter;
}
