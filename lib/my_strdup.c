/*
** EPITECH PROJECT, 2025
** my_strdup.c
** File description:
** my_strdup
*/

#include <stdlib.h>

#include "my.h"

char *my_strdup(char const *src)
{
    char *str;
    int i = 0;
    int length = my_strlen(src);

    if (src == NULL)
        return NULL;
    str = malloc(sizeof(char) * (length +1));
    if (str == NULL)
        return NULL;
    while (i < length){
        str[i] = src[i];
        i++;
    }
    str[i] = '\0';
    return str;
}
