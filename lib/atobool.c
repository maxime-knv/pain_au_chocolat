/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** atobool
*/

#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

bool atobool(char *str)
{
    char *lower_str = strdup(str);
    bool to_return = false;

    for (int i = 0; lower_str[i] != '\0'; i++){
        lower_str[i] = tolower(lower_str[i]);
    }
    if (strcmp(lower_str, "false") == 0){
        to_return = false;
    } else {
        to_return = true;
    }
    free(lower_str);
    return to_return;
}
