#ifndef NODE_H
#define NODE_H

// Written by William Tennis :)

	//create a handle for the dictionary
typedef struct dict* Dict;
	
	//Create new Dictionary
	//@param initial_size = the # of entries the Dictionary
	//@return a newly created Dictionary
Dict createDictionary(int initial_size);

	//Hashing function
	//sums ascii value of all characters in *key string
	//mods sum by size_of_array
	//@param *key = character array for entry(suit)
	//@param size_of_array = # of entries in dictionary
int hash(char *key,int size_of_array);

	//insertion function
	//creates a pair for key and value in KeyValuePair
	//calls hash function to get insertion index
	//if collision occurs it will perform linear probe
	//until an open slot is found
	//may require looping to beginning of array
	//@param Dictionary struct of all entries
	//@param *key = character array for entry (suit)
	//@param value = value associated with entry
void insert(Dict dict,char *key,int value);

	//get entry function
	//calls hash function to get index of *key character array of entry
	//if *key at index does not match
	//linear probe until match is found
	//@param Dictionary struct of all entries
	//@param *key = character array for entry (suit)
	//@return value at index of match
int get(Dict dict,char *key);

	//free memory allocated for the dictionary struct
	//@param Dictionary struct of all entries

	//returns the position of a suit relative to other suits
int getPosition(Dict dict,char *key);

	//print the dictionary for testing purposes
void printDict(Dict dict);

	//free memory allocated for the dictionary struct
	//@param Dictionary struct of all entries
void freeDictionary(Dict dict);


#endif
