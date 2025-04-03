make re
gcc main.c libcuddle.a
valgrind ./a.out script/data.csv
rm a.out
make fclean