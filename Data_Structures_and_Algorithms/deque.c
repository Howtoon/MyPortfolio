#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "deque.h"

        //Define the Deque
struct deque {Array *array;int index;int arraySize;int leftIndex;int rightIndex;};

	//Create the Deque
Deque createDeque(int maxSize)
{
	if ((maxSize%2)!=0)
		maxSize+=1;
        Deque newDeque = malloc(sizeof *newDeque);
        newDeque->array = malloc(sizeof (Array)*(maxSize));
	int i;
	for (i=0;i<maxSize;++i)
	{
		newDeque->array[i]='\0';
	}
	newDeque->arraySize = maxSize;
	newDeque->leftIndex = 0;
	newDeque->rightIndex = 0;
	return newDeque;
}
	//Insert Capital Letters
void insertLeft(Deque deque,char a)
{
	deque->leftIndex-=1;
	deque->array[((deque->leftIndex%deque->arraySize)+deque->arraySize)%deque->arraySize]=a;
	return;
}
	//Insert Lowercase Letters
void insertRight(Deque deque,char a)
{
	deque->array[((deque->rightIndex%deque->arraySize)+deque->arraySize)%deque->arraySize]=a;
	deque->rightIndex+=1;
	return;
}
	//Remove From Left End
char removeLeft(Deque deque)
{
	char a='\0';
	a=deque->array[((deque->leftIndex%deque->arraySize)+deque->arraySize)%deque->arraySize];
	deque->leftIndex+=1;
	return a;
}
	//Remove From Right End
char removeRight(Deque deque)
{
	char a='\0';
	deque->rightIndex-=1;
	a=deque->array[((deque->rightIndex%deque->arraySize)+deque->arraySize)%deque->arraySize];
	return a;
}
	//If L&R Position are Equal and L&R Index are Equal
bool isEmpty(Deque deque)
{
	if (((((((deque->rightIndex%deque->arraySize)+deque->arraySize)%deque->arraySize))==(((deque->leftIndex%deque->arraySize)+deque->arraySize)%deque->arraySize))&&(deque->rightIndex==deque->leftIndex)))
	{
		printf("isEmpty");
		return 1;
	}
	return 0;
}
	//If L&R Position are Equal and L&R Index are Exactly arraySize apart
bool isFull(Deque deque)
{
	if (((((((deque->rightIndex%deque->arraySize)+deque->arraySize)%deque->arraySize))==(((deque->leftIndex%deque->arraySize)+deque->arraySize)%deque->arraySize))&&(deque->rightIndex-deque->leftIndex)==deque->arraySize))
	{
		printf("isFull");
		return 1;
	}
	return 0;
}
	//Free dynamically allocated memory
void freeDeque(Deque deque)
{
	free(deque->array);
	free(deque);
	return;
}
