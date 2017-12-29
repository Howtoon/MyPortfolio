//Implementation of Polynomial.

#include <stdlib.h>

#include <stdio.h>

#include <math.h>

#include "polynomial.h"

	//Define the poly
struct poly {Coeff *coeff;int deg;};

Poly createPoly(int degree)
{
	//Poly is a typedef of poly *
	//malloc will return a pointer to a newly allocated memory
	//sizeof will allocate the amout of memory necessary
	//to hold the type the is pointed to by newPoly
	//since newPoly is a Poly which has been typedef'd to a
	//poly * (look at polynomial.h) it allocates enough size
	//for a poly struct
	Poly newPoly = malloc(sizeof *newPoly);
	newPoly->coeff = malloc(sizeof (Coeff)*(degree+1));
		//
	newPoly->deg=degree;
		//Sets newPoly->deg to highest degree
	int i;	
	for (i=0;i<newPoly->deg+1;++i)
		//This loop initializes the coeff[] array to 0
	{
		newPoly->coeff[i]=0;
	}	
	return newPoly;
}

Poly setTerm(Poly a, int degree, int coff)
	//Sets the coefficient of specified degree
{
	a->coeff[degree]=coff;
	return a;
}

Poly addPoly(Poly a, Poly b)
	//Algorithm to add two polynomials together.
{
	int i;	//counter
	Poly c;	//new polynomial to store the result
	if (a->deg>b->deg)	//Checks for highest degree
	{
		c=createPoly(a->deg);	//Creates new Poly with highest possible degree
		for (i=c->deg;i>-1;--i) //Copies highest degree polynomial to new Poly
		{
			c->coeff[i]=a->coeff[i];
		}
		for (i=b->deg;i>-1;--i)	//Adds coefficients from smaller degree polynomial to new Poly
		{
			c->coeff[i]=(c->coeff[i]+b->coeff[i]);
		}
	}
	else if (b->deg>a->deg)	//Checks for highest degree
	{
		c=createPoly(b->deg);
			 //Creates new Poly with highest possible degree
		for (i=c->deg;i>-1;--i)	
			//Copies highest degree polynomial to new Poly
		{
			c->coeff[i]=b->coeff[i];
		}
		for (i=a->deg;i>-1;--i)	
			//Adds coefficients from smaller degree polynomial to new Poly
		{
			c->coeff[i]=(c->coeff[i]+a->coeff[i]);
		}
	}
	else if (a->deg==b->deg) //Checks for equality
	{
		c=createPoly(a->deg);	
			//Creates new Poly with highest degree
		for (i=c->deg;i>-1;--i)
			//Add coefficients together to fill new Poly
		{
			c->coeff[i]=(a->coeff[i]+b->coeff[i]);
		}
	}
	return c;	//Returns new Poly
}

Poly multPoly(Poly a, Poly b)
	//Algorithm to multiply two polynomials together
{
	int degree=(a->deg+b->deg);
		//Adds the highest degrees from polynomials to store degree of new Poly
	int i;	
		//Counter (Outer)
	int j;	
		//Counter (Inner)
	int exp;	
		//Stores result of adding exponents
	Poly c=createPoly(degree);
			//Creates a new Poly of highest degree possible
	for (i=a->deg;i>-1;--i)
				//Outer loop increments Poly a
	{
		for (j=b->deg;j>-1;--j)
				//Inner loop increments Poly b
		{
			exp=(i+j);
				//Stores sum of exponents
			c->coeff[exp]=(c->coeff[exp]+(a->coeff[i]*b->coeff[j]));
				//Equation to add product and sum to new Poly
		}
	}	
	return c;
}

float evalPoly(Poly a, float x)
	//Plugs an x value into the polynomial and outputs the result as a float variable.
{
	float y=0;	//Stores result as float
	int i=0;	//Outer loop counter
	int j=0;	//Inner loop Counter
	float product;	//Stores Inner loop result as float
	for (i=a->deg;i>-1;--i)
		//Loop starts at highest degree
	{
		for (j=i,product=(float)x;j>1;--j)
			//This loop decriments j (which is set to degree by i) until it reaches 1
		{
			product=(float)product*x;
				//This will loop and multiply the product exponentially
		}
		if (i==1)
			//If i(degree/exponent)==1, then the result will equal the x value.
			product=(float)x;
		if (i==0)
			//If i(degree/exponent)==0, then the result will equal 1
			product=(float)1;
		product=(float)product*a->coeff[i];
			//This multiplies the product of the exponential loop by the coefficient
		y=(float)y+product;
			//This adds the product of the exponential and coefficient to the result and begins the loop again
	}
	return y;
}

void printPoly(Poly a)
	//Prints Poly
{
	int i;	
	for (i=a->deg;i>-1;--i)
	{
		if (a->coeff[i]>0&&i!=a->deg)
			printf("+");
		printf("%dx^%d ",a->coeff[i],i);
	}
	return;
}
