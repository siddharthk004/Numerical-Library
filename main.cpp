#include "Matrix.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include "Polation.hpp"

int main()
{


    Matrix m1,m2;
    // m1.inputFileMatrix("Input/vec1polation.txt");
    // m2.inputFileMatrix("Input/vec2polation.txt");
    // double x = -1;
    // Polation ans;
    // double result = ans.lagrangeInterpolation(x,m1,m2);
    // cout << "Interpolated value at x = " << x << " is " << result << endl;

    // Polation p;
    // int n = 5;
    // double x = 0.6;
    // std::cout << "T_" << n << "(" << x << ") = " << p.Tchebyshev(n, x) << std::endl;

    // cout << "**************************************" << endl;

    // Matrix l1,l2,l3,l4;
    // l1.inputFileMatrix("Input/line1.txt");
    // l2.inputFileMatrix("Input/line2.txt");
    // l3.inputFileMatrix("Input/vec1polation.txt");
    // l4.inputFileMatrix("Input/vec2polation.txt");
    // double line1 = ans.LineParabola(l1,l2);

    // cout << "Ax2 + Bx + c  value = " << line1 << endl;

    // double line = ans.ExponentialFit(l3,l4);

    // cout << "Expo Fit = " << line << endl;

    // double line2 = ans.PowerFit(l3,l4);

    // cout << "Power fit = " << line2 << endl;
    ///////////////////////////////////////////////////////////

    // // double Ans1 = ans.lagrangeI(-1);
    // // cout << "Interpolated value at -1 = " << Ans1 << endl;
    // cout << "**************************************" << endl;
    // cout << "Read From File And Print It" << endl;
    // cout << "**************************************" << endl;

    // Matrix m2, m3, M6, M7;
    // // Read 49 X 49 Matrix
    // cout << "49 X 49 Matrix:" << endl;
    m2.inputFileMatrix("Input/ex1.txt");
    // m3.inputFileMatrix("Input/49r.txt");
    
    // M6.inputFileMatrix("Input/input1X.txt");
    // M7.inputFileMatrix("Input/input2.txt");

    // Matrix m4, m5;
    // // Read 225 X 225 Matrix
    // cout << "225 X 225 Matrix:" << endl;
    // m4.inputFileMatrix("Input/225left.txt");
    // m5.inputFileMatrix("Input/225right.txt");

    // cout << "**************************************" << endl;
    // cout << "Read File" << endl;
    // cout << "**************************************" << endl;

    Matrix M6;
    M6.inputFileMatrix("Input/b1.txt");
    M6.displayMatrix();

    // cout << "**************************************" << endl;
    // cout << "A = L.U" << endl;
    // cout << "**************************************" << endl;

    // Matrix U = M1.UpperMatrix();
    // U.displayMatrix();

    // Matrix L = M1.LowerMatrix();
    // L.displayMatrix();

    // Matrix Choleski = L.MultMatrix(U);
    // Choleski.displayMatrix();

    // Matrix answer1 = M1.DolittleLU();
    // answer1.displayMatrix();


    
    Matrix paper,Ans;
    paper.inputFileMatrix("Input/p1.txt");

    Matrix o1,o2,o3,o4;
    int n = paper.rows;
    paper.cols += 1;



    
    o2.inputFileMatrix("Input/p2.txt");

    for(int i = 0;i < n;i++)
    {
        paper.data[i].push_back(o2.data[i][0]);
    }
    paper.displayMatrix();

    o3.inputFileMatrix("Input/p3.txt");
    paper.cols += 1;
    for(int i = 0;i < n;i++)
    {
        paper.data[i].push_back(o3.data[i][0]);
    }
    paper.displayMatrix();

    o4.inputFileMatrix("Input/p4.txt");
    paper.cols += 1;
    for(int i = 0;i < n;i++)
    {
        paper.data[i].push_back(o4.data[i][0]);
    }
    paper.displayMatrix();





    cout << "**************************************" << endl;
    cout << "LU" << endl;
    cout << "**************************************" << endl;

    cout << "Upper" << endl;

    Matrix U1 = paper.UpperMatrix();
    U1.displayMatrix();

    cout << "Lower" << endl;

    Matrix L1 = paper.LowerMatrix();
    L1.displayMatrix();

    // U1.MultMatrix(L1);


    cout << "Ans" << endl;
    Matrix A1 = L1.MultMatrix(U1);
    A1.displayMatrix();
    

    Matrix q2 = paper.GaussElimination(M6);
    q2.displayMatrix();

    Matrix q3 = paper.MultMatrix(q2);
    q3.displayMatrix();
    
    Matrix q4 = A1.MultMatrix(q2);
    q4.displayMatrix();
    
    Matrix q5 = paper.MultMatrix(q2);
    q5.displayMatrix();

    // Matrix answer2 = m2.DolittleLU();
    // answer2.displayMatrix();


    // cout << "**************************************" << endl;
    // cout << "Gauss Jacobi" << endl;
    // cout << "**************************************" << endl;
    // M6.GaussJacobi();
    // // M7.GaussJacobi();

    // cout << "**************************************" << endl;
    // cout << "Gauss seidal" << endl;
    // cout << "**************************************" << endl;
    // M6.GaussSeidel();
    // M7.GaussSeidel();

    // cout << "**************************************" << endl;
    // cout << "End" << endl;
    // cout << "**************************************" << endl;

    return 0;
}

/*
1 Create complex Number
2 Add Two complex Number
3 Sub Two complex Number
4 Mult Two complex Number
5 Div Two complex Number
6 Norm Of Complex Number
7 Conjugate Of Complex Number
8 Display Complex Number
9 Bisection Method
10 Newton Raphson Method
11 Fixed Point Method
12 Read Matrix From file
13 Addition of Two Matrix
14 Substraction of Two Matrix
15 Multiplication of Two Matrix
16 is Diagonal
17 is Identity
18 Gausian Elimination Matrix
19 Back substitution
20 Find Inverse of Matrix
21 Find Determinant of Matrix
22 Gauss Jacobi
23 Gauss Seidal
24 Iterative Jacobi
25 Iterative Seidal
26 MakeDominant
27 dolittle LU
28 IsDominant
29 
*/