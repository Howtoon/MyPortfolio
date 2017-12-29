#include <stdlib.h>
#include "node.h"

struct node {
    int value;			//VALUE OF CURRENT NODE
    Node next;			//NEXT NODE POINTER
    Node previous;		//PREVIOUS NODE POINTER
};

Node createNode(int value, Node next, Node previous){
    Node newNode = malloc(sizeof *newNode);
    newNode->value = value;
    newNode->previous = previous;			//PREVIOUS NODE POINTER
    newNode->next = next;
  
    return newNode;
}

int getValue(Node current){				//GET VALUE OF CURRENT NODE
    return current->value;
}

Node getNext(Node current){				//GoTo NEXT NODE 
    return current->next;
}

Node getPrevious(Node current){				//GOTO PREVIOUS NODE
    return current->previous;
}

void setValue(Node current, int value){			//SET VALUE OF CURRENT NODE
    current->value = value;
} 

void setNext(Node current, Node next){			//SET NEXT NODE POINTER
    current->next = next;
}

void setNode(Node current, Node previous){		//SET PREVIOUS NODE POINTER
    current->previous = previous;
}

void freeNode(Node current){				//FREE MEMORY OF CURRENT NODE
    free(current);
}
