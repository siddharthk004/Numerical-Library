#include <iostream>
using namespace std;

class polynomial
{
public:
    int A;
    int B;
    polynomial()
    {
        A = 4;
        B = 3;
    }

    polynomial(int a, int b)
    {
        A = a;
        B = b;
    }

    // Polynomial P(x) = AX^3 - BX
    float functionPoly(float x)
    {
        return ((A * (x * x * x)) - (B * x)); // 4X^3 - 3X
    }

    float DfunctionPoly(float x)
    {
        return (((3*A) * (x * x)) - (B));  // 12X^2-3
    }

    double function_g(double X)
    {
        return ((X*X)+5)/5;   // X^2 + 5  / 5
    }
};