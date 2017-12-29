#include<stdio.h>

int main (void)
{
   float rawNumber;
   float output;
   printf("Please enter a numerical value with at least three decimal places: ");
   scanf("%f",&rawNumber);
   output=((int)(rawNumber * 100 + .5) / 100.0);
   printf("%.2f",output);
   
   return 0;
   
}