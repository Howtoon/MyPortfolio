#include<stdio.h>
#include<math.h>

int main (void)
{
   double deposit=0.0;
   double rate=0;
   double interest=0;
   double percent=0;
   int years=0;
   int totalMonths=0;
   double balance=0;
   printf("Please enter the amount of your savings account deposit: ");
   scanf(" %lf",&deposit);
   printf("You  entered a deposit of $%.2f\n",deposit);
   printf("Please enter the interest rate as a percentage %%: ");
   scanf(" %lf",&percent);
   rate=percent/100;
   printf("You entered an interest rate of %.2f%%\n",percent);
   printf("It will be calculated as %.4f\n",rate);
   printf("Please enter the number of years for this deposit: ");
   scanf(" %i",&years);
   balance=deposit;
   totalMonths=years*12;
   interest=rate/12;
   balance=deposit* (pow( 1+interest, totalMonths));
   printf("After %i number of years, the deposit in the savings account is now $%.2f", years, balance);
	return 0;
}