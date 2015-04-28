/*
	Justin Liang
	Daeseong Kim
	5/26/11
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Define constants for vowels
#define A 0
#define E 4
#define I 8
#define O 14
#define U 20


int main(int argc, char *argv[]) 
{
	//Initialize and declare variables
	char c;
	int letter, templetter, total = 0, i, k, j; 
	int count[26] = {0}, x[26] = {0}, passed = 0, file = 0;
	
	//Set all values of array x to 1 because default state is
	//include all letters
	for(i = 0; i < 26; i++)
	{
		x[i] = 1;
	}
	
	for(k = 1; k < argc; k++)
	{	
		//If option is -V, include vowels
		if (argv[k][0] == '-' && argv[k][1] == 'V')
		{
			for(i = 0; i < 26; i++)
			{
				if(passed == 0)
				{
					if(i == A)
						x[i] = 1;
					else if(i == E)
						x[i] = 1;
					else if(i == I)
						x[i] = 1;
					else if(i == O)
						x[i] = 1;
					else if(i == U)
						x[i] = 1;
				}
				else if(passed == 1)
				{
					x[i] = 1;
				}
			}
			passed = 1;
		}
		
		//If option is -C, include consonants
		else if (argv[k][0] == '-' && argv[k][1] == 'C')
		{
			for(i = 0; i < 26; i++)
			{
				if(x[i] == 0)
				{
					if(i == A)
						x[i] = 0;
					else if(i == E)
						x[i] = 0;
					else if(i == I)
						x[i] = 0;
					else if(i == O)
						x[i] = 0;
					else if(i == U)
						x[i] = 0;
					else
						x[i] = 1;
				}
				else if(passed == 1)
				{
					x[1] = 1;
				}
			}
			passed = 1;
		}

		//If option is -I, include the characters after -I
		else if (argv[k][0] == '-' && argv[k][1] == 'I')
		{	
			for(j = 0; j < strlen(argv[k])-2; j++)
			{
				if(isalpha(argv[k][j+2]))
				{					
					templetter = tolower(argv[k][j+2]) - 97;					
					
					for (i=0;i<26;i++) 
					{
						if (i == templetter)
							x[i] = 1;
					}
				}
			}
			printf("\n");
		}

		//If option is -X, exclude the characters after -X
		else if (argv[k][0] == '-' && argv[k][1] == 'X')
		{
			for(j = 0; j < strlen(argv[k])-2; j++)
			{
				if(isalpha(argv[k][j+2]))
				{
					templetter = tolower(argv[k][j+2]) - 97;				
					for (i=0;i<26;i++) 
					{
						if(i == templetter)
							x[i] = 0;
					}
				}
			}
			printf("\n");
		}
		
		//If option is -R, reverse the state of inclusion and exclusion
		//For example, if it's letters "a, j, q, o" are set to value 1, and rest of
		//the letters are set to value 0, "a, j, q, o" are set to 0 and rest of
		//the letters are set to value 1
		else if (argv[k][0] == '-' && argv[k][1] == 'R')
		{
			for(i=0; i<26; i++)
			{
				if(x[i] == 0)
					x[i] = 1;
				else if(x[i] == 1)
					x[i] = 0;
			}
		}


		//If option is <, check to see if the next string is
		//a valid text file in the directory
		else if (argv[k][0] == '<')
		{
			FILE *sensor;
			sensor = fopen(argv[k+1],"r");
			if(sensor == NULL)
			{
				printf("Error opening file. \n");
				return 0;
			}
			else
			{
				file = 1;
				while((fscanf(sensor, "%c", &c)) == 1)
				{
					letter = tolower(c) - 97;
					for (i=0;i<26;i++) 
					{
						if (i == letter)
							count[i] += 1;
					}
				}
			}
			fclose(sensor);
		}	
		
		//If it's none of the above options, check to see if the file is valid
		//If it's not valid, return a bad option and terminate program
		else
		{	
			FILE *sensor;
			sensor = fopen(argv[k],"r");
			if(sensor != NULL)
			{}
			else
			{
				printf("Bad option: %s \n", argv[k]);
				return 0;
			}
			fclose(sensor);
		}
	}	
	
	//If no file is inputted into arguments,
	//read the user input instead
	if(file == 0)
	{
		while ((c=getchar()) != EOF || isalpha(c)) 
		{
			letter = tolower(c) - 97;
			for (i=0;i<26;i++) 
			{
				if (i == letter)
					count[i] += 1;
			}
		}
	}

	//Print count of the letters
	printf("Letter     Count\n");
	printf("------     -----\n");
	for (i=0;i<26;i++)
	{
		if (x[i] == 1)
			printf("%c            %i\n", i+'a', count[i]);
	}
	printf("           -----\n");
	for (i=0; i<26; i++)
	{
		if (x[i] == 1)
			total += count[i];
	}
	printf("Total:       %i\n", total);
	
	system("pause");
	return 0;
}
