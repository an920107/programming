#!/bin/bash

EXEC_FILE="./a.out"
TEST_DIR="../test_cases"

for entry in "$TEST_DIR"/*
do
    echo "# TESTCASE '$entry'"
    echo "$($EXEC_FILE < "$entry")"
    echo ""
    echo ""
done