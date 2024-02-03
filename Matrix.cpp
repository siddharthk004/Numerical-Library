#include "Matrix.hpp"

Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;

    data = new int *[rows];
    for (int i = 0; i < rows; ++i)
        data[i] = new int[cols];
}

Matrix::~Matrix()
{
    for (int i = 0; i < rows; ++i)
        delete[] data[i];
    delete[] data;
}

void Matrix::inputMatrix(Matrix &mat)
{
    cout << "Enter elements for matrix 1: " << endl;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            cin >> mat.data[i][j];
}

void Matrix::displayMatrix(Matrix &mat)
{
    cout << "Matrix 1: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << mat.data[i][j] << " ";
        cout << endl;
    }
}
void Matrix::GaussElimination(Matrix &mat)
{
    
}
