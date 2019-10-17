#!/bin/bash

wordlist=$(ls /etc)

for word in $wordlist
do
    if test -d /etc/$word
    then
        export PATH=$PATH:/etc/$word
    fi
done

exit 0