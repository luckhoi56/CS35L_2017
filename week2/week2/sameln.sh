#!/bin/bash
dir=$1
RESULT=`ls $dir|sort` #all files, include hidden and not hidden file
HIDE=`ls -lah $dir|grep '^\.' |sort`
#declare -a ARRAY
declare -a ARR
let count=0


for FILE in $HIDE
do
	if [ ! -L "$dir/$FILE" ] #if file exits and is a symbolic link
	then
		if[ -f "$dir/$FILE" ]
		then 
			echo "$dir/$FILE is a regular file"
			ARR[$count]="$dir/$FILE"
			let count=count+1
		else
			echo"$dir/$FILE is NOT a regular file."
		fi
	fi
done











for FILE in $RESULT
do
	if[! -L "$dir/$FILE"] #if file exits and is a symbolic link
	then
		if[ -f "$dir/$FILE"]
		then 
			echo "$dir/$FILE is a regular file"
			ARR[$count]="$dir/$FILE"
			let count=count+1
		else
			echo "$dir/$FILE is NOT a regular file."
		fi
	fi
done
echo "There are $count regular files"		
#now we have an array, we need two for loops to find the duplicate 
for file in $ARR
let cs1=md5sum ${ARR[$i]}
do
	
	for j in {i+1..$ARR}	
	let cs2=md5sum ${ARR[$j]}
	if [ "$ad1" -eq "$ad2" ] 
		then
		rm ${ARR[$j]}
		ln ${ARR[$i]} ${ARR[$j]}

		fi

