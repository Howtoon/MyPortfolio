#include <stdio.h>
#include "deque.h"
#include <string.h>

void entryLoop(Deque deque,int maxSize,char *a);

void dataEntry(Deque deque, char a);

int main()
{	
	int stringSize=35;	//Set size of max input array
	int arraySize=10;	//Set size of deque
	char input[stringSize];	//Declare input array
	while(true)		//Loop for continuous run
	{
		printf("\nArraySize Is Set To %i Characters\n",arraySize);
		printf("Enter your String (Max %i Characters): ",stringSize);
		Deque deque=createDeque(arraySize);		//Create deque
		int i=0;					//Declare counter for input array
        	while (true)					//Loop for input
        	{
                	int value = getchar();			//Gets input one character at a time
                	if (value=='\n' || value==EOF)		//Scans for end of String
                        	break;				//Breaks input loop if String is ended
                	input[i]=(char)value;			//Assigns getChar() value to input String array Typedef'd to char
                	++i;					//Increment input counter i
        	}
		input[i]='\0';				//Assigns last character of String to null character
		entryLoop(deque,i,input);		//Calls entryLoop() to process input String
		freeDeque(deque);			//Free Memory allocated deque
	}
	return 0;			//End Program
}
	//Process input String one character at a time
void entryLoop(Deque deque,int maxSize, char *a)
{
	char var;	
        int i;
        printf("\n\tInput: %s\n\tOutput: ",a);
	for (i=0;i<maxSize;++i)				//Increment for each character in the input String
        {
                var=a[i];
		dataEntry(deque, var);
        }
	printf("\n");
	return;
}
	//Tests each character for Capital, Lowercase, and Special Characters
void dataEntry(Deque deque, char a)
{
        char x='\0';
	if ((a>='a'&&a<='z')||(a>='A'&&a<='Z'))		//Insert Right or Left
	{
		if (isFull(deque))			//Cannot Insert if Full
			return;
		if (a>='a'&&a<='z')
			insertRight(deque,a);
		if (a>='A'&&a<='Z')
	        	insertLeft(deque,a);
        }
	if ((a=='+')||(a=='*'))				//Remove Left or Right
	{
		if (isEmpty(deque))			//Cannot Remove if Empty
			return;
		if (a=='+')
        	{
                	x=removeLeft(deque);
        		printf("%c",x);
		}
		if (a=='*')
        	{
                	x=removeRight(deque);
			printf("%c",x);
		}
        }
	return;
}
