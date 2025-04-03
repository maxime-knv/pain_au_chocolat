/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** is_bool.c
*/

#include <string.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <ctype.h>
#include <stdlib.h>

bool is_bool(char *str)
{
    char *lower_str = strdup(str);
    bool to_return = false;

    for (int i = 0; lower_str[i] != '\0'; i++){
        lower_str[i] = tolower(lower_str[i]);
    }
    if (strcmp(lower_str, "false") == 0 || strcmp(lower_str, "true") == 0){
        to_return = true;
    } else {
        to_return = false;
    }
    free(lower_str);
    return to_return;
}
