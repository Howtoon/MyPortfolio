#include <stdio.h>
#include <stdbool.h>
#include <string.h>
char input[50], search[50], *Text[50], *Pattern[50];

void contains ( int *ix);

int main (void)
{
//char input[50], search[50]; //Text[50], Pattern[50];
int index=-1;
printf("Please input a string of text: ");
scanf(" %s",input);
printf("Please input the pattern to search for: ");
scanf(" %s",search);
/*for (int i=0;i<50;i++)
   {
      Text[i]=&input[i];
      Pattern[i]=&search[i];
   }*/
contains(&index);
if (index==-1)
   {
   printf("The pattern does not exist");
   return 0;
   }
printf(" %i",index);
return 0;
}

void contains ( int *ix)
{
//int ix;
bool run=true;
int i=0, j=0, k=0;
while(i<50){
   if (input[i]!='\0')
   {
      if (input[i]==search[0])
      {   
         ix=&i;
         for(int j=0;k<(50-i);j++)
         {
            if (input[i]=='\0'&& search[j]=='\0')
               return;
            else if (input[i]!=search[j])
            {
                
            }
            else if (input[k]==search[j])
            {   
               k++;
            }
         
         }
      }
      i++;
   }
};
return;
   
   
   
   
   /*for (int j=50;j<28;j++)
      {
        
         if (text[j]==pattern[i])
         for (int k=j;k<(50-j);k++)
               
               
        
        output[i]=code->from[index];
      }*/



}