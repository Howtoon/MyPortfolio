#include <stdio.h>

int main( void )
{
	float gpa=0;
	float numCourses=0;
	double sum=0, numberGrade=0;
	char  letterGrade=0, modifier=0;
   printf ("Enter the number of courses: ");
	scanf (" %f", &numCourses);
   printf("_____________________________________\n");

	for (int i=0; i<numCourses; i++)
   {
      
		printf ("What grade did you earn?\n");
		
		printf ("Enter A, B, C, D, or F: ");
		scanf (" %c", &letterGrade);


		printf ("Enter modifier - for letter grades A-, etc. + for letter grades B+, etc. , and _ for letter grades A, B, etc.: ");
		scanf (" %c", &modifier);
		if (letterGrade == 'A')
      {
			numberGrade = 4.0;
		}
      if (letterGrade == 'B')
      {
         numberGrade = 3.0;
		}
      if (letterGrade == 'C')
		{
         numberGrade = 2.0;
		}
      if (letterGrade == 'D')
		{
         numberGrade = 1.0;
		}
      if (letterGrade == 'F')
      {
			numberGrade = 0.0;
      }
		if (modifier == '-')
      {
         numberGrade = numberGrade - 0.3;
		}
      if (modifier == '+')
		{
         numberGrade = numberGrade + 0.3;
      }
		sum = sum + numberGrade;
	}

	gpa = sum/numCourses;

	printf ("The final gpa is %1.2f.\n", gpa);

	return 0;
}
	
