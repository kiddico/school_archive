#!/bin/bash
temp=0
counter=0
modded=0

> requests
while [ $counter -lt 50 ]; do
	let temp=$RANDOM%120
	let modded=temp%3
	
	if [ $modded -eq 0 ]; then
		let temp=temp-100
	fi
	echo "$temp" >> requests
	let counter=counter+1
done
