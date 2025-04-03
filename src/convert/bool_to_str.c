/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** bool_to_str
*/

#include <string.h>
#include <stdbool.h>

char *bool_to_str(bool boolean)
{
    if (boolean)
        return strdup("true");
    return strdup("false");
}
