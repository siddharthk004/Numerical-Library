// #include "Matrix.hpp"
#include "./Root-Finding/Root_Finding.hpp"
// #include "./Complex/cmplx.hpp"
 
int main()
{
    // cout << "Matrix Library" << endl; 
    // int r = 0,c = 0;
    // cout << "Enter the number of rows: ";
    // cin >> r;
    // cout << "Enter the number of columns: ";
    // cin >> c;
    // Matrix m1(r, c);
    // m1.inputMatrix(m1);
    // m1.displayMatrix(m1);
    // m1.GaussElimination(m1);
    // m1.displayMatrix(m1);

    
    Root_Finding R1,R2,R3;

    cout << "\n\nRoot_finding function called Bisection" << endl;
    double Ans1 =  R1.Bisection(0.0,1.0);
    cout << "The root of the equation is: " << Ans1 << endl;

    cout << "\n\nRoot_finding function called Newton Raphson" << endl;
    double Ans2 =  R2.Newton_Raphson(1.0);
    cout << "The root of the equation is: " << Ans2 << endl;

    cout << "\n\nRoot_finding function called Fixed Point" << endl;
    for(double i = -10;i < 10;i++)
        double Ans3 =  R3.Fixed_Point(i);
    cout << "The root of the equation is: " << Ans3 << endl;

    // cmplx ans;
    // cmplx obj1(3.0,2.0);
    // obj1.display();

    // cmplx obj2(1.0,4.0);
    // obj2.display();

    // ans = obj1.add(obj2);    
    // ans.display();

    // ans = obj1.sub(obj2);
    // ans.display();
    
    // ans = obj1.mult(obj2);
    // ans.display();

    // ans = obj1.div(obj2);
    // ans.display();

    // double ansD = obj1.norm();
    // std::cout << "Norm of obj1: " << ansD << std::endl;

    // obj1.complexConjugate();

    return 0;
} 