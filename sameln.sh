#!/bin/bash
dir=$1
RESULT=`ls $dir|sort`
HIDE=`ls -a $dir|grep '^\.' |sort`
declare -a arr
let count=0

for FILE in $RESULTど
		  if [ ! L "$dir/$FILE" ]
		  then
		  	if [ -f "$dir/$FILE" ]then
			echo "$dir/$FILE is a regular file."  		ARRAY[$count]="$dir/$FILE"  		let count=count+1
			else  		echo "$dir/$FILE is NOT a regular file.fi
		  fiどne
