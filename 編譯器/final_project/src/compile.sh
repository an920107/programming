#!/bin/bash

bison -d -o main.tab.c main.y
flex -o main.yy.c main.l

g++ main.tab.c main.yy.c \
    include/python.cpp \
    include/object.cpp \
    include/ast.cpp \
    # include/state.cpp \
    # include/operator.cpp \
    # include/execute.cpp

rm main.tab.c main.tab.h main.yy.c
