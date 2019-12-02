#!/bin/bash

wordlist=$(ls /etc)
echo $wordlist

for word in $wordlist
do
    echo "NUME: $word"
done

exit 0