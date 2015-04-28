/*
   nim.c - CS 16 Project 2
   Justin Liang, 5/11/11
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* symbolic constants to keep track of whose turn it is */
#define COMPUTER 0
#define USER     1

/* symbolic constants for mode of computer play */
#define RANDOM 0
#define SMART  1

/* MACROS YOU MUST USE to communicate with the user */
#define prompt_take()        printf("You take: ")
#define illegal_choice()     printf("  illegal ... try again\n\n")
#define leaves(marbles)      printf("  leaves: %d\n\n", (marbles))
#define computer_takes(take) printf("Computer takes: %d\n", (take))

/* prototypes of functions that YOU MUST DEFINE BELOW main */
int random_choice(int marbles);
int smart_choice(int marbles);
int user_choice(int marbles);

/* prototypes of functions already provided below your solution area */
void print_header(int turn, int mode, int marbles);
void announce_winner(int turn);

int main(void) {

    int turn, mode, marbles;	

    /* find random first turn, play mode, and initial number of marbles */    
   	srand(time(NULL));
	turn = rand() % 2;
    mode = rand() % 2;
    marbles = 10 + rand() % 91;

    /* print result of random selections */
    print_header(turn, mode, marbles);

    /******* BEGIN YOUR SOLUTION TO PART D HERE *******/
	while(marbles > 1)
	{
		if(turn == COMPUTER && mode == RANDOM)
		{
			marbles = marbles - random_choice(marbles);
			leaves(marbles);
			turn = USER;
		}

		else if(turn == COMPUTER && mode == SMART)
		{
			marbles = marbles - smart_choice(marbles);
			leaves(marbles);
			turn = USER;
		}

		else if(turn == USER)
		{			
			marbles = marbles - user_choice(marbles);
			leaves(marbles);
			turn = COMPUTER;
		}		
	}


    /******* END OF YOUR SOLUTION TO PART D *******/

    /* finish up */
    announce_winner(turn);
    return 0;
}
           
/******* SOLUTIONS TO PARTS A, B, AND C HERE *******/


/******* DO NOT CHANGE ANYTHING BELOW (read it though) *******/

/* print result of random selections */
void print_header(int turn, int mode, int marbles) 
{
    printf("\nFirst turn: %s\n",
        (turn==COMPUTER ? "computer" : "you"));
    printf("Computer mode: %s\n",
        (mode==RANDOM ? "random" : "smart"));
    printf("Initial marbles: %d\n\n", marbles);
}


/* announce winner (the player who left just one marble) */
void announce_winner(int turn) 
{
    printf("Game over. ");
    if (turn == USER)
        printf("Computer wins!\n");
    else
        printf("You win!\n");
   		putchar('\n');
}

int random_choice(int marbles)
{
	int take = rand()%((marbles/2)-1+1) + 1;
	computer_takes(take);
	return take;
}

int smart_choice(int marbles)
{
	int desiredMarbles, take;
	if(marbles != 63 && marbles != 31 && marbles != 15 && marbles != 7 && marbles != 3 &&  marbles != 1)
	{
	    if(marbles > 63)
			desiredMarbles = 63;
		else if(marbles > 31)
			desiredMarbles = 31;
		else if(marbles > 15)
			desiredMarbles = 15;
		else if(marbles > 7)
			desiredMarbles = 7;
		else if(marbles > 3)
			desiredMarbles = 3;
		else if(marbles > 1)
			desiredMarbles = 1;
		take = marbles - desiredMarbles;
	}

	else
	{
		take = rand()%((marbles/2)-1+1) + 1;
	}	
	computer_takes(take);
	return take;
}

int user_choice(int marbles)
{
	int take;
	
	while(take <= 0 || take > (marbles/2))
	{		
		prompt_take();
		scanf("%i", &take);
		if(take <= 0 || take > (marbles/2))
		{
			illegal_choice();
		}
	}	
	return take;
}
