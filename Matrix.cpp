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

Matrix Matrix::MultMatrix(const Matrix &mat)
{
    if (rows != mat.rows || cols != mat.cols)
    {
        cerr << "Error: Matrices must have the same dimensions for subtraction!" << endl;
        return Matrix(); // Return empty matrix
    }

    Matrix result(rows, cols);
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            for (int k = 0; k < cols; k++)
                result.data[i][j] = this->data[j][k] * mat.data[k][j];

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
    Matrix obj1(*this);
    int n = obj1.rows;

    for (int i = 0; i < n; i++)
    {
        int maxIndex = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(obj1.data[k][i]) > fabs(obj1.data[maxIndex][i]))
            {
                maxIndex = k;
            }
        }

        if (maxIndex != i)
        {
            if (i < 0 || i >= obj1.rows || maxIndex < 0 || maxIndex >= obj1.rows)
            {
                throw std::out_of_range("Row indices out of range");
            }
            swap(obj1.data[i], obj1.data[maxIndex]);
        }

        if (fabs(obj1.data[i][i]) < 1e-9)
        {
            std::cerr << "Error: Singular matrix detected!" << std::endl;
            return Matrix(0, 0);
        }

        for (int k = i + 1; k < n; k++)
        {
            double factor = obj1.data[k][i] / obj1.data[i][i];
            for (int j = i; j < obj1.cols; j++)
            {
                obj1.data[k][j] -= factor * obj1.data[i][j];
            }
        }
    }

    // Back-substitution
    Matrix result(n, 1);
    for (int i = n - 1; i >= 0; i--)
    {
        result.data[i][0] = obj1.data[i][n] / obj1.data[i][i];
        for (int j = i - 1; j >= 0; j--)
        {
            obj1.data[j][n] -= obj1.data[j][i] * result.data[i][0];
        }
    }

    return result;
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
