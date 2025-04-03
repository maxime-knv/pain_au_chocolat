/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** copy_column_types
*/

#include <stdlib.h>
#include "dataframe.h"
#include "cuddle.h"

column_type_t *copy_column_types(column_type_t *column_types, int nb_elements)
{
    column_type_t *new_column_type
        = malloc(sizeof(column_type_t) * nb_elements);

    for (int i = 0; i < nb_elements; i++){
        new_column_type[i] = column_types[i];
    }
    return new_column_type;
}
