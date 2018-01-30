#include <stdio.h>
#include <stdlib.h>


int frobcmp(const void  *x, const void *y);

int main()
{
	// initial word can contain 10 characters
	// initial array can contain 10 words
	char* word = (char*)malloc(0);
	char** arrWord = (char**)malloc(0);
	char charIn = ' ';
	int wordCount = 0;
	int charCount = 0; //to count the number of wrd



	while (charIn != EOF)
	{

		charIn = getchar();
		if (charIn == EOF)
		{

			break;
		}
		//there could be some spaces in front of the word
		if (charIn == ' ' && charCount == 0)
			continue;

		//reallocate the word
		//check memory allocation
		word = realloc(word, sizeof(char) *(charCount + 1));
		if (word != NULL)
		{
			word[charCount] = charIn;
			charCount++;
		}
		else if (word == NULL)
		{
			fprintf(stderr, "Error with memory allocation");
			exit(1);
		}
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
		int  j = 0;

		while (1)
		{
			if (arrWord[i][j] == EOF)
			{
				fprintf(stderr, "cannot print, reach EOF");
				exit(1);
			}
			if (arrWord[i][j] == ' ')
				break;
			else
			{
				putchar(arrWord[i][j]);
				j++;
			}
		}
		putchar(' ');
	}
	i = 0;
	// collect memory
	for (; i< wordCount; i++)
		free(arrWord[i]);

	exit(0);

}

int frobcmp(const void  *x, const void *y)
{
	const char* a = *(const char **)x;
	const char* b = *(const char **)y;
	//unfrobnicate data by hand
	for (;;a++, b++)
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

			if ((*a ^ 42) >(*b ^ 42))
				return 1;
			else if ((*a ^ 42) < (*b ^ 42))
				return -1;

		}
	}
	return 0;
}
