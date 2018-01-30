#We sort the hidden file first because it has higher priority than the known file
#!/bin/bash
dir=$1
RESULT=`ls-a $dir|sort` #all files, include hidden and not hidden file
HIDE=`ls-a $dir|grep "^\." |sort`
#declare -a ARRAY
declare -a ARRAY
let count=0


for FILE in $HIDE
do
	if[!L "$dir/$FILE"] #if file exits and is a symbolic link
	then
		if[-f"$dir/$FILE"]
		then 
			echo "$dir/$FILE is a regular file"
			ARRAY[$count]="$dir/$FILE"
			let count=count+1
		else
			echo"$dir/$FILE is NOT a regular file."
		fi
	fi
done











for FILE in $RESULT
do
	if[!L "$dir/$FILE"] #if file exits and is a symbolic link
	then
		if[-f"$dir/$FILE"]
		then 
			echo "$dir/$FILE is a regular file"
			ARRAY[$count]="$dir/$FILE"
			let count=count+1
		else
			echo"$dir/$FILE is NOT a regular file."
		fi
	fi
done
echo "There are $count regular files"		
#now we have an array, we need two for loops to find the duplicate 
for i in {0..$ARRAY}
let cs1=md5sum ${ARRAY[$i]}
do
	${FDARR[$i]}
	for j in {i+1..$ARRAY}	
	let cs2=md5sum ${ARRAY[$j]}
	if [ "$ad1" -eq "$ad2" ] 
		then
		rm ${ARRAY[$j]}
		ln ${ARRAY[$i]} ${ARRAY[$j]}

		fi

