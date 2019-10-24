#!/bin/bash

if test -z $1
then
    echo "Programul ia ca argumente [calea_fisier]"
    exit 0
fi

if test $1 = "--help"
then
    echo "Programul ia ca argumente [calea_fisier]"
    exit 0
fi

last_size=$(wc $1 | awk '{print $2}');
echo $last_size

while true
do
    size=$(wc $1 | awk '{print $2}');
    if test $size -gt $last_size;
    then
        value=$((size-last_size));
        if test $value -eq 0
        then
            echo "Fisierul nu si-a modificat numarul de linii"
        fi
        
        if test $value -eq 1
        then
            echo "Fisierul a crescut cu 1 linie are acum [$size] linii"
        else
            echo "Fisierul a crescut cu $value linii are acum [$size] linii"
        fi
            
        last_size=$size;
    fi
    sleep 2
done