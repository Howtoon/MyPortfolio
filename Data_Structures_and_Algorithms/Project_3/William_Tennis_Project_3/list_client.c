#include <stdio.h>
#include <stdbool.h>

#include "list.h"

bool displayMenu();
int readInput();

int main()
{
	List newList = createList();
	printf("Welcome to the Double Linked Circular List Interface");
	bool done=0;
	while(!done){
		done=displayMenu(newList);
	}	
	freeList(newList);
    	return 0;
}

bool displayMenu(List list){
	bool done=0;
	int value=0;
	int index=0;
	printf("\n-----------------\n       Menu\n-----------------\n");
        printf("1. Get the current size of the linked list.\n");
        printf("2. Prepend an item to the linked list.\n");
       	printf("3. Append an item to the linked list.\n");
        printf("4. Insert an item into the linked list.\n");
        printf("5. Remove an item from the linked list.\n");
        printf("6. Get an item at a specific position in the linked list.\n");
        printf("7. Print the list in the forwards direction.\n");
        printf("8. Print the list in the reverse direction.\n");
        printf("9. Exit from the program.");
        printf("\n-----------------\n");
        printf("Please make a selection: ");
        int choice=readInput();
	switch (choice){
		case 1:
			printf("The size of the List is %i\n",size(list));
			break;
		case 2:
			printf("Please enter the value to prepend to the list: ");
			value=readInput();
			prepend(list,value);
			break;
		case 3:
			printf("Please enter the value to append to the list: ");
			value=readInput();
			append(list,value);
			break;
		case 4:
			printf("Please enter the value to Insert: ");
			value=readInput();
			printf("Please enter the Index number: ");
			index=readInput();
			insert(list,index,value);
			break;
		case 5:
			printf("Please enter the Index number to remove: ");
			index=readInput();
			value=removeAt(list,index);
			printf("%i removed from Index #%i",value,index);
			break;
		case 6:
			printf("Please enter the Index number to get: ");
			index=readInput();
			value=get(list,index);
			printf("%i is at Index #%i",value,index);
			break;
		case 7:
			printList(list);
			break;
		case 8:
			printListFromEnd(list);
			break;
		case 9:
			done=1;
			break;
		default:
			break;
	}	
	return done;
}

int readInput(){
	int output=NULL;
	int sign=1;
	while (true){
		int input = getchar();
        	if (input=='-'||input=='+'){
			if (input=='-')
                		sign=-1;;
		}
		else{
			if (input>'9'||input<'0'){
				continue;
			}
			output*=10;
			output+=input-'0';
		}
        	while ((input=getchar())!='\n'){
        		if (input>'9'||input<'0')
					continue;
			output*=10;
                	output+=input-'0';
		}
       		output*=sign;
		return output;
	}
return 0;
}
