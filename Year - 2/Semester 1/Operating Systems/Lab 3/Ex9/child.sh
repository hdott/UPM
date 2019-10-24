#!/bin/bash

echo "[$1] "
list=$(ps -eo pid,ppid,user,euid)
#echo $list
pid=$(echo $$)
pgrep -f ./child.sh
for value in $list
do
    echo $value
    if test $($value | awk '{print $1}') = $(echo $$)
    then
        echo "am gasit"
    fi
    sleep 2
done
echo $(ps -eo pid,ppid,user,euid | awk '{print $1}')
