#include <iostream>
using namespace std;
#include <cmath>

class Root_Finding
{
    public:
        double TOL;
        int Itr;

    Root_Finding();
    double Bisection(double a,double b);

    
    double Newton_Raphson(double a);
    double Fixed_Point(double a);
};