#include<stdio.h>
#include<math.h>


int main (void)
{
   int radius;
   printf("Input the radius of a circle: ");
   scanf("%i",&radius);
   float area=radius*radius*M_PI;
   float circumference=2*M_PI*radius;
   printf("The Area of a circle with a radius of %i is %f units squared\n",radius,area);
   printf("The Circumference of a circle with a radius of %i is %f units",radius,circumference);
   
   return 0;
   
}