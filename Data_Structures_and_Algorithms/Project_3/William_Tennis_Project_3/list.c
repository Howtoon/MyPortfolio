#include <stdlib.h>
#include <stdio.h>

#include "list.h"
#include "node.h" //list is built upon nodes

struct list {
    int size;	//Stores the size of the list
    Node head;	//Stores the head Node
};
					//Creates a new list
List createList(){
	List newList = malloc(sizeof *newList);			//allocates for new list struct
	newList->head = NULL;					//head set to NULL
    	newList->size = 0;
    	return newList;
}
					//get size of list
int size(List currentList){
    	return currentList->size;
}
								//adds a new node to the beginning and sets it to head
void prepend(List currentList, int value){
    	if (currentList->size==0){				//if list is empty
    		Node newNode = createNode(value, NULL, NULL);	//create newNode store value
		currentList->head=newNode;			//set head to newNode
		setNode(currentList->head,currentList->head);	//setPrevious of newNode itself 
		setNext(currentList->head,currentList->head);	//setNext of newNode to itself
		++currentList->size;				//increment size
		return;
	}
	Node newNode = createNode(value, NULL, NULL);		//if list is not empty create newNode
	setNode(newNode, getPrevious(currentList->head));	//setPrevious of newNode to Previous of oldHead
	setNext(newNode, currentList->head);			//setNext of newNode to oldHead
	setNext(getPrevious(currentList->head), newNode);	//setNext of previous of oldHead to newNode
	setNode(currentList->head,newNode);			//setPrevious of oldHead to newNode
    	currentList->head = newNode;				//newNode becomes the newHead
    	++currentList->size; 					//increment the size of the list
	return;
}
								//adds a newNode to the end of the list
void append(List currentList, int value){
	if (currentList->size==0){				//if list is empty
		Node newNode = createNode(value, NULL, NULL);	//create newNode store value
                currentList->head=newNode;			//set head to newNode
                setNode(currentList->head,currentList->head);	//setPrevious of newNode itself 
                setNext(currentList->head,currentList->head);	//setNext of newNode to itself
                ++currentList->size;				//increment size
                return;	
	}
	Node newNode = createNode(value, NULL, NULL);		//if list is not empty create newNode
	setNext(getPrevious(currentList->head),newNode);	//setNext of Previous of Head to newNode
	setNode(newNode,getPrevious(currentList->head));	//setPrevious of newNode to Previous of Head
	setNext(newNode,currentList->head);			//setNext of newNode to Head
	setNode(currentList->head, newNode);			//setPrevious of Head to newNode
	++currentList->size; 					//increment size
    	return;
}
								//creates and inserts a node into a given index
