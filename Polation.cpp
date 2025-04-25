#include "Polation.hpp"
#include <math.h>

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
    cout << "Ax2 + Bx + c  value = " << ans[0][0] << "X^2" << ans[1][0] << "X" << ans[2][0] << endl;

    double totalError = 0.0;
    for (int i = 0; i < n; i++)
    {
        double xi = x[0][i];
        double yi = y[0][i];
        double predicted = p1.lineFunc(xi, ans[0][0], ans[1][0], ans[2][0]);
        totalError += (yi - predicted) * (yi - predicted);
    }
    double rmsError = sqrt(totalError / n);
    return rmsError;
}

double Polation::ExponentialFit(Matrix x, Matrix y)
{
    int n = x[0].size();
    if (y[0].size() != n)
        return -1;

    double sumX = 0.0, sumY = 0.0, sumX2 = 0.0, sumXY = 0.0;

    for (int i = 0; i < n; i++)
    {
        double xi = x[0][i];
        double yi = y[0][i];
        if (yi <= 0)
            return -1;

        double logY = log(yi);
        sumX += xi;
        sumY += logY;
        sumX2 += xi * xi;
        sumXY += xi * logY;
    }

    double denominator = n * sumX2 - sumX * sumX;
    double b = (n * sumXY - sumX * sumY) / denominator;
    double lnA = (sumY * sumX2 - sumX * sumXY) / denominator;
    double a = exp(lnA);

    cout << "Exponential Fit: y = " << a << " * e^(" << b << " * x)" << endl;

    double totalError = 0.0;
    for (int i = 0; i < n; i++)
    {
        double predicted = a * exp(b * x[0][i]);
        totalError += pow(y[0][i] - predicted, 2);
    }

    return sqrt(totalError / n); // RMS Error
}

double Polation::PowerFit(Matrix x, Matrix y)
{
    int n = x[0].size();
    if (y[0].size() != n)
        return -1;

    double sumLogX = 0.0, sumLogY = 0.0, sumLogX2 = 0.0, sumLogXY = 0.0;

    for (int i = 0; i < n; i++)
    {
        double xi = x[0][i];
        double yi = y[0][i];
        if (xi <= 0 || yi <= 0)
            return -1;

        double logX = log(xi);
        double logY = log(yi);

        sumLogX += logX;
        sumLogY += logY;
        sumLogX2 += logX * logX;
        sumLogXY += logX * logY;
    }

    double denominator = n * sumLogX2 - sumLogX * sumLogX;
    double b = (n * sumLogXY - sumLogX * sumLogY) / denominator;
    double lnA = (sumLogY * sumLogX2 - sumLogX * sumLogXY) / denominator;
    double a = exp(lnA);

    cout << "Power Fit: y = " << a << " * x^" << b << endl;

    double totalError = 0.0;
    for (int i = 0; i < n; i++)
    {
        double predicted = a * pow(x[0][i], b);
        totalError += pow(y[0][i] - predicted, 2);
    }

    return sqrt(totalError / n); // RMS Error
}

double Polation::lineFunc(double xi, double a, double b, double c)
{
    return a * (xi * xi) + b * xi + c;
}

// To(0) = 1
// To(1) = x
double Polation::Tchebyshev(int n, double x)
{
    if (n == 0)
        return 1;
    if (n == 1)
        return x;

    double Tn_2 = 1;
    double Tn_1 = x;
    double Tn;

    for (int i = 2; i <= n; ++i)
    {
        Tn = 2 * x * Tn_1 - Tn_2;
        Tn_2 = Tn_1;
        Tn_1 = Tn;
    }
    return Tn;
}
