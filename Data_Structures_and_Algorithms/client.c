/*
 * This is a client of the Polynomial ADT
 * To compile this program, you will need the command:
 * gcc -Wall polynomial.c client.c -o client
 */

#include <stdio.h>
#include "polynomial.h"

int main()
{
   int a=2;
   Poly testPoly;
   newPoly(a);
   return 0;
}