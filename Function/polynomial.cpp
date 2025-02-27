#include "polynomial.hpp"

polynomial::polynomial()
{
    A = 0;
    B = 0;
    C = 0;
    D = 0;
}

polynomial::polynomial(int a, int b, int c, int d)
{
    A = a;
    B = b;
    C = c;
    D = d;
}

// Deriavative Function
float polynomial::functionPolyA(float x)
{
    return ((A * (x * x * x)) + (B * (x * x)) + (C * x) + D); // AX^3+BX^2+CX+D
}

float polynomial::functionPolyB(float x)
{
    return ((A * (x * x * x)) - (B * (x * x)) - (C * x) - D); // AX^3-BX^2-CX-D
}


// Double Deriavative Function
float polynomial::functionDoublePolyA(float x)
{
    return (((A*3)*(x*x))+(2*B)*x+C); // 3AX^2+BX^2+C
}

float polynomial::functionDoublePolyB(float x)
{
    return (((A*3)*(x*x))-(2*B)*x-C); // 3AX^2-BX^2-C
}

///////////////////////////////////////////////////////////


// Function g(x)
double polynomial::function_g(double X)
{
    return ((X * X) + 5) / 5; // X^2+5/5
}