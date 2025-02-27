#include <fstream>
#include <iostream>
#include "Matrix.hpp"
#include <math.h>

using namespace std;

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
    data = nullptr;
}

Matrix::Matrix(int r, int c)
{
    rows = r;
    cols = c;
    data = new double *[rows];
    for (int i = 0; i < rows; ++i)
    {
        data[i] = new double[cols](); // Ensure values are initialized
    }
}

Matrix::Matrix(const Matrix &mat)
{
    rows = mat.rows;
    cols = mat.cols;
    data = new double *[rows];

    for (int i = 0; i < rows; ++i)
    {
        data[i] = new double[cols];
        for (int j = 0; j < cols; ++j)
        {
            data[i][j] = mat.data[i][j];
        }
    }
}

Matrix::~Matrix()
{
    if (data)
    {
        for (int i = 0; i < rows; ++i)
        {
            if (data[i] != nullptr) // Check if row is allocated
                delete[] data[i];
        }
        delete[] data;
        data = nullptr; // Prevent dangling pointer
    }
}

void Matrix::inputFileMatrix(const std::string File)
{
    ifstream inputFile(File);

    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open input file!" << endl;
        return;
    }

    int newRows, newCols;
    inputFile >> newRows >> newCols;

    // Free old memory safely
    if (data)
    {
        for (int i = 0; i < rows; ++i)
            delete[] data[i];
        delete[] data;
        data = nullptr;
    }

    // Update matrix dimensions
    rows = newRows;
    cols = newCols;

    // Allocate memory with zero initialization
    data = new double *[rows];
    for (int i = 0; i < rows; ++i)
    {
        data[i] = new double[cols](); // Initialize all elements to 0
    }

    // Read matrix values from the file
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (!(inputFile >> data[i][j]))
            {
                cerr << "Error: Not enough data in input file!" << endl;
                inputFile.close();
                return;
            }
        }
    }

    inputFile.close();
    cout << "Matrix read from file successfully!" << endl;
}

Matrix Matrix::AddMatrix(const Matrix &mat)
{
    if (rows != mat.rows || cols != mat.cols)
    {
        cerr << "Error: Matrices must have the same dimensions for addition!" << endl;
        return Matrix(0, 0); // Explicitly return a properly allocated empty matrix
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = this->data[i][j] + mat.data[i][j];

    return result;
}

Matrix Matrix::SubMatrix(const Matrix &mat)
{
    if (rows != mat.rows || cols != mat.cols)
    {
        cerr << "Error: Matrices must have the same dimensions for subtraction!" << endl;
        return Matrix(); // Return empty matrix
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result.data[i][j] = this->data[i][j] - mat.data[i][j];

    return result;
}

bool Matrix::isDiagonal()
{
    if (rows != cols)
        return false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i != j && data[i][j] != 0)
            {
                return false;
            }
        }
    }
    return true;
}
bool Matrix::isIdentity()
{
    if (rows != cols)
        return false;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (i == j && data[i][j] != 1)
            {
                return false;
            }
        }
    }
    return true;
}
Matrix Matrix::GaussElimination()
{
    Matrix A(*this);
    int n = A.rows;

    for (int i = 0; i < n; i++)
    {
        // Pivot row selection
        int maxIndex = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(A.data[k][i]) > fabs(A.data[maxIndex][i]))
            {
                maxIndex = k;
            }
        }

        // Swap rows if necessary
        if (maxIndex != i)
        {
            if (i < 0 || i >= rows || maxIndex < 0 || maxIndex >= rows)
            {
                throw out_of_range("Row indices out of range");
            }
            if (i != maxIndex)
            {
                for (int k = 0; k < cols; k++)
                {
                    swap(data[i][k], data[maxIndex][k]);
                }
            }
        }

        // Ensure pivot is nonzero
        if (fabs(A.data[i][i]) < 1e-9)
        {
            cerr << "Error: Singular matrix detected!" << endl;
            return Matrix(0, 0);
        }

        for (int k = i + 1; k < n; k++)
        {
            double factor = A.data[k][i] / A.data[i][i];
            for (int j = i; j < n; j++)
            {
                A.data[k][j] -= factor * A.data[i][j];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(i == j)
            {
                A.data[i][j] /= A.data[i][j]; 
            }
        }
    }

    return A;
}

void Matrix::displayMatrix()
{
    cout << "Matrix: " << endl;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            cout << data[i][j] << " ";
        cout << endl;
    }
}
