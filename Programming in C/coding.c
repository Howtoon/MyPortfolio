#include <stdio.h>
#include <stdbool.h>

struct CodeT
{
char from[28];
char to[28];
}code;


void encodeStr( char *input, char *output, struct CodeT *code);
void decodeStr( char *input, char *output, struct CodeT *code);
int getIndexEncode ( char character, struct CodeT *code);

int main (void)
{
char textIn[100], textOut[100], *input[100], *output[100], selection[10];
int menu;
bool run=true;

   code.from[0] =' ';
   code.from[1] ='a';
   code.from[2] ='b';
   code.from[3] ='c';
   code.from[4] ='d';
   code.from[5] ='e';
   code.from[6] ='f';
   code.from[7] ='g';
   code.from[8] ='h';
   code.from[9] ='i';
   code.from[10]='j';
   code.from[11]='k';
   code.from[12]='l';
   code.from[13]='m';
   code.from[14]='n';
   code.from[15]='o';
   code.from[16]='p';
   code.from[17]='q';
   code.from[18]='r';
   code.from[19]='s';
   code.from[20]='t';
   code.from[21]='u';
   code.from[22]='v';
   code.from[23]='w';
   code.from[24]='x';
   code.from[25]='y';
   code.from[26]='z';
   code.from[27]='\0';

   code.to[0]='.';
   code.to[1]='1';
   code.to[2]='7';
   code.to[3]='2';
   code.to[4]='0';
   code.to[5]='9';
   code.to[6]='3';
   code.to[7]='%';
   code.to[8]='@';
   code.to[9]='#';
   code.to[10]='+';
   code.to[11]='!';
   code.to[12]=':';
   code.to[13]='_';
   code.to[14]='-';
   code.to[15]='$';
   code.to[16]='^';
   code.to[17]='*';
   code.to[18]='(';
   code.to[19]=')';
   code.to[20]='8';
   code.to[21]='5';
   code.to[22]='4';
   code.to[23]='=';
   code.to[24]='6';
   code.to[25]='?';
   code.to[26]='>';
   code.to[27]='\0';

do{
   for (int i=0;i<100;i++)
   {
      textIn[i]='\0';
      textOut[i]='\0';
   }
   printf("\nPlease make a choice\n1: Encode\n2: Decode\n1/2: ");
   gets(selection);   
   if (selection[0]=='1')
   {   
      printf("Enter the text to encode: ");
      gets(textIn);
      for (int i=0;i<100;i++)
         {
         input[i]=&textIn[i];
         output[i]=&textOut[i];
         }
      encodeStr(*input,*output,&code);
      printf("The text has been encoded to: %s\n",textOut);
   }
   if (selection[0]=='2')
   {
      printf("Enter the text to decode: ");
      gets(textIn);
      for (int i=0;i<100;i++)
         {
         input[i]=&textIn[i];
         output[i]=&textOut[i];
         }
      decodeStr(*input,*output,&code);
      printf("The text has been decoded to: %s\n",textOut);
   }
   printf("Again? Y/N: ");
   gets(selection);
   if (selection[0]=='n'||selection[0]=='N')
      run=false;
}while (run==true);
return 0;
}

void encodeStr( char *input, char *output, struct CodeT *code)
{
int index;
for (int i=0;i<100;i++)
   {
      for (int j=0;j<28;j++)
      {
        if (input[i]==code->from[j])
        index=j;
        output[i]=code->to[index];
      }
   }
return;
}

void decodeStr( char *input, char *output, struct CodeT *code)
{
int index;
for (int i=0;i<100;i++)
   {
      for (int j=0;j<28;j++)
      {
        if (input[i]==code->to[j])
        index=j;
        output[i]=code->from[index];
      }
   }
return;
}