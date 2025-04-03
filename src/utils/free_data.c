/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** free_data
*/

#include <stdlib.h>

void free_data(void ***data)
{
    for (int i = 0; data[i] != NULL; i++){
        for (int j = 0; data[i][j] != NULL; j++){
                free(data[i][j]);
        }
        free(data[i]);
    }
    free(data);
}
