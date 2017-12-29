#include<stdio.h>
#include<stdbool.h>
#include<limits.h>

int main (void)
{
   double age [500]={0};
   double count=0;
   bool done=0;
   int varCount=0;
   int maximum=INT_MIN;
   int minimum=INT_MAX;
   double total=0;
   double avg=0;
   printf("This program calculates the min, max, and avg of the values entered.\n");
   printf("To end, enter -1 at the prompt\n");
   printf("__________________________________________\n");
   do
   {
      count++;
      printf("Please enter the age of person number %.0f: ",count);
      scanf("%lf",&age[varCount]);
      if (age[varCount]==-1)
      {
         done=1;
      }
      varCount++;
   }while (done==0);
   varCount--;
   for (int i=0;i<varCount;i++)
   {
      if (age[i]>maximum)
      {
         maximum=age[i];
      }
   }
   for (int i=0;i<varCount;i++)
   {
      if (age[i]<minimum)
      {
         minimum=age[i];
      }
   }
   for (int i=0;i<=varCount;i++)
   {
      total=total+age[i];
   }
   count--;
   avg=total/(count);
   printf("__________________________________________\n");
   printf("You entered %.0f values\n",count);
   printf("The  smallest entered age is: %i\n",minimum);
   printf("The largest entered age is: %i\n",maximum);
   printf("The average value from all values entered is: %.2f",avg);
	return 0;
}