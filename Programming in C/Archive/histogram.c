#include <stdio.h>

/**
 * Prints a histogram to the screen using horizontal bar chart.
 * Parameters:
 *   list - a list of integers
 *   n - the number of values in the list
 */
void printHistogram ( int *hist, int n );

/**
 * This program requests data from the user and then
 * computes and prints a histogram. You may assume that
 * the data values entered are in the range of 0 to 9.
 */
int main ( void )
{
	int i, n;

	// Data entry
	//
	printf ("How many values in your data set? ");
	scanf ("%d", &n);

	int list[n];
	for (i=0; i < n; i++)
   {
		printf ("Enter a value: ");
		scanf ("%d", &list[i]);
	}

	// Processing data to compute histogram
	//
	int hist[10];    


	// Printing histogram
	printHistogram ( hist, n);

	return 0;
}

void printHistogram ( int *list, int n )
{
    int i, j;
    int value[10];
    for (i=0;i<10;i++)
    {
      value[i]=0;
    }
    for (i=0; i<10;i++)
    {
      for (j=0; j<n;j++)
      {   
         if (i==*(list+j))
         {
            value[i]+=1;
         }
      }   
    }
    for (i=0; i <10; i++)
    {
      printf ("[%i] ", i);
		for (j = 0; j < value[i]; j++)
		{	
         printf ("*");
    	}
      printf ("\n");
    }
}