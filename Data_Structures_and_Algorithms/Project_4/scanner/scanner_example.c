#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

//example of using the functions in scanner
int main(int argc, char **argv)
{
    int numOfSuits;
    int numOfCards;
    int value;
    int i;
    FILE *fp = fopen(argv[1], "r");
    char *suit;
    
    numOfSuits = readInt(fp); //perform first reads
    numOfCards = readInt(fp);
    printf("number of suits:%d\n",numOfSuits);
    printf("number of cards:%d\n",numOfCards);
    printf("These are all the Suits in the deck\n");
    printf("-----------------------------------\n");
    for (i=numOfSuits;i>0;--i){
    	printf(readString(fp));
	printf("\n");
    }
    printf("These are all the cards in the Deck\n");
    printf("-----------------------------------\n");
    for (i=numOfCards;i>0;--i){   
	//free(string); //dynamically allocated memory must be freed
        suit = readString(fp);
        value = readInt(fp);
        printf("%s     \t%d\n",suit,value);
    }
    fclose(fp); //do not forget to close the file when finished with it
    return 0;
}
