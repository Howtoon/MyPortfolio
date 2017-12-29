#include <stdio.h>

int main(void)
{
  int length=0;
  do{
     printf("Please enter the length of the Fibonacci sequence to generate between 1 and 75: ");
     scanf(" %i", &length);
  }while ((length<1)||(length>75));
  int fibSequence[length]={[0]=0,[1]=1};
  printf("%i, %i, ");
  for (int i=2;i<length;i++)
  {
     fibSequence[i]=(fibSequence[(i-1)]+fibSequence[i-2]);
     printf("%i, ",fibSequence[i]);
  }
return 0;
}