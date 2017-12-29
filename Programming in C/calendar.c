#include<stdio.h>

int main(void)
{
   int numberOfDays=0;
   int startDay=0;
   int arrayOfDays [7][6]={0};
   int x=0;
   int y=0;
   printf("This program will produce a calendar month based on your input.\n");
   printf("First, on which day does the month begin?\n");
   printf("Please input the number which corresponds with the first day of the month.\n");
   printf("Sunday=0\nMonday=1\nTuesday=2\nWednesday=3\nThursday=4\nFriday=5\nSaturday=6\nFirst day: ");
   scanf(" %i",&startDay);
   switch (startDay)
   {
      case 0:{
         printf("You have chosen Sunday\n");
         break;}
      case 1:{
         printf("You have chosen Monday\n");
         break;}
      case 2:{
         printf("You have chosen Tuesday\n");
         break;}
      case 3:{
         printf("You have chosen Wednesday\n");
         break;}
      case 4:{
         printf("You have chosen Thursday\n");
         break;}
      case 5:{
         printf("You have chosen Friday\n");
         break;}
      case 6:{
         printf("You have chosen Saturday\n");
         break;}
   }
   printf("Now, please enter the number of days in the month: ");
   scanf(" %i",&numberOfDays);
   printf("You entered %i days",numberOfDays);
   switch (startDay)
   {
      //FIRST DAY IS SUNDAY
      case 0:{
         x=0;
         printf("\n+----------------------------------+\n");
         printf("|SUN |MON |TUE |WED |THU |FRI |SAT |\n");
         printf("+----------------------------------+\n");
         for (int i=1;i<=numberOfDays;i++)
         {
            arrayOfDays[x][y]=i;
            if ((i==1)||(x==0))
            {
            printf("|");
            }
            printf("%2i",arrayOfDays[x][y]);
            x++;
            
            
            if (arrayOfDays[x][y]>=10)
            {
               printf("|");
            }
            if (arrayOfDays[x][y]<=10)
            {
               printf("  |");
            }
            
            if (x>=7)
            {
               y++;
               x=0;
               printf("\n+----------------------------------+\n");
            }
         }
         if (x!=0)
         {
         printf("\n+----------------------------------+\n");
         }
         switch (x)
         {
            case 0:{
            printf("The last day of the month is Saturday");
            break;}
            case 1:{
            printf("The last day of the month is Sunday");
            break;}
            case 2:{
            printf("The last day of the month is Monday");
            break;}
            case 3:{
            printf("The last day of the month is Tuesday");
            break;}
            case 4:{
            printf("The last day of the month is Wednesday");
            break;}
            case 5:{
            printf("The last day of the month is Thursday");
            break;}
            case 6:{
            printf("The last day of the month is Friday");
            break;}
         }
         return 0;
         break;}
      //FIRST DAY IS MONDAY
      case 1:{
         x=1;
         printf("\n+----------------------------------+\n");
         printf("|SUN |MON |TUE |WED |THU |FRI |SAT |\n");
         printf("+----------------------------------+\n");
         printf("|    ");
         for (int i=1;i<=numberOfDays;i++)
         {
            arrayOfDays[x][y]=i;
            if ((i==1)||(x==0))
            {
            printf("|");
            }
            printf("%2i",arrayOfDays[x][y]);
            x++;
            
            
            if (arrayOfDays[x][y]>=10)
            {
               printf("|");
            }
            if (arrayOfDays[x][y]<=10)
            {
               printf("  |");
            }
            
            if (x>=7)
            {
               y++;
               x=0;
               printf("\n+----------------------------------+\n");
            }

         }
         if (x!=0)
         {
         printf("\n+----------------------------------+\n");
         }
         switch (x)
         {
            case 0:{
            printf("The last day of the month is Saturday");
            break;}
            case 1:{
            printf("The last day of the month is Sunday");
            break;}
            case 2:{
            printf("The last day of the month is Monday");
            break;}
            case 3:{
            printf("The last day of the month is Tuesday");
            break;}
            case 4:{
            printf("The last day of the month is Wednesday");
            break;}
            case 5:{
            printf("The last day of the month is Thursday");
            break;}
            case 6:{
            printf("The last day of the month is Friday");
            break;}
         }
         return 0;
         break;}
      //FIRST DAY IS TUESDAY
      case 2:{
         x=2;
         printf("\n+----------------------------------+\n");
         printf("|SUN |MON |TUE |WED |THU |FRI |SAT |\n");
         printf("+----------------------------------+\n");
         printf("|    |    ");
         for (int i=1;i<=numberOfDays;i++)
         {
            arrayOfDays[x][y]=i;
            if ((i==1)||(x==0))
            {
            printf("|");
            }
            printf("%2i",arrayOfDays[x][y]);
            x++;
            
            
            if (arrayOfDays[x][y]>=10)
            {
               printf("|");
            }
            if (arrayOfDays[x][y]<=10)
            {
               printf("  |");
            }
            
            if (x>=7)
            {
               y++;
               x=0;
               printf("\n+----------------------------------+\n");
            }

         }
         if (x!=0)
         {
         printf("\n+----------------------------------+\n");
         }
         switch (x)
         {
            case 0:{
            printf("The last day of the month is Saturday");
            break;}
            case 1:{
            printf("The last day of the month is Sunday");
            break;}
            case 2:{
            printf("The last day of the month is Monday");
            break;}
            case 3:{
            printf("The last day of the month is Tuesday");
            break;}
            case 4:{
            printf("The last day of the month is Wednesday");
            break;}
            case 5:{
            printf("The last day of the month is Thursday");
            break;}
            case 6:{
            printf("The last day of the month is Friday");
            break;}
         }
         return 0;
         break;}
      //FIRST DAY IS WEDNESDAY
      case 3:{
         x=3;
         printf("\n+----------------------------------+\n");
         printf("|SUN |MON |TUE |WED |THU |FRI |SAT |\n");
         printf("+----------------------------------+\n");
         printf("|    |    |    ");
         for (int i=1;i<=numberOfDays;i++)
         {
            arrayOfDays[x][y]=i;
            if ((i==1)||(x==0))
            {
            printf("|");
            }
            printf("%2i",arrayOfDays[x][y]);
            x++;
            
            
            if (arrayOfDays[x][y]>=10)
            {
               printf("|");
            }
            if (arrayOfDays[x][y]<=10)
            {
               printf("  |");
            }
            
            if (x>=7)
            {
               y++;
               x=0;
               printf("\n+----------------------------------+\n");
            }

         }
         if (x!=0)
         {
         printf("\n+----------------------------------+\n");
         }
         switch (x)
         {
            case 0:{
            printf("The last day of the month is Saturday");
            break;}
            case 1:{
            printf("The last day of the month is Sunday");
            break;}
            case 2:{
            printf("The last day of the month is Monday");
            break;}
            case 3:{
            printf("The last day of the month is Tuesday");
            break;}
            case 4:{
            printf("The last day of the month is Wednesday");
            break;}
            case 5:{
            printf("The last day of the month is Thursday");
            break;}
            case 6:{
            printf("The last day of the month is Friday");
            break;}
         }
         return 0;
         break;}
      //FIRST DAY IS THURSDAY
      case 4:{
         x=4;
         printf("\n+----------------------------------+\n");
         printf("|SUN |MON |TUE |WED |THU |FRI |SAT |\n");
         printf("+----------------------------------+\n");
         printf("|    |    |    |    ");
         for (int i=1;i<=numberOfDays;i++)
         {
            arrayOfDays[x][y]=i;
            if ((i==1)||(x==0))
            {
            printf("|");
            }
            printf("%2i",arrayOfDays[x][y]);
            x++;
            
            
            if (arrayOfDays[x][y]>=10)
            {
               printf("|");
            }
            if (arrayOfDays[x][y]<=10)
            {
               printf("  |");
            }
            
            if (x>=7)
            {
               y++;
               x=0;
               printf("\n+----------------------------------+\n");
            }

         }
         if (x!=0)
         {
         printf("\n+----------------------------------+\n");
         }         
         switch (x)
         {
            case 0:{
            printf("The last day of the month is Saturday");
            break;}
            case 1:{
            printf("The last day of the month is Sunday");
            break;}
            case 2:{
            printf("The last day of the month is Monday");
            break;}
            case 3:{
            printf("The last day of the month is Tuesday");
            break;}
            case 4:{
            printf("The last day of the month is Wednesday");
            break;}
            case 5:{
            printf("The last day of the month is Thursday");
            break;}
            case 6:{
            printf("The last day of the month is Friday");
            break;}
         }
         return 0;
         break;}
      //FIRST DAY IS FRIDAY
      case 5:{
         x=5;
         printf("\n+----------------------------------+\n");
         printf("|SUN |MON |TUE |WED |THU |FRI |SAT |\n");
         printf("+----------------------------------+\n");
         printf("|    |    |    |    |    ");
         for (int i=1;i<=numberOfDays;i++)
         {
            arrayOfDays[x][y]=i;
            if ((i==1)||(x==0))
            {
            printf("|");
            }
            printf("%2i",arrayOfDays[x][y]);
            x++;
            
            
            if (arrayOfDays[x][y]>=10)
            {
               printf("|");
            }
            if (arrayOfDays[x][y]<=10)
            {
               printf("  |");
            }
            
            if (x>=7)
            {
               y++;
               x=0;
               printf("\n+----------------------------------+\n");
            }

         }
         if (x!=0)
         {
         printf("\n+----------------------------------+\n");
         }
         switch (x)
         {
            case 0:{
            printf("The last day of the month is Saturday");
            break;}
            case 1:{
            printf("The last day of the month is Sunday");
            break;}
            case 2:{
            printf("The last day of the month is Monday");
            break;}
            case 3:{
            printf("The last day of the month is Tuesday");
            break;}
            case 4:{
            printf("The last day of the month is Wednesday");
            break;}
            case 5:{
            printf("The last day of the month is Thursday");
            break;}
            case 6:{
            printf("The last day of the month is Friday");
            break;}
         }
         return 0;
         break;}
      //FIRST DAY IS SATURDAY
      case 6:{
         x=6;
         printf("\n+----------------------------------+\n");
         printf("|SUN |MON |TUE |WED |THU |FRI |SAT |\n");
         printf("+----------------------------------+\n");
         printf("|    |    |    |    |    |    ");
         for (int i=1;i<=numberOfDays;i++)
         {
            arrayOfDays[x][y]=i;
            if ((i==1)||(x==0))
            {
            printf("|");
            }
            printf("%2i",arrayOfDays[x][y]);
            x++;
            
            
            if (arrayOfDays[x][y]>=10)
            {
               printf("|");
            }
            if (arrayOfDays[x][y]<=10)
            {
               printf("  |");
            }
            
            if (x>=7)
            {
               y++;
               x=0;
               printf("\n+----------------------------------+\n");
            }

         }
         if (x!=0)
         {
         printf("\n+----------------------------------+\n");
         }
         switch (x)
         {
            case 0:{
            printf("The last day of the month is Saturday");
            break;}
            case 1:{
            printf("The last day of the month is Sunday");
            break;}
            case 2:{
            printf("The last day of the month is Monday");
            break;}
            case 3:{
            printf("The last day of the month is Tuesday");
            break;}
            case 4:{
            printf("The last day of the month is Wednesday");
            break;}
            case 5:{
            printf("The last day of the month is Thursday");
            break;}
            case 6:{
            printf("The last day of the month is Friday");
            break;}
         }
         return 0;
         break;}
   }
}