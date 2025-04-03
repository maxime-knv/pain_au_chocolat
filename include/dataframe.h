/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-bscuddle-loan.riyanto
** File description:
** dataframe
*/

#ifndef DATAFRAME_H_
    #define DATAFRAME_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include <stdlib.h>
typedef enum {
    BOOL,
    INT,
    UINT,
    FLOAT,
    STRING,
    UNDEFINED
} column_type_t;

typedef struct dataframe_s {
    int nb_rows;
    int nb_columns;
    char **column_names;
    column_type_t *column_types;
    char *separators;
    void ***data;
} dataframe_t;

typedef struct dataframe_shape_s {
    int nb_rows;
    int nb_columns;
} dataframe_shape_t;


dataframe_t *df_read_csv(const char *filename, const char *separator);
int df_write_csv(dataframe_t *dataframe, const char *filename);
dataframe_t *df_head(dataframe_t *dataframe, int nb_rows);
int df_write_csv(dataframe_t *dataframe, const char *filename);
dataframe_t *df_tail(dataframe_t *dataframe, int nb_rows);
dataframe_shape_t df_shape(dataframe_t *dataframe);
void df_info(dataframe_t *dataframe);
dataframe_t *df_filter(dataframe_t *dataframe, const char *column
    , bool (*filter_func) (void *value));
void df_describe(dataframe_t *dataframe);
dataframe_t *df_apply(dataframe_t *dataframe, const char *column
    , void *(*apply_func)(void *value));
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void df_free(dataframe_t *dataframe);
dataframe_t *df_apply(dataframe_t *dataframe, const char *column,
    void *(*apply_func)(void *value));
dataframe_t *df_to_type(dataframe_t *df, const char *column
    , column_type_t downcast);
dataframe_t *df_sort(dataframe_t *df, const char *column,
    bool (*sort_func)(void *val1, void *val2));
bool df_column_exist(dataframe_t *df, const char *column_name);
#endif
