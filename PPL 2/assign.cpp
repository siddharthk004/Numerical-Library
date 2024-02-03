#include <iostream>
using namespace std;

double convert (double value)
{
    return 1.8*value+32;
}

int main() {
    float  celcius = 0.0;

    cout<<"Enter the Temperature \n"; 
    cin>>celcius;

    double ans = convert(celcius);

    cout<<"The equivalent temperature in Fahrenheit is: "<<ans<<endl;

    return 0;
}