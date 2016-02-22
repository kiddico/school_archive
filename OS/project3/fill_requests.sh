#!/bin/bash
temp=0
counter=0
> requests
while [ $counter -lt 50 ]; do
	let temp=$RANDOM%100
	echo "$temp" >> requests
	let counter=counter+1
done
