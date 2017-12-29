#ifndef DEQUE_H
#define DEQUE_H
#include <stdbool.h>

typedef char Array;
        //Typedef an char array to be stored in Deque struct.

typedef struct deque *Deque;
        //Typedef a deque * to be Deque.

Deque createDeque(int maxSize);
	//Creates a new que of maxSize
	//Dynamically allocates memory for struct and array
	//Returns new que to client

void insertLeft(Deque deque, char a);
	//Takes in a que and a character
	//Inserts the character into the next open slot to the left

void insertRight(Deque deque, char a);
	//Takes in a que and a character
        //Inserts the character into the next open slot to the right

char removeLeft(Deque deque);
	//Takes in a que
	//Removes and returns the first character to the Left

char removeRight(Deque deque);
        //Takes in a que
        //Removes and returns the first character to the Right

bool isEmpty(Deque deque);
	//Takes in a que
	//Compares the index value of the Left and Right to determine if the que is full
	//Returns True or False as an integer 1/0

bool isFull(Deque deque);
	//Takes in a que
	//Compares the index value of the Left and Right to determine if the que is full
	//Returns True or False as an integer 1/0

void freeDeque(Deque deque);
	//Takes in a que
	//Frees the memory allocated to the que struct 
	//By first freeing the elements of the struct and then the struct itself

#endif
