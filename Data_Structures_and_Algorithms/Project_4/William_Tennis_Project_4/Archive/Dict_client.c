#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"
#include "dictionary.h"

//Written by William Tennis :)

typedef struct Card{						//TypeDefinition Card
    int value;							//value relative to other suits
    char *suit;							//suit name
}Card;
typedef struct deck* Deck;					//TypeDefinition Deck of Cards

struct deck{							//define a deck of Cards
        int numOfCards;						//Number of cards in the deck
        Card *card;						//Array of cards
    };

void printDeck(Deck deck);					//print the deck of cards to screen

Deck sortByValue(Deck deck);					//Sort the deck by value

Deck sortBySuit(Dict dict,Deck deck);				//sort the deck by suit

int main(int argc, char **argv){		//MAIN
    Deck deck=malloc(sizeof deck);				//allocate size of deck of cards
    int i;							//counter
    FILE *fp = fopen(argv[1], "r");				//open file
    int numOfSuits = readInt(fp);					//Read Size of dictionary
    int numOfCards = readInt(fp);
    Dict dict=createDictionary(numOfSuits);		//Create dictionary Function  param numOfSuits
    for (i=0;i<numOfSuits;++i){					//Read the suits from the file
    	insert(dict,readString(fp),i+1);	//Insert into dictionary param dictionary,suit,
    }
    deck->numOfCards=numOfCards;
    deck->card=malloc(sizeof(Card)*numOfCards);		//allocate array of cards for numOfCards
    for (i=0;numOfCards>i;++i){				//for loop to read in and fill the deck
	deck->card[i].suit=readString(fp);			//read in suit of card
        deck->card[i].value=readInt(fp);			//read in card rank/value
    }								//end loop
    deck=sortByValue(deck);					//sort by value function
    deck=sortBySuit(dict,deck);					//sort by suit function
    printDeck(deck);						//print the sorted deck to the screen
    free(deck->card);						//free deck memory
    free(deck);							//free deck

    fclose(fp); //do not forget to close the file when finished with it
    
    return 0;
}

void printDeck(Deck deck){			//PRINTDECK
	int i;							//counter
	for (i=0;i<deck->numOfCards;++i){			//loop through the deck
		printf("%s     \t%d\n",deck->card[i].suit,deck->card[i].value); // 
	}							//end loop
	return;					//return
}

Deck sortByValue(Deck deck){		//Sort the deck by value of each card (Bubble Sort)
  	int i;			//outer counter
	int j;			//inner counter
	Card joker;		//temp card
	for (i=0;i<deck->numOfCards;++i){		//start of outer loop
    		for (j=0;j<deck->numOfCards-1;++j){	//start of inner loop
      			if (deck->card[j].value > deck->card[j+1].value){	//comparison
        			joker.suit=deck->card[j].suit;			//begin swaps
				joker.value=deck->card[j].value;

        			deck->card[j].suit=deck->card[j+1].suit;
        			deck->card[j].value=deck->card[j+1].value;

				deck->card[j+1].suit=joker.suit;
				deck->card[j+1].value=joker.value;		
			}
    		}
  	}
	return deck;			//return the deck
}

Deck sortBySuit(Dict dict,Deck deck){		//sort the deck by suit position
	int i;				//outer counter
	int j;				//inner counter
	Card joker;			//temp card
	for (i=0;i<deck->numOfCards;++i){			//outerloop start
                for (j=1;j<deck->numOfCards-1;++j){		//inner loop start
			if (get(dict,deck->card[j].suit)>get(dict,deck->card[j+1].suit)){//compare positions
				joker.suit=deck->card[j].suit;			//begin swaps	
                                joker.value=deck->card[j].value;

                                deck->card[j].suit=deck->card[j+1].suit;
                                deck->card[j].value=deck->card[j+1].value;

                                deck->card[j+1].suit=joker.suit;
                                deck->card[j+1].value=joker.value;
			}
		}
	}
	return deck;			//return the deck
}
