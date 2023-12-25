#!/bin/bash

EXEC_FILE="./a.out"
TEST_DIR="../test_cases"

for entry in "$TEST_DIR"/*
do
    echo "# TESTCASE '$entry'"
    "$EXEC_FILE" < "$entry"
    echo ""
done