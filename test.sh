#!/bin/sh
if [  -z $1 ]
then
echo "please choose map by passing map number after test.sh with space"
elif [ $1 = 1 ]
then
./lem-in < $(pwd)/maps_ok/1
elif [ $1 = 2 ]
then
./lem-in < $(pwd)/maps_ok/2
else
echo "Please choose map 1 or 2"
fi