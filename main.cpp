#include "Matrix.hpp"

int main()
{
    // Read the first matrix from file
    Matrix m1;
    m1.inputFileMatrix("input1.txt");
    m1.displayMatrix();

    // Read the second matrix from file
    Matrix m2;
    m2.inputFileMatrix("input2.txt");
    m2.displayMatrix();

    // Addition
    cout << "Addition Result:" << endl;
    Matrix sumMatrix = m1.AddMatrix(m2);
    sumMatrix.displayMatrix();

    // Subtraction
    cout << "Subtraction Result:" << endl;
    Matrix subMatrix = m1.SubMatrix(m2);
    subMatrix.displayMatrix();

    // Multiplication
    cout << "Multiplication Result:" << endl;
    Matrix mulMatrix = m1.MultMatrix(m2);
    mulMatrix.displayMatrix();

    // Check if the matrices are diagonal
    cout << "Checking if matrices are diagonal:" << endl;

    cout << "Matrix 1: " << (m1.isDiagonal() ? "Diagonal" : "Not Diagonal") << endl;
    cout << "Matrix 2: " << (m2.isDiagonal() ? "Diagonal" : "Not Diagonal") << endl;

    // Check if the matrices are Identity
    cout << "Checking if matrices is Identity:" << endl;

    cout << "Matrix 1: " << (m1.isIdentity() ? "Identity" : "Not Identity") << endl;
    cout << "Matrix 2: " << (m2.isIdentity() ? "Identity" : "Not Identity") << endl;

    // gausss Elimination
    cout << "Gaussian Elimination Result:" << endl;
    Matrix gaussMatrix = m1.GaussElimination();
    gaussMatrix.displayMatrix();

    // Lower Triangular
    cout << "Lower Triangular Matrix Result:" << endl;
    Matrix lowerTriangular = m1.LowerTriangular();
    lowerTriangular.displayMatrix();
    
    // Upper Triangular
    cout << "Upper Triangular Matrix Result:" << endl;
    Matrix upperTriangular = m1.UpperTriangular();
    upperTriangular.displayMatrix();

    return 0;
}
