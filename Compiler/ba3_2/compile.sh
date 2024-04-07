#!/bin/bash

bison -d -o main.tab.c main.y
flex -o main.yy.c main.l

gcc -o a.out main.tab.c main.yy.c -lfl
