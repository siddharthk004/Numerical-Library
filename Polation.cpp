#include "Polation.hpp"

double Polation::lagrangeInterpolation(double x,Matrix EQ1,Matrix EQ2) {
    int n = EQ1.size();
    double result = 0.0;

    for (int j = 0; j < n; ++j) {
        double term = EQ2[j][0];
        for (int i = 0; i < n; ++i) {
            if (i != j) {
                term *= (x - EQ1[i][0]) / (EQ1[j][0] - EQ1[i][0]);
            }
        }
        result += term;
    }
    return result;
}
double Polation::lagrangeI(double x) {
    return (3*(x*x)-(2*x)+1);
}
