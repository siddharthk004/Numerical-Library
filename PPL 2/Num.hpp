#include <iostream>
using namespace std;

class Num
{
public:
    int number;
    int fraction1;
    int fraction2;
    double num;

    Num(double num);

    void convert();

    int gcd(int x, int y);

    void fraction();

    void display();
};