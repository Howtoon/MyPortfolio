#include <stdio.h>
#include <stdbool.h>



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

int main (void)
{

int totalCars, totalRentals, sizeC, sizeR, run, input, Id, index;
run=1;
totalRentals=0;
sizeC=0;
sizeR=0;
input=0;
totalCars=0;
Id=0;
index=-1;
char Name[20];
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

do{
   printf("Menu\n");
   printf("----\n");
   printf("1: Add new car to the inventory\n");
   printf("2: Make a reservation\n");
   printf("3: Find a reservation using renter name and print it to the screen\n");
   //printf("4: Find reservation by renter name\n");
   //printf("5: Find car by carId");
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
         totalRentals=addNewRental ( *Cars,totalCars, *Rentals, totalRentals, sizeR );
      }
      /*//Find carId using Make
      case (3):
      {
      printf("Enter the car make to search for: ");
      scanf(" %s",carMake);
      for (int i=0;i<20;i++)
      {
         Make[i]=&carMake[i];
      }
      for (int i=0;i<20;i++)
      {
         Cars[i]=&allCars[i];
      }
      Id=0;
      Id=findCarIdByName(*Cars,totalCars,*Make);
      printf(" %i",Id);
      }*/
      
      //Find reservation using renter name and print it to the screen 
      case (3):
      {
      printf("Enter the renter's name: ");
      scanf(" %s",Name);
      index=findReservation ( *Rentals, totalRentals, Name );
      printf(" %s %i %i",allRentals[index].renterName,allRentals[index].daysRenting,allRentals[index].carId);
      }
      
      /*//Find car by carID
      case (5):
      {
      
      }*/
      
      //Print all rental information
      case (4):
      {
      
      }
      //   
      case (5):
      {
      
      }
      case (6):
      {
      
      }
      case (7):
      {
         run=0;
      }
   }
         
}while (run==1);
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
printf("\n%i %s %s %i %.2lf\n",allCars[0].carId,allCars[0].make,allCars[0].model,allCars[0].numDoors,allCars[0].rate);
printf("\n%i %s %s %i %.2lf\n",allCars[1].carId,allCars[1].make,allCars[1].model,allCars[1].numDoors,allCars[1].rate);
printf("\n%i %s %s %i %.2lf\n",allCars[2].carId,allCars[2].make,allCars[2].model,allCars[2].numDoors,allCars[2].rate);
return 3;
}
//Option #1 "Add new car to inventory"
int addNewCar ( struct CarT *allCars, int totalCars, int size)
{
if (size==19)
   return totalCars;
else
{
   size++;
   printf("Enter the CarId: ");
   scanf(" %i",&allCars[size].carId);
   printf("Enter the make: ");
   scanf(" %s",allCars[size].make);
   printf("Enter the model: ");
   scanf(" %s",allCars[size].model);
   printf("Enter the number of doors: ");
   scanf(" %i",&allCars[size].numDoors);
   printf("Enter the rental rate: ");
   scanf(" %lf",&allCars[size].rate);
   printf("\n%i %s %s %i %.2lf\n",allCars[size].carId,allCars[size].make,allCars[size].model,allCars[size].numDoors,allCars[size].rate);
   totalCars++;
}
return totalCars;
}
//Option #2 "Make a new reservation"
      /*
      printf("Enter the car make to search for: ");
      scanf(" %s",carMake);
      for (int i=0;i<20;i++)
      {
         Make[i]=&carMake[i];
      }
      for (int i=0;i<20;i++)
      {
         Cars[i]=&allCars[i];
      }
      Id=0;
      Id=findCarIdByName(*Cars,totalCars,*Make);
      printf(" %i",Id);
      */
int addNewRental ( struct CarT *allCars, int totalCars, struct RentalT *allRentals, int totalRentals, int size )
{
int Id=-1;
char carMake[20];

if (size==59)
{
   return 60;
}
else
{
   while (Id==-1)
   {
      printf("Enter the renter's name: ");
      scanf(" %s",allRentals[size].renterName);
      printf("Enter the number of days renting: ");
      scanf(" %i",&allRentals[size].daysRenting);
      printf("Enter the make of the car: ");
      scanf(" %s",carMake);
      Id=findCarIdByName(allCars,totalCars,carMake);
   }
   printf("%s %i %i",allRentals[size].renterName, allRentals[size].daysRenting, allRentals[size].carId); 
   }
   return (totalRentals+1);
}  
//Called by Option #2 "Make a new reservation"
int findCarIdByName ( struct CarT *allCars, int totalCars, char *carMake )
{
for (int i=0;i<(totalCars-1);i++)
{
if (equalStrings(allCars[i].make,carMake)==true)
   return allCars[i].carId;
else
   return -1;
}
return 0;
}

int findReservation ( struct RentalT *allRentals, int totalRentals, char *renterName )
{
bool areEqual=0;

for (int i=0;i<(totalRentals-1);i++)
{
if (equalStrings(allRentals[i].renterName,renterName)==true)
return i;
}

return -1;
}

int findCarById ( struct CarT *allCars, int totalCars, int carId )
{
for (int i=0;i<(totalCars-1);i++)
{
   if (equalInt(allCars[i].carId,carId)==true)
      return i;
}
return -1;
}

void printAllRentals ( struct RentalT *allRentals, int totalRentals, struct CarT *allCars, int totalCars )
{
return;
}

void printCarInfo ( struct CarT *allCars, int totalCars, int CarId )
{
return;
}

double getAverageRentalDays ( struct RentalT *allRentals, int totalRentals )
{
return 0;
}

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

bool equalInt ( int i1,  int i2)
{
bool areEqual;
if (i1==i2)
   areEqual=true;
else
   areEqual=false;
return areEqual;
}