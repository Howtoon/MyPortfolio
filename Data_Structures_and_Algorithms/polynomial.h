#ifndef POLY_H
#define POLY_H

typedef int Coeff;
   //Typedef an int array to be stored in  Poly struct.

typedef struct poly *Poly;
   //Typedef a poly * to be Poly. 

Poly newPoly(int degree);
   //Takes in an integer that cooresponds with the highest degree of the polynomial to be created.
   //Creates a struct of arrays that will hold the coefficients of the polynomial.
   //The degrees of the polynomial will be represented by the index number of the array.

Poly setTerm(Poly a, int degree, int coeff);
   //Takes in a struct of Poly,the degree/exponent, and the coefficient.
   //Sets the coefficient to the corresponding degree index in the Poly struct.

Poly addPoly(Poly a, Poly b);
   //Takes in two Poly structs and adds them together.
   //Creates a new Poly struct containing the sum and returns it.

Poly multPoly(Poly a, Poly b);
   //Takes in two Poly structs and adds them together.
   //Creates a new Poly struct containing the product and returns it.

float evalPoly(Poly a, float x);
   //Takes in a Poly and a value of x to evaluate the value of the polynomial at the given x.
   //Outputs the answer as a float variable.

void printPoly(Poly a);
   //Prints the Poly struct to screen with appropriate agebraic notation.
   
#endif