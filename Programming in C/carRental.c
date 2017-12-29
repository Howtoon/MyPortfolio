#include <stdio.h>
#include <stdbool.h>
#include <string.h>

struct CarT//Inventory Info
{
   int carId;
   char make[20];
   char model[20];
   int numDoors;
   double rate;
};

struct RentalT//Customer Info
{
   char renterName[20];
   int daysRenting;
   int carId;
};

int createInventory ( struct CarT *allCars );
int addNewCar ( struct CarT *allCars, int totalCars, int size);
int addNewRental ( struct CarT *allCars, int totalCars, struct RentalT *allRentals, int totalRentals, int size );
int findCarIdByName ( struct CarT *allCars, int totalCars, char *carMake );
int findReservation ( struct RentalT *allRentals, int totalRentals, char *renterName );
int findCarById ( struct CarT *allCars, int totalCars, int carId );
void printAllRentals ( struct RentalT *allRentals, int totalRentals, struct CarT *allCars, int totalCars );
void printCarInfo ( struct CarT *allCars, int totalCars, int CarId );
double getAverageRentalDays ( struct RentalT *allRentals, int totalRentals );
bool equalStrings (const char s1[], const char s2[]);
bool equalInt ( int i1,  int i2);
//void  readLine (char  buffer[]);

int main (void)
{

int totalCars, totalRentals, sizeC, sizeR, run, input, Id, index, CarId, k;
//char character;
double avg=0  ;
totalRentals=0;
sizeC=0;
sizeR=0;
input=0;
totalCars=0;
Id=0;
index=-1;
char Name[20], Make[20];
struct CarT allCars[20], *Cars[20];
struct RentalT allRentals[60], *Rentals[60];

for (int i=0;i<20;i++)
{
   Cars[i]=&allCars[i];
}

for (int i=0;i<60;i++)
{
   Rentals[i]=&allRentals[i];
}
totalCars=createInventory(*Cars);
sizeC=totalCars-1;

do
{
   //Updates pointers and variables
   for (int i=0;i<20;i++)
   {
      Cars[i]=&allCars[i];
   }
   
   for (int i=0;i<60;i++)
   {
      Rentals[i]=&allRentals[i];
   }
   sizeC=totalCars-1;
   sizeR=totalRentals-1;
   for (int i=0;i<totalCars;i++)
   {
      printf("\n+-------INVENTORY----------------------------------------------------------------------------------------");
      printf("\n| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf",allCars[i].carId,allCars[i].make,allCars[i].model,allCars[i].numDoors,allCars[i].rate);
   }
      if (totalRentals!=0)
         printf("\n+--------------------------------------------------------------------------------------------------------\n");

   for (int i=0;i<totalRentals;i++)
   {
      printf("\n+-------RESERVATIONS-------------------------------------------------------------------------------------");
      printf("\n| Renter Name: %s\t Days Renting: %i",allRentals[i].renterName,allRentals[i].daysRenting);
      index=findCarById ( *Cars, totalCars, allRentals[i].carId );
      printf("\n| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf",allCars[index].carId,allCars[index].make,allCars[index].model,allCars[index].numDoors,allCars[index].rate);
   }
   printf("\n+--------------------------------------------------------------------------------------------------------");
   
   //Menu Display and Input.
   printf("\n\nMenu\n");
   printf("----\n"); 
   printf("1: Add new car to the inventory\n");
   printf("2: Make a reservation\n");
   printf("3: Find a reservation using renter name and print it to the screen\n");
   printf("4: Print all rental information to the screen\n");
   printf("5: Print car information to the screen of a selected car using the make of the car to search the inventory\n");
   printf("6: Calculate and print average number of days rented\n");
   printf("7: Exit program\n");
   scanf(" %i",&input);

   switch (input)
   {
      //Add a new car to the inventory
      case (1):
      {
         for (int i=0;i<20;i++)
         {
            Cars[i]=&allCars[i];
         }
         totalCars=addNewCar (*Cars, totalCars, sizeC);
         if (totalCars<20)
         {   
            sizeC=totalCars-1;
         }
         else
         {   
            printf("Inventory full");
            totalCars=20;
            sizeC=totalCars-1;
         } 
         break;  
      }
      
      //Make a new reservation
      case (2):
      {
         for (int i=0;i<20;i++)
         {
            Cars[i]=&allCars[i];
         }
         for (int i=0;i<60;i++)
         {
            Rentals[i]=&allRentals[i];
         }
         sizeR=totalRentals-1;         
         totalRentals=addNewRental ( *Cars, totalCars, *Rentals, totalRentals, totalRentals );
         sizeR=totalRentals-1;
         break;
      }

      //Find reservation using renter name and print it to the screen 
      case (3):
      {
      printf("Enter the renter's name without spaces: ");
      //gets( Name);
      scanf(" %s",Name);
      
      /*
      k=0;
      do
      {
          character = getchar ();
          Name[k] = character;
          ++k;
      }
      while ( character != '\n' );
  
      Name[k - 1] = '\0';
      
      //readLine(Name);*/
      
      index=findReservation ( *Rentals, totalRentals, Name );
      if (index==-1)
         printf("The reservation that you have requested does not exist.\n");
      else
         {
         printf("\n+-----------------------------------------------------------------------------------------------\n");
         printf("| Renter Name: %s\t Days Renting: %i\n",allRentals[index].renterName,allRentals[index].daysRenting);
         index=findCarById ( *Cars, totalCars, allRentals[index].carId );
         printf("| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf\n",allCars[index].carId,allCars[index].make,allCars[index].model,allCars[index].numDoors,allCars[index].rate);
         printf("+-----------------------------------------------------------------------------------------------\n");
         }
      break;
      }
      
      //Print all rental information
      case (4):
      {
      printAllRentals ( *Rentals, totalRentals, *Cars, totalCars );
      break;
      }
      //Prints car information that matches the CarId.
      case (5):
      {
      printf("Enter the make of the car you would like to find without spaces: ");
      scanf(" %s",Make);
      CarId=findCarIdByName( *Cars, totalCars, Make);
      printCarInfo ( *Cars, totalCars, CarId );
      break;
      }
      //Gets average days rented for all reservations.
      case (6):
      {
      avg=getAverageRentalDays ( *Rentals, totalRentals );
      printf("The average days renting is: %.2lf",avg);
      break;
      }
      case (7):
      {
         run=-1;
         break;
      }
   }
   run++;   
}while (run>0);
return 0;
}

