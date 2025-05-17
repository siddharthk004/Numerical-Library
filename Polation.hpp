#include <iostream>
#include <vector>
#include "Matrix.hpp"

using namespace std;

class Polation
{
public:
    double lagrangeInterpolation(double x, Matrix EQ1, Matrix EQ2);
    // double PowerFit();
    double lagrangeI(double x);
    // double ExponentialFit();
    double lineFunc(double xi, double a, double b, double c);
    double LineParabola(Matrix x, Matrix y);
    double PowerFit(Matrix x, Matrix y);
    double ExponentialFit(Matrix x, Matrix y);


    double Tchebyshev(int n, double x);
};
