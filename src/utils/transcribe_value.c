/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** transcribe_value
*/

#include <stdlib.h>
#include "dataframe.h"
#include <stdio.h>
#include <string.h>

void *transcribe_value(char *str_value, int type)
{
    void *value = NULL;

    if (type == INT){
        value = malloc(sizeof(int));
        *(int *)value = atoi(str_value);
    }
    if (type == UINT){
        value = malloc(sizeof(unsigned int));
        *(unsigned int *)value = atoi(str_value);
    }
    if (type == STRING){
        value = strdup(str_value);
    }
    if (type == FLOAT){
        value = malloc(sizeof(float));
        *(float *)value = atof(str_value);
    }
    return value;
}
