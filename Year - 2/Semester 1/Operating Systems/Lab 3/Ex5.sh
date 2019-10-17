#!/bin/sh

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
    
    if test -f ./out.log
    then
        #size=$(ls -nl \"$pwd/out.log\" | awk '{print $5}')
        size=$(ls -nl ./out.log | awk '{print $5}');
    else
        size=0
    fi

    if test $size -gt 4096
    then
        save=$(tail -100 ./out.log)
        echo $save > ./out.log
    fi
  
    sleep 5
done