#include <iostream>
#include <cmath>
#include "Num.hpp"

Num::Num(double num)
{
    this->num = num;
    fraction1 = 0;
    fraction2 = 0;
    convert();
}

void Num::convert()
{
    number = (int)num;
    double temp = num - number; // Extract fractional part
    int count = 0;              // Count decimal places
    double frac = temp;

    // Loop to count decimal places and remove floating-point errors
    while (std::fabs(frac - (int)frac) > 1e-9 && count < 10) // Prevent infinite loops
    { 
        frac *= 10;
        count++;
    }

    fraction2 = pow(10, count);
    fraction1 = static_cast<int>(temp * fraction2); // Convert to integer

    fraction(); 
}

int Num::gcd(int x, int y) // Changed to int
{
    if (y == 0)
        return x;
    return gcd(y, x % y);
}

void Num::fraction()
{
    int gcd_val = gcd(fraction1, fraction2);
    fraction1 /= gcd_val;
    fraction2 /= gcd_val;
    
    display();
}

void Num::display()
{
    if (fraction1 == 0)
        std::cout << number;
    else
    {
        std::cout << number << " + " << fraction1 << "/" << fraction2;
    }
    std::cout << std::endl;
}
