#include "./Root_Finding.hpp"
#include "../Function/polynomial.hpp"

Root_Finding::Root_Finding()
{
    TOL = 0.0001;
    Itr = 0;
}

double Root_Finding::Bisection(double a, double b)
{
    polynomial p1;

    while (fabs(a - b) > TOL)
    {
        double func_a = p1.functionPoly(a);
        double func_b = p1.functionPoly(b);

        if (func_a * func_b > 0)
        {
            std::cout << "No root in the given interval" << endl;
            return -1;
        }

        double ans_a = (a + b) / 2;
        double func_ans_a = p1.functionPoly(ans_a);

        if (fabs(func_ans_a) < TOL)
        {
            return ans_a;
        }

        if (func_a * func_ans_a < 0)
        {
            b = ans_a;
        }
        else
        {
            a = ans_a;
        }

        Itr++;

        if (Itr >= 50)
        {
            cout << "Max iterations reached, stopping iteration." << endl;
            break;
        }
        cout << "cnt = " << Itr << endl;
    }
    return a;
}

double Root_Finding::Newton_Raphson(double a)
{
    polynomial p1;
    while (true)
    {
        double func = p1.functionPoly(a);
        double func_d = p1.DfunctionPoly(a);

        // Prevent division by zero
        if (fabs(func_d) < TOL)
        {
            cout << "Derivative too small, stopping iteration." << endl;
            break;
        }

        // Newton-Raphson formula
        double next_a = a - (func / func_d);

        // Check for convergence
        if (fabs(next_a - a) < TOL)
        {
            a = next_a;
            break;
        }

        a = next_a;
        Itr++;

        if (Itr >= 50)
        {
            cout << "Max iterations reached, stopping iteration." << endl;
            break;
        }
        cout << "cnt = " << Itr << endl;
    }

    return a;
}

double Root_Finding::Fixed_Point(double a)
{
    polynomial p1;
    while (Itr <= 500)
    {
        double func_g = p1.function_g(a);

        // Check for convergence
        if (fabs(func_g - a) < TOL)
        {
            return func_g;
        }
        Itr++;
        a = func_g;
    }
    return a;
}