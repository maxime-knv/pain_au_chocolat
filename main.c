/*
** EPITECH PROJECT, 2024
** cuddle
** File description:
** main.c
*/

#include "include/dataframe.h"
#include "include/cuddle.h"
#include <sys/stat.h>

void *apply_func(void *value) {
    int *new_value = malloc(sizeof(int));

    *new_value = *(int *)value * 2;
    return new_value;
}

int main(int ac, char **av)
{
    dataframe_t *df = df_read_csv("script/data.csv", ",");
    dataframe_t *new_df = NULL;
    // df_write_csv(df, "file");
    // df_info(df);
    //df_describe(df);
    //df_write_csv(df, "caca");
    //new_df = df_apply(df, "age", apply_func);
    //df_write_csv(new_df, "poop");
    df_column_exist(df, "caca");
    // printf("nb_rows = %i\nnb_columns : %i\n", nb_rows, nb_columns);
}
