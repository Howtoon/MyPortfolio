#include <stdio.h>
 
int getMax(int list[], int num_elements);

int main(void)
{
    int i, j, a, n, list[30];
    int max;
    int temp=n;
 
    printf("Enter the value of N \n");
    scanf("%d", &n);
    printf("Enter the numbers \n");
    for (i = 0; i < n; ++i)
    {    
        scanf("%d", &list[i]);
    }
    max = getMax(list, temp);
    for (i = 0; i < n; ++i)
    {
        for (j = i + 1; j < n; ++j)
        {
            if (list[i] > list[j])
            {
                
                a =  list[i];
                list[i] = list[j];
                list[j] = a;
                temp--;
            }
        }
    }
    printf("The numbers arranged in ascending order are given below \n");
    for (i = 0; i < n; ++i)
    {  
       printf("%d ", list[i]);
    }  
}


int getMax(int list[], int num_elements)
{
   int i, max=-32000;
   for (i=0; i<num_elements; i++)
   {
	 if (list[i]>max)
	 {
	    max=list[i];
	 }
   }
   return(max);
}
