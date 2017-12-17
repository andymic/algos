#!/bin/bash
CP=g++
HEADERS="../data_structures/linkedlist.cc"
EXAMPLES=(linkedlist_manipulation.cc)

for ex in $EXAMPLES
do
    echo "Running $CP $HEADERS $EXAMPLES"
    $CP $HEADERS $EXAMPLES
    ./a.out
done
