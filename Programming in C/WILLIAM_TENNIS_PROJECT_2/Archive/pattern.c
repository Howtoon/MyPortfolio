#include <stdio.h>
#include <string.h>
#include <stdbool.h>
 
int contains(char [], char []);
 
int main() {
  char text[100], pattern[100], menu[20];
  int index;
  bool run=true;
do{
  printf("Enter a string of text: ");
  gets(text);
  printf("Enter a pattern to search for: ");
  gets(pattern);
  index=contains(text,pattern);
  if(index!=-1)
    printf("Found at index: %d\n", index);
  else
    printf("Pattern not found in string.\n");
  printf("Again? Y/N: ");
  gets(menu);
  if (menu[0]=='n'||menu[0]=='N')
   run=false;
}while(run==true);
return 0;
}
 
int contains(char text[], char pattern[])
{
  int i;
  int j;
  int k;
  int textL;
  int patternL;
  int index=-1;
  
  patternL=strlen(pattern);
  textL=strlen(text);
  
  if (patternL>textL)
    return -1;
  for (i=0;i<=(textL-patternL);i++)
  {
    index = k = i;
    for (j = 0; j<patternL; j++)
    {
      if (text[k]==pattern[j])
        k++;
      else
        break;
    }
    if (j==patternL)
      return index;
  }
  return -1;
}