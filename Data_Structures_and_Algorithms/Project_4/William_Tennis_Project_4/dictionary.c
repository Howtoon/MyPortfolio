#include "dictionary.h"
#include "scanner.h"
#include <string.h>

// Written by William Tennis

typedef struct KVP{
        int value;
        char *key;
}KVP;

struct dict{			//Declare dictionary struct
        int numOfSuits;			//Number of Unique Suits
        KVP *kvp;			//Array of key value pairs/HashTable
};

Dict createDictionary(int initial_size){
	int i;
	Dict newDict = malloc(sizeof newDict);					//Declare and allocate Dictionary
        newDict->numOfSuits = initial_size;					//Assign size of dictionary
	newDict->kvp =malloc(sizeof (struct KVP)*initial_size);			//Allocate size of HashTable Array
	for (i=0;i<newDict->numOfSuits;++i){
		newDict->kvp[i].key='\0';
	}
	return newDict;						//Return created dictionary
}

int hash(char *key,int size_of_array){		//params suit,#ofsuits
	int sum=0;					//sum of ascii chars
        int hasNext=1;					//boolean loop variable
	int hashIndex;					//var to hold sum%size
	int i=0;					//counter for array index
	do{					//start while loop
		if (key[i]=='\0'){			//check for end of char array
			hashIndex=(sum)%size_of_array;			//store hashIndex result
			return hashIndex;		//return hasIndex
		}				//end if
		sum=sum+(int)(key[i]);			//adds ascii value to sum
		++i;				//increment counter
 	} while(hasNext);		//check loop boolean (will never be false)
	return -1;		//error exit
}

void insert(Dict dict,char *key,int value){	//params Dictionary,suit,valueOfSuit
	int hashIndex=hash(key,dict->numOfSuits);	//get hashIndex for insert
        	int notEmpty=1;				//boolean check
        	while (notEmpty){				//start while loop
        	        if (dict->kvp[hashIndex].key=='\0'){	//if array slot is empty
        	                dict->kvp[hashIndex].key=key;		//store suit
               		        dict->kvp[hashIndex].value=value;	//store suit order
                        	notEmpty=0;			//set loop boolean to false
                	}				//end if
                	++hashIndex;				//increment index counter
                	if (hashIndex==dict->numOfSuits)	//check if index counter is out of bounds
                        	hashIndex=0;		//reset index counter
        	}				//end loop
	return;						//return void
}
void printDict(Dict dict){
	int i;
//	printf("Number of Suits: %d\n",dict->numOfSuits);
	for (i=0;i<dict->numOfSuits;++i){
  //      	printf("%s    \t%d at Index: %d\n",dict->kvp[i].key,dict->kvp[i].value,i);
    	}	
	return;
}

int get(Dict dict,char *key){	//params Dictionary,suit
	int i;					//counter
	for (i=hash(key,dict->numOfSuits);i<dict->numOfSuits+1;++i){	//loop through all suits
                if (i==dict->numOfSuits){			//reset index if reached end of array
                        i=0;
                }
		if (strcmp(dict->kvp[i].key,key)==0){		//compare key to suit
			//printf("Position of %s is %d",key,i);
                        return dict->kvp[i].value;		//return suit Position
		}
        }			//end loop
	//printf("Error Getting Index");		//error
        return -1;			//error
}

void freeDict(Dict dict){		//function to free all memory allocated to dictionary
	free(dict->kvp);
	free(dict);
	return;
}
