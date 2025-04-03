/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** df_read_csv
*/

#include <stddef.h>
#include <unistd.h>
#include "dataframe.h"
#include "cuddle.h"


dataframe_t *df_read_csv(const char *filename, const char *separator)
{
    dataframe_t *dataframe = NULL;

    if (filename == NULL)
        return NULL;
    if (access(filename, F_OK) == -1)
        return NULL;
    if (separator == NULL){
        dataframe = get_dataframe(filename, ",");
    } else {
        dataframe = get_dataframe(filename, separator);
    }
    return dataframe;
}
