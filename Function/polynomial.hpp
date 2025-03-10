#include <iostream>
using namespace std;

class polynomial
{
public:
    int A,B,C,D;

    polynomial();
    polynomial(int a, int b, int c, int d);
    float functionPolyA(float x);
    float functionPolyB(float x);
    float functionDoublePolyA(float x);
    float functionDoublePolyB(float x);
    double function_g(double X);
    double X(double y,double z);
    double Y(double x,double z);
    double Z(double x,double y);
};