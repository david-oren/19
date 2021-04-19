#!/bin/sh

if [ $# -ne 3 ]; then
    echo "Usage: $0 [runnable] [output file] [python prettier]"
    exit 1
fi

runnable=$1
output_file=$2
prettier=$3
segv_status=139

$runnable 2>&1 > $output_file

if [ $? -eq $segv_status ]; then
    echo "Test Segfaulted: the last runned assertion was:"
    tail -n 1 $output_file
else
    python3 $prettier < $output_file
fi
