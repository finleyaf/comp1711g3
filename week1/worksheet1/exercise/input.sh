#!/bin/bash
num="USER INPUT"
read -p "Enter a number: " num

for ((i=0; i<num; i++)) do
mkdir dir_$i
done