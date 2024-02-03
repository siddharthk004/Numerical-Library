#include <iostream>
#include <cmath>
using namespace std;

class BisectionMethod
{
private:
    float a; // Lower bound
    float b; // Upper bound
    int cnt; // Iteration counter

    // Polynomial P(x) = 2X^2 - 1
    float polynomial(float x)
    {
        return (2 * x * x) - 1;
    }

public:
    BisectionMethod(float a, float b) : a(a), b(b), cnt(0) {}

    float solution()
    {
        const float tolerance = 0.00001; // Convergence tolerance
        const int maxIterations = 100;  // Max number of iterations

        float fa = polynomial(a);
        float fb = polynomial(b);

        // Check if initial guesses bracket the root
        if (fa * fb > 0)
        {
            cout << "The initial guesses do not bracket a root. Exiting..." << endl;
            return NAN;
        }

        while (cnt < maxIterations)
        {
            float x = (a + b) / 2.0; // Midpoint
            float fx = polynomial(x);

            // Print iteration details
            cout << "Iteration " << cnt + 1 << ": a = " << a << ", b = " << b << ", x = " << x << ", f(x) = " << fx << endl;

            // Check for convergence
            if (fabs(fx) < tolerance || fabs(b - a) < tolerance)
            {
                return x;
            }

            // Update bounds
            if (fa * fx < 0)
            {
                b = x; // Root lies in [a, x]
                fb = fx;
            }
            else
            {
                a = x; // Root lies in [x, b]
                fa = fx;
            }

            cnt++;
        }

        cout << "Maximum iterations reached. Approximate solution: ";
        return (a + b) / 2.0; // Return midpoint as the approximate solution
    }
};

int main()
{
    float a, b;
    cout << "Solving P(X) = 2X^2 - 1 using the Bisection Method" << endl;
    cout << "Enter the value of A (lower bound): ";
    cin >> a;
    cout << "Enter the value of B (upper bound): ";
    cin >> b;

    BisectionMethod brc(a, b);
    float ans = brc.solution();

    if (!isnan(ans))
    {
        cout << "The root of the equation is: " << ans << endl;
    }
    else
    {
        cout << "Failed to find a root." << endl;
    }

    return 0;
}
