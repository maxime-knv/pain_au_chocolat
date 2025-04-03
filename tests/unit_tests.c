/*
** EPITECH PROJECT, 2025
** cuddle
** File description:
** unit_tests.c
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/logging.h>
#include <stdbool.h>
#include <stdio.h>
#include "cuddle.h"

Test(get_type, is_bool){
    char *str = "true";
    int result = get_type(str);

    cr_assert(result == BOOL);

}

Test(get_type, is_string){
    char *str = "string";
    int result = get_type(str);
    cr_assert(result == STRING);
}


Test(get_type, is_string2){
    char *str = "33string";
    int result = get_type(str);
    cr_assert(result == STRING);
}

Test(get_type, is_string3){
    char *str = "10 000";
    int result = get_type(str);
    cr_assert(result == STRING);
}

Test(get_type, is_string4){
    char *str = "10.0.0";
    int result = get_type(str);
    cr_assert(result == STRING);
}

Test(get_type, is_int){
    char *str = "-2";
    int result = get_type(str);
    cr_assert(result == INT);
}

Test(get_type, is_int2){
    char *str = "2";
    int result = get_type(str);
    cr_assert(result != INT);
}

Test(get_type, is_uint){
    char *str = "387";
    int result = get_type(str);
    cr_assert(result == UINT);
}

Test(get_type, is_float){
    char *str = "3.4";
    int result = get_type(str);
    cr_assert(result == FLOAT);
}

Test(get_type, is_negative_float){
    char *str = "-343.9";
    int result = get_type(str);
    cr_assert(result == FLOAT);
}

Test(get_column_names, get_column_mane){
    char **result = get_column_names("./tests/testfiles/test_01.csv", ",");
    char *should[4] = {"name", "age", "city", NULL};
    cr_assert_arr_eq(should, result, 0);
}

// Test(df_write_csv, check_file1){
//     char **result = get_column_names("./tests/testfiles/test_01.csv", ",");
//     char *should[4] = {"name", "age", "city", NULL};

//     FILE *file1 = fopen("file", "r");
//     FILE *file2 = fopen("tests/testfiles/test_01.csv", "r");
//     cr_assert_file_contents_eq(file1, file2);
//     cr_assert_arr_eq(should, result, 0);
// }

Test(df_write_csv, check_file2){
    dataframe_t *df = df_read_csv("not-existing-file", ",");

    cr_assert(df == NULL);
}

Test(df_write_csv, check_file3){
    dataframe_t *df = df_read_csv("tests/testfiles/test_01.csv", NULL);

    cr_assert(df != NULL);
}

Test(df_write_csv, check_file4){
    dataframe_t *df = df_read_csv(NULL, ",");

    cr_assert(df == NULL);
}

// Test(df_write_csv, check_file5){
//     dataframe_t *df = df_read_csv("tests/testfiles/test_01.csv", ",");

//     dataframe_t *df2 = df_head(df, 1);
//     df_write_csv(df2, "tests/testfiles/file");
//     FILE *file1 = fopen("tests/testfiles/file", "r");
//     FILE *file2 = fopen("tests/testfiles/test_01.csv", "r");

//     cr_assert_file_contents_eq(file1, file2);
// }

