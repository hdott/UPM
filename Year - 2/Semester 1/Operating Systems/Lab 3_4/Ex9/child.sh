#!/bin/bash

#indexul procesului lansat
index=$1

#pid ppid user euid
value=$(ps -q $$ -o pid,ppid,user,euid)
set $value
pid=$5
ppid=$6
user=$7
euid=$8

echo "[$index] PID: $pid   PPID: $ppid   USER: $user   ID: $euid"
sleep 2

exit $(( RANDOM % 255))