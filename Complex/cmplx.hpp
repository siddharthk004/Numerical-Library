#include <iostream>

class cmplx
{
public:
    double real;
    double img; 
public:
    cmplx();
    cmplx(double x, double y);
    cmplx add(cmplx addV);
    cmplx mult(cmplx addV);
    cmplx div(cmplx addV);
    cmplx sub(cmplx addV);
    double norm();
    void complexConjugate();
    void display();
};
