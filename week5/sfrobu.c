#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <limits.h>
#include <ctype.h>
int comparison = 0;
int ignore_case = 0;
int frobcmp(const void  *x, const void *y)
{
	comparison++;
	const char* a = *(const char **)x;
	const char* b = *(const char **)y;
	//unfrobnicate data by hand
	for (;; a++, b++)
	{
		//if both array gets to the end
		if (*a == ' ' && *b == ' ')
		{
			return 0;

		}
		// array only has spaces inside
		// a is less than b
		else if (*a == ' ')
			return -1;
		else if (*b == ' ')
			return 1;
		else
		{
            if (ignore_case == 0)
            {


			if ((*a ^ 42) > (*b ^ 42))
				return 1;
			else if ((*a ^ 42) < (*b ^ 42))
				return -1;
            }
            else if (ignore_case ==1)
            {
                int temp1 = *a ^ 42;
                int temp2 = *b ^42;

                if (temp1 <CHAR_MIN || temp1 >CHAR_MAX || temp2 < CHAR_MIN || temp2 >CHAR_MAX )
                {
                    fprintf(stderr, "out out range for char");
                    exit(1);
                }
                else
                {
                   temp1 = toupper(temp1);
                   temp2 = toupper(temp2);
                   if (temp1 >temp2)
                    return 1;
                   else if (temp1 < temp2)
                        return -1;


                }
            }
		}
	}
	return 0;
}
void sfrob(int a)
{
	int fileSize = a;
	char* word = (char*)malloc(fileSize * sizeof(char));
	char** arrWord = (char**)malloc(0);
	char charIn = ' ';
	int wordCount = 0;
	int charCount = 0; //to count the number of wrd
	int memory = 0;


	while (read(0, &charIn, 1) > 0)
	{


		if (charIn == EOF)
		{

			break;
		}
		//there could be some spaces in front of the word
		if (charIn == ' ' && charCount == 0)
			continue;

		//reallocate the word
		//check memory allocation
		if (memory >= fileSize)
		{
			fileSize += 1;
			word = realloc(word, sizeof(char) *(fileSize));



			if (word == NULL)
			{
				fprintf(stderr, "Error with memory allocation");
				exit(1);
			}

		}


		word[charCount] = charIn;
		charCount++;

		//
		if (charIn == ' ' && charCount > 1)
		{
			//reallocate the array word
			//check memory allocation
			arrWord = realloc(arrWord, sizeof(char*) * (wordCount + 1));
			if (arrWord != NULL)
			{
				arrWord[wordCount] = word;  // put the word into array of word
				wordCount++;
			}
			else if (arrWord == NULL)
			{
				fprintf(stderr, "Error with memory allocation");
				exit(1);
			}

			// reset the word
			word = (char*)malloc(0);
			charCount = 0;
		}
	}
	//Since the while loop has been break,
	//now we need to collect the last word
	if (charCount != 0)
	{
		word = realloc(word, (charCount + 1) * sizeof(char));
		if (word != NULL)
		{
			word[charCount] = ' ';
			charCount++;
		}
		else if (word == NULL)
		{
			fprintf(stderr, "Error with memory allocation");
			exit(1);
		}
		arrWord = realloc(arrWord, (wordCount + 1) * sizeof(char*));
		if (arrWord != NULL)
		{
			arrWord[wordCount] = word;;
			wordCount++;

		}
		else if (arrWord == NULL)
		{
			fprintf(stderr, "Error with memory allocation");
			exit(1);
		}
	}
	// sort and print out everything
	qsort(arrWord, wordCount, sizeof(char*), frobcmp);
	int i = 0;
	for (; i < wordCount; i++)
	{
		char temp = ' ';
		char space = ' ';
		int  j = 0;

		while (1)
		{
			temp = arrWord[i][j];
			if (arrWord[i][j] == EOF)
			{
				fprintf(stderr, "cannot print, reach EOF");
				exit(1);
			}
			if (arrWord[i][j] == ' ')
				break;
			if (write(1, &temp, 1) < 1)
			{
				fprintf(stderr, "cannot print, reach EOF");
				exit(1);

			}
			j++;
		}
		if (write(1, &space, 1) < 1)
		{
			fprintf(stderr, "cannot print, reach EOF");
			exit(1);

		}
	}
	i = 0;
	// collect memory
	for (; i < wordCount; i++)
		free(arrWord[i]);
	printf("Number of comparison %d", comparison);
	exit(0);
}
int main(int argc, char * argv[])
{
    if(argv[1]=="-f")
    {
        ignore_case = 1;
    }
	struct stat fileStat;
	if (fstat(0, &fileStat) < 0)
	{
		fprintf(stderr, "error!");
		exit(1);
	}

	// Check if input is a regular file

	// Pass in file size for initial memory allocation
	int fileSize = fileStat.st_size;
	if (S_ISREG(fileStat.st_mode)) {
		// Pass in file size for initial memory allocation
		int fileLength = fileStat.st_size;
		sfrob(fileLength);
	}
	else {
        fprintf(stderr, "not regular file!");    
		exit(1);
	}



	// initial word can contain 10 characters
	// initial array can contain 10 wordsQ

}



