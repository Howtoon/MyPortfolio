#include <stdio.h>

int main(void)
{
   int list[10];
   int s;
   int n=10;
   printf("Please enter ten positive integers in ascending order by pressing enter after each integer.\n");
   for (int i=0;i<10;i++)
   {
      printf("index #%i:",i);
      scanf(" %i",&list[i]);
   }
   printf("This program will now return the index value of the integer you enter.\nPlease enter the value for which you would like to search:");
   scanf(" %i",&s);
   int searchLinear(int s, int *list, int n);
   int search1=searchLinear(s,list,n);
   if (search1==-1)
   {
      printf("searchLinear: The integer you searched for does not exist in the array.\n");
   }
   else
   {
      printf("searchLinear: The integer %i has an index value of %i\n",s,search1);
   }
   int searchBinary(int s, int *list, int n);
   int search2=searchBinary(s,list,n);
   if (search2==-1)
   {
      printf("searchBinary: The integer you searched for does not exist in the array.\n");
   }
   else
   {
      printf("searchBinary: The integer %i has an index value of %i\n",s,search2);
   }

return 0;
}

int searchLinear(int s, int *list, int n)
{
int index=0;
int match;
   for(int i=0;i<n;i++)
   {
      if (list[i]==s)
      {
      index=i;
      return index;
      }
      else
      {
      index=-1;
      }
   }
return index;
}


int searchBinary(int s, int *list, int n)
{
int index=0;
int k=n-1;
int f=0;
int m=k/2;
   while (index<=k)
   {
      if (list[m]<s)
      {
         f=m+1;
      }
      else if (list[m]==s)
      {
         return m;
      }
      else
      {
         k=m-1;
      }
      m=(f+k)/2;
   }
   if (f>k)
   {
      return -1;
   }

return -1;
}
