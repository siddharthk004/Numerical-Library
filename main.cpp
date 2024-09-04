#include "Matrix.hpp"

int main()
{
    cout << "**************************************" << endl;
    cout << "Read From File And Print It" << endl;
    cout << "**************************************" << endl;

    Matrix m2,m3;
    // Read 49 X 49 Matrix
    cout << "49 X 49 Matrix:" << endl;
    m2.inputFileMatrix("Input/49l.txt");
    m3.inputFileMatrix("Input/49r.txt");

    Matrix m4,m5;
    // Read 225 X 225 Matrix


    cout << "225 X 225 Matrix:" << endl;
    m4.inputFileMatrix("Input/225left.txt");
    m5.inputFileMatrix("Input/225right.txt");

    cout << "**************************************" << endl;
    cout << "49 X 49 Gauss Elim.." << endl;
    cout << "**************************************" << endl;   
    Matrix ans1 = m2.GaussElimination(m3);
    ans1.displayMatrix();
    
    cout << "**************************************" << endl;
    cout << "225 X 225 Gauss Elim.." << endl;
    cout << "**************************************" << endl;
    Matrix ans2 = m4.GaussElimination(m5);
    ans2.displayMatrix();


    cout << "**************************************" << endl;
    cout << "Read File" << endl;
    cout << "**************************************" << endl;

    Matrix M1;
    M1.inputFileMatrix("Input/input1.txt");
    M1.displayMatrix();

    cout << "**************************************" << endl;
    cout << "A = L.U" << endl;
    cout << "**************************************" << endl;

    Matrix U = M1.UpperMatrix();
    U.displayMatrix();

    Matrix L = M1.LowerMatrix();
    L.displayMatrix();

    Matrix A = L.MultMatrix(U);
    A.displayMatrix();

    cout << "**************************************" << endl;
    cout << "Gauss Jacobi" << endl;
    cout << "**************************************" << endl;

    M1.GaussJacobi();

    cout << "**************************************" << endl;
    cout << "Gauss Seidal" << endl;
    cout << "**************************************" << endl;
    M1.GaussSeidal();

    cout << "**************************************" << endl;
    cout << "End" << endl;
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
 

*/