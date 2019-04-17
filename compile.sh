#!/bin/sh
gcc -c main.c lib.c player_1_func.c player_2_func.c
gcc -o quoridor main.o lib.o player_1_func.o player_2_func.o
rm main.o lib.o player_1_func.o player_2_func.o
