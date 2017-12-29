#include <stdio.h>
#include "polynomial.h"

int main()
{	
	float y=0;
	
	printf("\n\n");
	Poly P1=createPoly(5);
	P1=setTerm(P1,0,3);
	P1=setTerm(P1,1,2);
	P1=setTerm(P1,2,5);
	P1=setTerm(P1,3,-10);
	P1=setTerm(P1,4,7);
	P1=setTerm(P1,5,-4);
	printf("Create Poly P1: ");
	printPoly(P1);
	printf("\n\n");
	
	Poly P2=createPoly(7);
	P2=setTerm(P2,0,5);
	P2=setTerm(P2,1,-4);
	P2=setTerm(P2,2,8);
	P2=setTerm(P2,3,2);
	P2=setTerm(P2,4,-7);
	P2=setTerm(P2,5,9);
	P2=setTerm(P2,6,-3);
	P2=setTerm(P2,7,6);
	printf("Create Poly P2: ");
	printPoly(P2);
	printf("\n\n");
	
	printf("Evaluate Poly P1 at x=2: ");
	printPoly(P1);
	y=evalPoly(P1,2);
	printf("=%f\n\n",y);

	printf("Add Polys:(");
	printPoly(P1);
	printf(")+(");
	printPoly(P2);
	printf(")\n\tResult:=(");
	Poly P3=addPoly(P2,P1);
	printPoly(P3);
	printf(")\n\n");
	
	printf("Multiply Polys:(");
	printPoly(P1);
	printf(")(");
	printPoly(P2);
	Poly P4=multPoly(P1,P2);
	printf(")\n\tResult:=(");
	printPoly(P4);
	printf(")\n\n");
	
/*	Poly P5=createPoly(2);
	P5=setTerm(P5,0,1);
	P5=setTerm(P5,1,2);
	P5=setTerm(P5,2,1);
	printPoly(P5);

	Poly P6=createPoly(2);
	P6=setTerm(P6,0,2);
	P6=setTerm(P6,1,3);
	P6=setTerm(P6,2,4);
	printPoly(P6);
	
	Poly P7=multPoly(P5,P6);
	printPoly(P7);
*/
return 0;
}

