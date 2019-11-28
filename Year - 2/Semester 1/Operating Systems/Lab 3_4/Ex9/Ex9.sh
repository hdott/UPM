#!/bin/bash

if test $# -gt 0
then
    for (( i = 1; i <= $1; ++i))
    do
        ./child.sh $i
        echo "Value returned: $?"
    done
fi