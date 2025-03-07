#include "Matrix.hpp"

int main()
{
    cout << "**************************************" << endl;

    // Read the first matrix from file
    Matrix m1;
    m1.inputFileMatrix("input1.txt");
    m1.displayMatrix();
    cout << "**************************************" << endl;

    // Read the second matrix from file
    Matrix m2;
    m2.inputFileMatrix("input2.txt");
    m2.displayMatrix();
    cout << "**************************************" << endl;

    // Read the first matrix from file
    Matrix m3;
    m3.inputFileMatrix("input3.txt");
    m3.displayMatrix();
    cout << "**************************************" << endl;
 
    // Read the second matrix from file
    Matrix m4;
    m4.inputFileMatrix("input4.txt");
    m4.displayMatrix();
    cout << "**************************************" << endl;
    // Read the second matrix from file
    Matrix m5;
    m5.inputFileMatrix("input1X.txt");
    m5.displayMatrix();
    cout << "**************************************" << endl;
    // Read the second matrix from file
    Matrix m6;
    m6.inputFileMatrix("input3X.txt");
    m6.displayMatrix();
    cout << "**************************************" << endl;

    // // Addition
    // cout << "Addition Result:" << endl;
    // Matrix sumMatrix = m1.AddMatrix(m2);
    // sumMatrix.displayMatrix();
    // cout << "**************************************" << endl;

    // // Subtraction
    // cout << "Subtraction Result:" << endl;
    // Matrix subMatrix = m1.SubMatrix(m2);
    // subMatrix.displayMatrix();
    // cout << "**************************************" << endl;

    // // Multiplication
    // cout << "Multiplication Result:" << endl;
    // Matrix mulMatrix = m1.MultMatrix(m2);
    // mulMatrix.displayMatrix();
    // cout << "**************************************" << endl;

    // // Check if the matrices are diagonal
    // cout << "Checking if matrices are diagonal:" << endl;
    // cout << "Matrix 1: " << (m1.isDiagonal() ? "Diagonal" : "Not Diagonal") << endl;
    // // cout << "Matrix 2: " << (m2.isDiagonal() ? "Diagonal" : "Not Diagonal") << endl;
    // cout << "**************************************" << endl;

    // // Check if the matrices are Identity
    // cout << "Checking if matrices is Identity:" << endl;
    // cout << "Matrix 1: " << (m1.isIdentity() ? "Identity" : "Not Identity") << endl;
    // // cout << "Matrix 2: " << (m2.isIdentity() ? "Identity" : "Not Identity") << endl;
    
    cout << "**************************************" << endl;
    cout << "A and A~ Upper Triangular " << endl;
    cout << "**************************************" << endl;

    // gausss Elimination
    cout << "Gaussian Elimination Result:" << endl;
    Matrix gaussMatrix = m5.GaussElimination();
    gaussMatrix.displayMatrix();
    
    // gausss Elimination
    cout << "Gaussian Elimination Result:" << endl;
    Matrix gaussMatrix3 = m6.GaussElimination();
    gaussMatrix3.displayMatrix();
    
    cout << "**************************************" << endl;
    cout << "Ax = b" << endl;
    cout << "**************************************" << endl;

    // inverse of Matrix
    cout << "Inverse Matrix Result:" << endl;
    Matrix inverseMatrix = m1.InverseMatrix();
    inverseMatrix.displayMatrix();

    // determinant of matrix
    cout << "Determinant of Matrix 1: " << m1.DeterminantMatrix() << endl;
    cout << "Determinant of Matrix 2: " << m3.DeterminantMatrix() << endl;

    // Multiplication
    cout << "Multiplication Result: A-1 * b" << endl;
    Matrix mulMatrix1 = inverseMatrix.MultMatrix(m2);
    mulMatrix1.displayMatrix();

    // Multiplication
    cout << "Multiplication Result:" << endl;
    Matrix mulMatrix2 = m1.MultMatrix(mulMatrix1);
    mulMatrix2.displayMatrix();

    cout << "**************************************" << endl;
    cout << "A~x = b" << endl;
    cout << "**************************************" << endl;

    // inverse of Matrix
    cout << "Inverse Matrix Result:" << endl;
    Matrix inverseMatrix3 = m3.InverseMatrix();
    inverseMatrix3.displayMatrix();

    // Multiplication
    cout << "Multiplication Result:" << endl;
    Matrix mulMatrix3 = inverseMatrix3.MultMatrix(m2);
    mulMatrix3.displayMatrix();

    // Multiplication
    cout << "Multiplication Result:" << endl;
    Matrix mulMatrix4 = m3.MultMatrix(mulMatrix3);
    mulMatrix4.displayMatrix();

    cout << "**************************************" << endl;
    cout << "Ax = b~" << endl;
    cout << "**************************************" << endl;

    // Multiplication
    cout << "Multiplication Result:" << endl;
    Matrix mulMatrix5 = inverseMatrix.MultMatrix(m4);
    mulMatrix5.displayMatrix();

    // Multiplication
    cout << "Multiplication Result:" << endl;
    Matrix mulMatrix6 = m3.MultMatrix(mulMatrix5);
    mulMatrix6.displayMatrix();

    cout << "**************************************" << endl;
    cout << "End" << endl;
    cout << "**************************************" << endl;

    return 0;
}

/*
1 Read Matrix From file
2 Addition of Two Matrix
3 Substraction of Two Matrix
4 Multiplication of Two Matrix
5 is Diagonal
6 is Identity
7 Gausian Elimination Matrix
8 Back substitution
9 Find Inverse of Matrix
10 Find Determinant of Matrix

*/