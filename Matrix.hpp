
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include <iostream>
#include <vector>
using namespace std;

class Matrix
{
public:
    int rows, cols;
    vector<vector<double>> data;

    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix &mat);
    ~Matrix();

    Matrix AddMatrix(const Matrix &mat);
    Matrix MultMatrix(const Matrix &mat);
    Matrix SubMatrix(const Matrix &mat);
    Matrix GaussElimination(const Matrix &mat);
    Matrix UpperMatrix();
    Matrix LowerMatrix();
    Matrix DolittleLU();
    Matrix MakeDominant();
    Matrix InverseMatrix();

    bool isDiagonal();
    bool isIdentity();
    bool IsDominant();
    void GaussJacobi();
    void GaussSeidel();
    void displayMatrix();
    void IterativeMethod();
    void IterativeMethodS();
    double DeterminantMatrix();
    void inputFileMatrix(const std::string File);
    double func(int row, const vector<double> &prevVariables);
    std::vector<double> &operator[](int index)
    {
        return data[index];
    }
    const std::vector<double> &operator[](int index) const
    {
        return data[index];
    }
    int size() const;
};

#endif