#!/bin/bash

EXEC_FILE="./a.out"
TEST_DIR="../test_cases"

for entry in "$TEST_DIR"/*
do
    param=$(echo "$entry" | cut -d'/' -f 3)
    echo "# TESTCASE '$entry'"
    echo "$($EXEC_FILE $param < "$entry")"
    echo ""
    echo ""
done