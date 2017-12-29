   //Define the poly
struct poly {Coeff *coeff;};

Poly newPoly(int degree)
{
    //Poly is a typedef of poly *
    //malloc will return a pointer to newly allocated memory
    //sizeof will allocate the amount of memory necessary
    //to hold the type that is pointed to by newPoly
    //since newPoly is a Poly which has been typedef'd to a
    //poly * (look at the poly.h) it allocates enough size
    //for a poly struct
    Poly newPoly =  malloc(sizeof *newPoly);
    newPoly->coeff= malloc(sizeof (Coeff)*(degree+1));
    
    

    return newPoly;
}