/*
** EPITECH PROJECT, 2025
** G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
** File description:
** cuddle
*/

#ifndef CUDDLE_H_
    #define CUDDLE_H_

    #include <stdbool.h>
    #include <stddef.h>
    #include "dataframe.h"

    #define SUCCESS 0
    #define ERROR 84
    #define ISDIGIT_FAILURE 0
    #define MAX_UINT 4294967295
    #define MAX_INT 2147483647
    #define MIN_INT -2147483648
    #define TYPE_LEN 5
    #define INFO_LIST_LEN 6

bool is_bool(char *str);
bool is_float(char *str);
bool is_int(char *str);
bool is_uint(char *str);
int get_column_index(char **column_names, const char *column_to_search);
dataframe_t *get_dataframe(const char *filename, const char *separators);
char ***parse_data(char const *filename, char const *separator, int nb_rows);
column_type_t *get_column_types(char ***parsed_data, int nb_columns);
int get_type(char *value);
int get_single_column_type(char ***parsed_data, int index);
void ***transcribe_data(char ***parsed_data, int columns_nb
    , int rows_nb, column_type_t *column_types);
char **get_column_names(char const *filename, char const *separator);
int get_nb_rows(char const *filename);
int get_nb_columns(char **column_names);
dataframe_t *get_dataframe(const char *filename, const char *separators);
void **copy_row(dataframe_t *df, void **row_to_copy);
void ***copy_multiple_rows(dataframe_t *df, int rows_nb, int start, int nrows);
column_type_t *copy_column_types(column_type_t *column_types, int nb_elements);
void **copy_column(dataframe_t *dataframe, int index);
double convert_void(dataframe_t *df, int i, void *nb);
double calculate_mean(dataframe_t *df, int i);
void *transcribe_value(char *str_value, int type);
void *copy_value(void *val_to_cpy, int type);
double get_min(dataframe_t *df, int i);
double get_max(dataframe_t *df, int i);
double get_std(dataframe_t *df, int i);
void print_columns(dataframe_t *df);
void print_count(dataframe_t *df);
void print_mean(dataframe_t *df);
void print_std(dataframe_t *df);
void print_min(dataframe_t *df);
void print_max(dataframe_t *df);
void *df_get_value(dataframe_t *dataframe, int row, const char *column);
void **df_get_values(dataframe_t *dataframe, const char *column);
void **df_get_unique_values(dataframe_t *dataframe, const char *column);
void df_free(dataframe_t *dataframe);
void free_data(void ***data);
dataframe_t *duplicate_df(dataframe_t *df);


void *copy_value_bool(void *val_to_cpy);
void *copy_value_int(void *val_to_cpy);
void *copy_value_uint(void *val_to_cpy);
void *copy_value_string(void *val_to_cpy);
void *copy_value_float(void *val_to_cpy);




void *str_to_void_bool(char *str_value);
void *str_to_void_int(char *str_value);
void *str_to_void_uint(char *str_value);
void *str_to_void_string(char *str_value);
void *str_to_void_float(char *str_value);

char *bool_to_str(bool boolean);

static void *(* const copy_value_func_list[TYPE_LEN + 1])(void *) = {
    copy_value_bool,
    copy_value_int,
    copy_value_uint,
    copy_value_float,
    copy_value_string,
    NULL,
};

static void *(* const convert_str_to_void_func_list[TYPE_LEN + 1])(char *) = {
    str_to_void_bool,
    str_to_void_int,
    str_to_void_uint,
    str_to_void_float,
    str_to_void_string,
    NULL,
};

static bool (* const type_func_list[TYPE_LEN])(char *) = {
    is_bool,
    is_int,
    is_uint,
    is_float,
    NULL,
};

#endif
