##
## EPITECH PROJECT, 2025
## G-AIA-200-PAR-2-1-cuddle-maxime.kournikov
## File description:
## Makefile
##

CC ?= gcc

SRC_MY =	lib/my_str_to_word_array.c 	\
			lib/my_show_word_array.c	\
			lib/mini_printf.c			\
			lib/my_strndup.c 			\
			lib/my_strdup.c 			\
			lib/my_strlen.c 			\
			lib/my_strdup.c 			\
			lib/my_putstr.c				\
			lib/my_putchar.c			\
			lib/my_put_nbr.c			\
			lib/arrlen.c 				\
			lib/my_copy_word_array.c	\
			lib/my_get_array_size.c		\
			lib/atobool.c			\

SRC =	src/utils/get_column_index.c 				\
		src/types/is_int.c							\
		src/types/is_uint.c							\
		src/types/is_float.c						\
		src/types/is_bool.c							\
		src/types/get_type.c 						\
		src/utils/get_column_index.c 				\
		src/parse/get_dataframe.c 					\
		src/parse/parse_data.c 						\
		src/parse/get_column_types.c 				\
		src/parse/get_single_column_type.c 			\
		src/parse/transcribe_data.c 				\
		src/utils/get_column_index.c 				\
		src/parse/get_dataframe.c 					\
		src/parse/parse_data.c 						\
		src/parse/get_column_names.c				\
		src/parse/get_nb_rows.c						\
		src/parse/get_nb_columns.c					\
		src/cuddle/df_read_csv.c					\
		src/utils/copy_row.c						\
		src/utils/copy_multiple_rows.c				\
		src/cuddle/df_head.c						\
		src/cuddle/df_tail.c						\
		src/cuddle/df_write_csv.c					\
		src/utils/copy_column_types.c 				\
		src/cuddle/df_shape.c						\
		src/utils/copy_column.c						\
		src/cuddle/df_info.c						\
		src/cuddle/df_filter.c						\
		src/cuddle/df_describe/df_describe.c		\
		src/utils/convert_void.c					\
		src/cuddle/df_describe/calculate_mean.c		\
		src/cuddle/df_describe/get_min.c       		\
		src/cuddle/df_describe/get_max.c			\
		src/cuddle/df_describe/get_std.c			\
		src/cuddle/df_describe/print_columns.c		\
		src/cuddle/df_describe/print_count.c  		\
		src/cuddle/df_describe/print_mean.c 		\
		src/cuddle/df_describe/print_std.c 			\
		src/cuddle/df_describe/print_min.c			\
		src/cuddle/df_describe/print_max.c			\
		src/utils/transcribe_value.c				\
		src/cuddle/df_get_value.c					\
		src/cuddle/df_get_values.c					\
		src/cuddle/df_get_unique_values.c			\
		src/cuddle/df_free.c						\
		src/utils/free_data.c						\
		src/convert/str_to_void/str_to_void_bool.c	\
		src/convert/str_to_void/str_to_void_int.c	\
		src/convert/str_to_void/str_to_void_uint.c	\
		src/convert/str_to_void/str_to_void_float.c	\
		src/convert/str_to_void/str_to_void_string.c\
		src/convert/bool_to_str.c					\
		src/cuddle/df_apply.c						\
		src/utils/copy_value.c						\
		src/utils/copy_value/copy_value_int.c     \
		src/utils/copy_value/copy_value_float.c     \
		src/utils/copy_value/copy_value_string.c     \
		src/utils/copy_value/copy_value_uint.c     \
		src/utils/copy_value/copy_value_bool.c     \
		src/utils/duplicate_df.c \
		src/cuddle/df_to_type.c						\
		src/cuddle/df_sort.c						\
		src/df_column_exist.c





SRC_TEST = tests/unit_tests.c

OBJ_MY = $(SRC_MY:.c=.o)

OBJ = $(SRC:.c=.o)

CFLAGS += -Wall -Wextra

CPPFLAGS += -iquote include -g3

TESTFLAGS = -L. -lcuddle --coverage -lcriterion

TEST_NAME = unit_tests

NAME = libcuddle.a

all:	crlib

crlib:	$(OBJ_MY) $(OBJ_LL) $(OBJ)
	ar rc $(NAME) $(OBJ_MY) $(OBJ_LL) $(OBJ)

clean:
	$(RM) $(OBJ_MY)
	$(RM) $(OBJ)
	$(RM) *.gcno
	$(RM) *gcda

fclean:	clean
	$(RM) $(NAME)
	$(RM) unit_tests

tests_run: crlib
	$(CC) -o $(TEST_NAME) $(SRC_TEST) $(CFLAGS) $(CPPFLAGS) $(TESTFLAGS)
	./$(TEST_NAME)



re: fclean all
