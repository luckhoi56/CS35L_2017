Assignment 6: 
Homework

For this part, I first used wget to download
the srt.tgz and then used tar -xvzf to unzip the
file. I then cd into the folder and typed:
$make clean check

make: *** [2-test.ppm] Error 1

This error popped up because I had not implemented the
multicore performance yet


I looked at the source code and realized the nested for loops
could implement the concept of parallism. An image could 
be splitted up into sections. Each section would be sponsorred by a
thread. 
When I first did it, when I ran the $make clean check. It would
report the make error. This was because I forgot to 
change the increament of px in the for loop from
px++ to px= px + nthreads. Since we using multithread, the increament
must be different

The second issue I ran into was I did not
use the array pixels[i][j][3] to substitute for the scaled_colors
array. Thus the printf did not show the correct result.
 