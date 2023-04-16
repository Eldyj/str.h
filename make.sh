#!/bin/sh

CC=gcc
FLAGS="-O3 -Wall -Wextra -g3"

$CC $FLAGS -c -o str.o str.c
$CC $FLAGS -c -o strio.o strio.c
$CC $FLAGS -c -o strvec.o strvec.c
$CC $FLAGS -c -o strmap.o strmap.c
$CC $FLAGS -c -o strconv.o strconv.c

$CC $FLAGS -o test test.c str.o strvec.o strmap.o strconv.c strio.o

rm *.o
