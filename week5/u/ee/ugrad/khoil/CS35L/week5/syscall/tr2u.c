/*
ll take two inputs into 
the function call tr2u, and we will transpose 
into another character that "to" will request to
Since we are using system call, we should use read and write 
one byte at a time

The idea is that tr with both inputs in the same length
is the same as the mapping. If we have regular ascii table,
if we tr some of them, that some of them now will be map
to another character
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void tr2u(char* from, char* to)
{
	//alphabet table of from


	//alphabet table of to
	//check if from.length() is the same as to.lengh
	char alphabet_table[256];
	int i = 0;
	for (; i < 256; i++)
	{
		alphabet_table[i] = i;
	}
	int from_size = strlen(from);
	int to_size = strlen(to);

	if (from_size != to_size)
	{
		fprintf(stderr, "Froma and To lengths are different");
		exit(1);
	}



	// check for duplicate byte
	i =0;
	for (; i < strlen(from); i++)
	{
		int j = i+1;
		for (; j < strlen(from); j++)
		{
			if (from[i] == from[j])
			{
				fprintf(stderr, "Duplicate found");
				exit(1);
			}

		}
	}
	// modify the table
	i = 0;
	for (; i < strlen(from); i++)
	{
		alphabet_table[from[i]] = to[i];
	}
	char temp[1];
	int state = read (0, temp, 1 );
	while (state >0 )
	{
		write (1, temp,1);
		state = read (0, temp, 1);
		//putchar(alphabet_table[readIn]);
		//readIn = getchar();
	}

}
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		fprintf(stderr, "the inputs should be 2");
		exit(1);
	}
	tr2u(argv[1], argv[2]);
} 
