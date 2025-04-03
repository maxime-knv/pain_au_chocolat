/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** get_single_column_type
*/

#include "dataframe.h"
#include "cuddle.h"
#include <stdio.h>
#include <stdlib.h>

int change_type(int type, int tmp_type)
{
    if (tmp_type == STRING)
        return STRING;
    if (tmp_type == INT)
        return INT;
    return type;
}

int get_single_column_type(char ***parsed_data, int index)
{
    int type = get_type(parsed_data[0][index]);
    int tmp_type = 0;

    if (type == STRING)
        return STRING;
    for (int i = 1; parsed_data[i] != NULL; i++){
        tmp_type = get_type(parsed_data[i][index]);
        if (type != tmp_type)
            return change_type(type, tmp_type);
    }
    return type;
}