// createInventory() initializes the original inventory of cars in the first three slots of allCars[]
int createInventory ( struct CarT *allCars)
{
allCars[0].carId=1234;
allCars[0].make[0]='V';
allCars[0].make[1]='W';
allCars[0].make[2]='\0';
allCars[0].model[0]='G';
allCars[0].model[1]='o';
allCars[0].model[2]='l';
allCars[0].model[3]='f';
allCars[0].model[4]='\0';
allCars[0].numDoors=2;
allCars[0].rate=66.00;
allCars[1].carId=2241;
allCars[1].make[0]='F';
allCars[1].make[1]='o';
allCars[1].make[2]='r';
allCars[1].make[3]='d';
allCars[1].make[4]='\0';
allCars[1].model[0]='F';
allCars[1].model[1]='o';
allCars[1].model[2]='c';
allCars[1].model[3]='u';
allCars[1].model[4]='s';
allCars[1].model[5]='\0';
allCars[1].numDoors=4;
allCars[1].rate=45.00;
allCars[2].carId=3445;
allCars[2].make[0]='B';
allCars[2].make[1]='M';
allCars[2].make[2]='W';
allCars[2].make[3]='\0';
allCars[2].model[0]='X';
allCars[2].model[1]='3';
allCars[2].model[3]='\0';
allCars[2].numDoors=4;
allCars[2].rate=128.00;
printf("+--------------------------------------------------------------------------------------------------------");
printf("\n| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf\n",allCars[0].carId,allCars[0].make,allCars[0].model,allCars[0].numDoors,allCars[0].rate);
printf("+--------------------------------------------------------------------------------------------------------");
printf("\n| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf\n",allCars[1].carId,allCars[1].make,allCars[1].model,allCars[1].numDoors,allCars[1].rate);
printf("+--------------------------------------------------------------------------------------------------------");
printf("\n| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf\n",allCars[2].carId,allCars[2].make,allCars[2].model,allCars[2].numDoors,allCars[2].rate);
printf("+--------------------------------------------------------------------------------------------------------");
printf("\nThese cars have been added to your inventory.\n\n");
return 3;
}

//Option #1 "Add new car to inventory." Returns the number of cars in the inventory.

int addNewCar ( struct CarT *allCars, int totalCars, int size)
{
if (size==19)
   return totalCars;
else
{
   size++;
   printf("Enter the CarId #: ");
   scanf(" %i",&allCars[size].carId);
   printf("Enter the make without spaces: ");
   scanf(" %s",allCars[size].make);
   printf("Enter the model without spaces: ");
   scanf(" %s",allCars[size].model);
   printf("Enter the number of doors: ");
   scanf(" %i",&allCars[size].numDoors);
   printf("Enter the rental rate in $: ");
   scanf(" %lf",&allCars[size].rate);
   printf("+-----------------------------------------------------------------------------------------------");
   printf("\n| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf\n",allCars[size].carId,allCars[size].make,allCars[size].model,allCars[size].numDoors,allCars[size].rate);
   printf("+-----------------------------------------------------------------------------------------------\n");
   totalCars++;
}
return totalCars;
}

//Option #2 "Make a new reservation." Returns the number of total rentals.

