#!/bin/bash

if [ "$1" == "-h" ]; then
    echo "Usage: ./run.sh [output_file]"
    echo "If output_file is not provided, output will be printed only to stdout"
    exit 0
fi 

g++ main.cpp -o main
./main | tee $1 | less