make re
gcc main.c -L. -lcuddle -lm
./a.out script/data.csv
rm a.out
# echo '\n\nfile :\n'
# cat file
# echo '\n\n\n'
# rm file
make fclean