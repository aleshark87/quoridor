#!/bin/sh
gcc -c main.c lib.c
gcc -o quoridor main.o lib.o
rm main.o lib.o
