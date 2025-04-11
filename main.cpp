#include "Matrix.hpp"
#include "Polation.hpp"

int main()
{
    Matrix m1,m2;
    m1.inputFileMatrix("Input/vec1polation.txt");
    m2.inputFileMatrix("Input/vec2polation.txt");
    double x = -1;
    Polation ans;
    double result = ans.lagrangeInterpolation(x,m1,m2);
    cout << "Interpolated value at x = " << x << " is " << result << endl;


    cout << "**************************************" << endl;

    Matrix l1,l2;
    l1.inputFileMatrix("Input/line1.txt");
    l2.inputFileMatrix("Input/line2.txt");
    double line = ans.LineParabola(l1,l2);

    cout << "Ax2 + Bx + c  value = " << line << endl;



    // // double Ans1 = ans.lagrangeI(-1);
    // // cout << "Interpolated value at -1 = " << Ans1 << endl;
    // cout << "**************************************" << endl;
    // cout << "Read From File And Print It" << endl;
    // cout << "**************************************" << endl;

    // Matrix m2, m3, M6, M7;
    // // Read 49 X 49 Matrix
    // cout << "49 X 49 Matrix:" << endl;
    // m2.inputFileMatrix("Input/49l.txt");
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

    // Matrix M1;
    // M1.inputFileMatrix("Input/input1.txt");
    // M1.displayMatrix();

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


    // cout << "**************************************" << endl;
    // cout << "A = L.U 49 X 49" << endl;
    // cout << "**************************************" << endl;

    // Matrix U1 = m2.UpperMatrix();
    // U1.displayMatrix();

    // Matrix L1 = m2.LowerMatrix();
    // L1.displayMatrix();

    // Matrix A1 = L1.MultMatrix(U1);
    // A1.displayMatrix();

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
    cout << "**************************************" << endl;

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