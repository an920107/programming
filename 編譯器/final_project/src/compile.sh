#!/bin/bash

bison -d -t --verbose -o main.tab.c main.y
flex -o main.yy.c main.l

g++ main.tab.c main.yy.c \
    include/python.cpp \
    include/ast.cpp \
    # include/object.cpp \
    # include/state.cpp \
    # include/operator.cpp \
    # include/execute.cpp

rm main.tab.c main.tab.h main.yy.c
