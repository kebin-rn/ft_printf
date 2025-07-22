#!/bin/bash

make fclean
make
cp /home/rnihei/projects/printf-git/main.c ./
cc -o test main.c -L . -l ftprintf
./test
make fclean
rm test
