#!/bin/bash

if test -f ./out.log
then
    rm ./out.log
fi

while true
do
    value=$(./prog)
    if test $value -eq 0
    then
        echo succes
    else
        echo $value
        echo "err$value" >> out.log
    fi
    
    sleep 5
done