int addNewRental ( struct CarT *allCars, int totalCars, struct RentalT *allRentals, int totalRentals, int size )
{
   int Id=-1,k;
   int index;
   char carMake[20], *Make[20], character;
   struct CarT *Cars[20];
   if (size==59)
   {
      return 60;
   }
   else
   {
      for (int run=1;run>0;run++)
      {
            printf("Enter the renter's name without spaces: ");
            scanf(" %s",allRentals[size].renterName);
           
            /*
            k=0;
            if (allRentals[size].renterName[0]=='\0')
            {
            do
            {
                character = getchar ();
                allRentals[size].renterName[k] = character;
                ++k;
            }
            while ( character != '\n' );
     
            allRentals[size].renterName[k - 1] = '\0';
            }*/
            
            
            printf("Enter the number of days renting: ");
            scanf(" %i",&allRentals[size].daysRenting);
            printf("Enter the make of the car without spaces: ");
            scanf(" %s",carMake);
            for (int i=0;i<20;i++)
            {
               Make[i]=&carMake[i];
            }
            for (int i=0;i<20;i++)
            {
               Cars[i]=&allCars[i];
            }
            Id=findCarIdByName( allCars, totalCars, carMake);
            if (Id<0)
            {
               printf("The make you have entered does not exist. Try again\n");
            }
            else
            {
               printf("+--------------------------------------------------------------------------------------------------------");
               printf("\n| Renter Name: %s\t Days Renting:%i\n",allRentals[size].renterName, allRentals[size].daysRenting);
               index=findCarById ( allCars, totalCars, Id );
               printf("| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf\n",allCars[index].carId,allCars[index].make,allCars[index].model,allCars[index].numDoors,allCars[index].rate);
               printf("+--------------------------------------------------------------------------------------------------------\n");
               allRentals[size].carId=Id;
               run=-2;
               return (totalRentals+1);
            }  
      }
   }
return totalRentals;
}
//Called by Option #2 "Make a new reservation." Returns the CarId that matches the reservation CarId entered.
int findCarIdByName ( struct CarT *allCars, int totalCars, char *carMake )
{
   for (int i=0;i<(totalCars);i++)
   {
      if (equalStrings( allCars[i].make, carMake)==true)
         return allCars[i].carId;
   }
return -1;
}
//Option #3 "Find reservation by Renter Name." Returns the array index as an integer.
int findReservation ( struct RentalT *allRentals, int totalRentals, char *renterName )
{
bool areEqual=0;
   
   for (int i=0;i<(totalRentals);i++)
   {
      if (equalStrings(allRentals[i].renterName,renterName)==true)
         return i;
   }

return -1;
}

//Called by Option #4, and 5. Finds car inventory information by CarId. Returns the array index as an integer.
int findCarById ( struct CarT *allCars, int totalCars, int carId )
{
for (int i=0;i<(totalCars);i++)
{
   if (equalInt(allCars[i].carId,carId)==true)
      return i; 
}
return -1;
}

//Option #4 Prints all rental information. No return value.
void printAllRentals ( struct RentalT *allRentals, int totalRentals, struct CarT *allCars, int totalCars )
{
int index;
printf("+-----------------------------------------------------------------------------------------------\n");
for (int i=0;i<(totalRentals);i++)
{
   index=findCarById ( allCars, totalCars, allRentals[i].carId );
   printf("| Renter Name: %s\t Days Renting: %i\n",allRentals[i].renterName, allRentals[i].daysRenting);
   printf("| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf\n",allCars[index].carId,allCars[index].make,allCars[index].model,allCars[index].numDoors,allCars[index].rate);
   printf("+-----------------------------------------------------------------------------------------------\n");
}
return;
}

//Option #5 Prints the car information for the car the matches the CarId.
void printCarInfo ( struct CarT *allCars, int totalCars, int CarId )
{
int index=findCarById ( allCars, totalCars, CarId );
printf("\n+-----------------------------------------------------------------------------------------------\n");
printf("| CarId: %i\t Make: %s\t Model: %s\t # Doors: %i\t Rental Rate: $%.2lf\n",allCars[index].carId,allCars[index].make,allCars[index].model,allCars[index].numDoors,allCars[index].rate);
printf("+-----------------------------------------------------------------------------------------------\n");
return;
}

//Option #6 Computes average days rented for all reservations. Returns the product as a double.
double getAverageRentalDays ( struct RentalT *allRentals, int totalRentals )
{
double totalDays=0;
   for (int i=0;i<totalRentals;i++)
   {
      totalDays=(totalDays+allRentals[i].daysRenting);  
   }
return (totalDays/totalRentals);
}

//Compares strings for equality & returns T/F.
bool equalStrings (const char s1[], const char s2[])
{
int i=0;
bool areEqual;

while( s1[i]==s2[i] && s1[i]!='\0' && s2[i]!='\0' )
   i++;
if (s1[i]=='\0'&&s2[i]=='\0')
   areEqual=true;
else
   areEqual=false;
return areEqual;
}

//Compares integers for equality & returns T/F.
bool equalInt ( int i1,  int i2)
{
bool areEqual;
if (i1==i2)
   areEqual=true;
else
   areEqual=false;
return areEqual;
}

/*//Read Line Input "Called to read strings from the keyboard."
void  readLine (char  buffer[])
{
    char  character;
    int   i = 0;

    do
    {
        character = getchar ();
        buffer[i] = character;
        ++i;
    }
    while ( character != '\n' );

    buffer[i - 1] = '\0';
}*/





