#!/bin/bash

if test -z $1
then
    list=$(cat /etc/passwd | tr ":" " " | awk '{print $1}');

    for value in $list
    do
        echo $value
    done
else
    list=$(cat /etc/passwd | tr ":" " " | awk '{print $1}');
    raspuns=true
    for value in $list
    do
        if test $1 = $value
        then
            raspuns=true
            break
        else
            raspuns=false
        fi
    done

    if $raspuns = true
    then
        echo "Utilizatorul $1 a fost gasit"
    else
        echo "Utilizatorul $1 NU a fost gasit"
    fi
fi