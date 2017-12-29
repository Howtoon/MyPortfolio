#include <stdio.h>
#include <stdlib.h>

#include "scanner.h"

//example of using the functions in scanner
int main(int argc, char **argv)
{
    char *string;
    int value;
    FILE *fp = fopen(argv[1], "r");

    string = readString(fp); //perform first reads
    value = readInt(fp);
    while(!feof(fp)){
        /*Do what you want with read in values here*/
        printf("%s %d\n",string, value);
        
	free(string); //dynamically allocated memory must be freed
        string = readString(fp);
        value = readInt(fp);
    }
    fclose(fp); //do not forget to close the file when finished with it
    return 0;
}