void insert(List currentList, int index, int value){
    	if(index == 0){ 					//if inserting at beginning, use prepend
        	prepend(currentList, value);
        	return;
    	}
    	if(index == currentList->size){ 			//if inserting at end, use append
        	append(currentList, value);
        	return;
    	}
    	if(index > currentList->size){ 				//if index is greater than size
        	while (index>=currentList->size){		//while index is greater than or equal to size
			index-=currentList->size;		//reduce index by the amount of size
    		}
	}
	if (index < 0 ){					//if index is negative
		while (index<0){				//while index is negative
			index+=currentList->size;		//increase index by amount of size
		}
	}
    								//we can't directly index into a linked list, so we have to loop
    								//we will need to go until we are before where we want to insert
    								//this will enable us to update the next pointer for the node
    								//that will proceed our inserted node
    								//start looping at the head
    	Node currentNode = currentList->head;		//store Head as currentNode
    	int i;						//counter variable
    	for(i = 0; i < index-1; ++i){			//loop until we are before where we want to insert
        	currentNode = getNext(currentNode); 	//store and move to next node
    	}
   	Node nextNode = getNext(currentNode); 		//save Next of currentNode as nextNode
	Node newNode = createNode(value, getNext(currentNode),currentNode);	//create newNode setNext to Next of currentNode setPrevious to currentNode 
	setNode(nextNode, newNode);			//setPrevious of nextNode to newNode
    	setNext(currentNode, newNode);			//setNext of currentNode to newNode
    	++currentList->size; 				//increase size of the list
}
int removeAt(List currentList, int index){	//remove the node at any give index 
    	if(currentList->size == 0){			//if the list is empty do not remove anything
        	printf("Cannot remove element from the list. \n");
        	exit(1);
    	}
    	Node currentNode = currentList->head;				//store Head as currentNode
    	if(index == 0){							//if index is 0
		int value = getValue(currentNode);  			//save value of head
        	setNext(getPrevious(currentNode),getNext(currentNode));	//set next of end to next of oldHead
		setNode(getNext(currentNode),getPrevious(currentNode)); //set previous of newHead to previous of oldHead 
		currentList->head=getNext(currentNode);   		//set head to next of oldHead
        	freeNode(currentNode); 					//FREE MEMORY of oldHead
        	--currentList->size;					//increment size
		return value;						//return value
    	}
	if (index>currentList->size){					//if index is greater than size
		while (index>=currentList->size){			//while index is greater than or equal to size
                        index-=currentList->size;			//reduce index by the amount of size
                }
	}
	if (index < 0 ){						//if index is negative
                while (index<0){					//while index is negative
                        index+=currentList->size;			//increase index by amount of size
                }
        }
	--currentList->size;						//decrement size
   	int i;								//counter variable
    	for(i = 0; i < index-1; ++i)					//loop until we are before where we want to remove
        	currentNode = getNext(currentNode); 			//move to next Node
   	Node removeNode = getNext(currentNode);				//we will need to temporarily store the node we are removing
    	setNext(currentNode, getNext(removeNode));			//next we point the current node to the next of the node we are removing
	setNode(getNext(removeNode),currentNode);			//setPrevious of the Next of the removeNode to currentNode
    	int value = getValue(removeNode);				//save value of removeNode
    	freeNode(removeNode);						//FREE MEMORY of removeNode
    	return value;							//return value
}
int get(List currentList, int index){			//returns the value at a given index
    	if(currentList->size == 0){					//cannot return a value from an exmpty list
        	printf("Cannot get a value from given index. \n");
        	exit(1);
    	}
	if (index>currentList->size){					//if index is greater than size
                while (index>=currentList->size){			//while index is greater than or equal to size
                        index-=currentList->size;			//reduce index by the amount of size
                }
        }
        if (index < 0 ){						//if index is negative
                while (index<0){					//while index is negative	
                        index+=currentList->size;			//increase index by amount of size
                }
        }
	if (index==0){							//if index==0
		return getValue(currentList->head);			//return value of Head
	}
    	Node currentNode = currentList->head;				//store Head as currentNode
    	int i;								//counter variable
    	for(i = 0; i < index; ++i){					//loop to position of index
        	currentNode = getNext(currentNode); 			//move to next node
    	}
	return getValue(currentNode); 					//return the value of the current node
}
void printListFromEnd(List currentList){			//print list in reverse order
	printf("[");
	Node currentNode = getPrevious(currentList->head);	//store previous of head as currentNode
	int i;							//counter variable
	for(i=0;i<currentList->size;++i){			//loop through all indexes
		printf("%d",getValue(currentNode));		//print value of currentNode
                printf(" ");
                currentNode = getPrevious(currentNode);		//update currentNode to previous of currentNode
	}
	printf("] \n");
}
void printList(List currentList){				//print list in order
    printf("[");
    Node currentNode = currentList->head;			//store Head as currentNode
    int i;							//counter variable
	for(i=0;i<currentList->size;++i){			//loop through all indexes
        	printf("%d",getValue(currentNode));		//print value of currentNode
            	printf(" ");
        	currentNode = getNext(currentNode);		//update currentNode to Next of currentNode
    	}
    printf("] \n"); //wrap things up
}

void freeList(List currentList){
    //freeing may seem a little tricky, we will need
    //to pass over the list and free each item
    //before we can free the list
    	Node currentNode = getPrevious(currentList->head); //start at head
    	int i;
	for (i=0;i<currentList->size;++i)
    	{
        	Node previous = getPrevious(currentNode);//temporarily hold previous
        	freeNode(currentNode);//free current
        	currentNode = previous;//set current to the previous node
    	}
    	free(currentList);//finally, free the linked list
}

