#!/bin/bash

G_DEBUG_FLAG=""

for arg in "$@"
do
    if [ "$arg" = "--debug" ]
    then
        G_DEBUG_FLAG="-D_DEBUG_"
    fi
done

bison -d -t --verbose -o main.tab.c main.y
flex -o main.yy.c main.l

g++ $G_DEBUG_FLAG main.tab.c main.yy.c \
    include/python.cpp \
    include/ast.cpp

rm main.tab.c main.tab.h main.yy.c
