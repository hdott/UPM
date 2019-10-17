#!/bin/bash

echo -n "Introduceti un numar intreg: " 
    read N

if test $N -gt 0
then
    if test -d ./TEST
    then
        rm -rf ./TEST
        mkdir TEST
    else
        mkdir TEST
    fi

    for ((value=1; value<=$N; ++value))
    do
        path="./TEST/f$value.data"
        touch $path
        _tmp="";
        for ((i=1; i<=value; ++i))
        do
            _tmp+="$i\n"
        done
        echo $_tmp
        echo -e $_tmp > $path
        #cat $path
    done
else
    echo "Something went Wrong!"
fi