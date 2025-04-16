#include "Polation.hpp"
#include<math.h>

double Polation::lagrangeInterpolation(double x, Matrix EQ1, Matrix EQ2)
{
    int n = EQ1.size();
    double result = 0.0;

    for (int j = 0; j < n; ++j)
    {
        double term = EQ2[j][0];
        for (int i = 0; i < n; ++i)
        {
            if (i != j)
            {
                term *= (x - EQ1[i][0]) / (EQ1[j][0] - EQ1[i][0]);
            }
        }
        result += term;
    }
    return result;
}
double Polation::lagrangeI(double x)
{
    return (3 * (x * x) - (2 * x) + 1);
}


// Ax^2 + Bx + C

double Polation::LineParabola(Matrix x, Matrix y)
{
    int n = x[0].size();  // assuming x is 1xN
    int n1 = y[0].size(); // assuming y is 1xN
    if (n1 != n)
    {
        return -1;
    }

    double Sx1 = 0.0, Sy1 = 0.0, Sx2 = 0.0, Sx3 = 0.0, Sx4 = 0.0;
    double Sfixi = 0.0, Sfixi2 = 0.0;

    for (int i = 0; i < n; i++)
    {
        double xi = x[0][i];
        double yi = y[0][i];
        double xi2 = xi * xi;
        double xi3 = xi2 * xi;
        double xi4 = xi2 * xi2;

        Sx1 += xi;
        Sy1 += yi;
        Sx2 += xi2;
        Sx3 += xi3;
        Sx4 += xi4;

        Sfixi += yi * xi;
        Sfixi2 += yi * xi2;
    }

    Matrix M1(3, 3);
    Matrix M2(3, 1);

    M1.data[0][0] = Sx4;
    M1.data[0][1] = Sx3;
    M1.data[0][2] = Sx2;
    M2.data[0][0] = Sfixi2;

    M1.data[1][0] = Sx3;
    M1.data[1][1] = Sx2;
    M1.data[1][2] = Sx1;
    M2.data[1][0] = Sfixi;

    M1.data[2][0] = Sx2;
    M1.data[2][1] = Sx1;
    M1.data[2][2] = n;
    M2.data[2][0] = Sy1;

    Polation p1;
    Matrix ans = M1.GaussElimination(M2);
    ans.displayMatrix();
    cout << "Ax2 + Bx + c  value = " << ans[0][0] <<"X^2"<< ans[1][0] <<"X"<< ans[2][0]<< endl;

    double totalError = 0.0;
    for (int i = 0; i < n; i++)
    {
        double xi = x[0][i];
        double yi = y[0][i];
        double predicted = p1.lineFunc(xi, ans[0][0], ans[1][0], ans[2][0]);
        totalError += (yi - predicted)*(yi - predicted);
    }
    double rmsError = sqrt(totalError / n);
    return rmsError;
}

double Polation::lineFunc(double xi, double a, double b, double c)
{
    return a * (xi * xi) + b * xi + c;
}