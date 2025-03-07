#include <fstream>
#include <iostream>
#include "Matrix.hpp"
#include <math.h>
#include <iomanip>

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
    if (cols != mat.rows)
    {
        cerr << "Error: Matrices cannot be multiplied, incompatible dimensions!" << endl;
        return Matrix(); // Return an empty matrix
    }

    Matrix result(rows, mat.cols); // Create result matrix of size (rows x mat.cols)

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < mat.cols; j++)
        {
            result.data[i][j] = 0; // Initialize result cell
            for (int k = 0; k < cols; k++) // Multiply row elements by column elements
            {
                result.data[i][j] += this->data[i][k] * mat.data[k][j];
            }
        }
    }

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

    if (obj1.cols != n + 1)  // Ensure it's an augmented matrix (n equations, n+1 columns)
    {
        throw std::invalid_argument("Matrix must be augmented (n x (n+1))");
    }

    // Forward elimination (Convert to upper triangular form)
    for (int i = 0; i < n; i++)
    {
        int maxIndex = i;

        // Partial Pivoting: Find the row with the maximum absolute value in column i
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(obj1.data[k][i]) > fabs(obj1.data[maxIndex][i]))
            {
                maxIndex = k;
            }
        }

        // Swap rows if needed
        if (maxIndex != i)
        {
            std::swap(obj1.data[i], obj1.data[maxIndex]);
        }

        // Check for singular matrix
        if (fabs(obj1.data[i][i]) < 1e-9)
        {
            throw std::runtime_error("Singular matrix detected! No unique solution.");
        }

        // Normalize pivot row
        for (int j = i + 1; j < obj1.cols; j++)
        {
            obj1.data[i][j] /= obj1.data[i][i];
        }
        obj1.data[i][i] = 1;  // Set leading coefficient to 1

        // Eliminate column values below the pivot
        for (int k = i + 1; k < n; k++)
        {
            double factor = obj1.data[k][i];

            for (int j = i; j < obj1.cols; j++)
            {
                obj1.data[k][j] -= factor * obj1.data[i][j];
            }
        }
    }

    // Back-substitution to find the solution
    Matrix result(n, 1);  // Solution vector

    for (int i = n - 1; i >= 0; i--)
    {
        result.data[i][0] = obj1.data[i][n];  // Start with augmented column

        for (int j = i + 1; j < n; j++)
        {
            result.data[i][0] -= obj1.data[i][j] * result.data[j][0];
        }
    }

    return result;  // Returns solution vector
}

Matrix Matrix::InverseMatrix()
{
    if (rows != cols)
    {
        cerr << "Error: Matrix must be square for inversion!" << endl;
        return Matrix(); // Return empty matrix
    }

    int n = rows;
    Matrix augmented(n, 2 * n);

    // Create Augmented Matrix [A | I]
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            augmented.data[i][j] = this->data[i][j]; // Copy original matrix

        for (int j = 0; j < n; j++)
            augmented.data[i][j + n] = (i == j) ? 1 : 0; // Identity matrix
    }

    // Apply Gaussian Elimination
    for (int i = 0; i < n; i++)
    {
        // Find the maximum pivot
        int pivotRow = i;
        for (int j = i + 1; j < n; j++)
        {
            if (fabs(augmented.data[j][i]) > fabs(augmented.data[pivotRow][i]))
                pivotRow = j;
        }

        // Swap rows if needed
        if (i != pivotRow)
            swap(augmented.data[i], augmented.data[pivotRow]);

        // Check if matrix is singular
        if (fabs(augmented.data[i][i]) < 1e-9)
        {
            cerr << "Error: Matrix is singular and cannot be inverted!" << endl;
            return Matrix();
        }

        // Normalize the pivot row
        double pivot = augmented.data[i][i];
        for (int j = 0; j < 2 * n; j++)
            augmented.data[i][j] /= pivot;

        // Eliminate the column
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                double factor = augmented.data[j][i];
                for (int k = 0; k < 2 * n; k++)
                    augmented.data[j][k] -= factor * augmented.data[i][k];
            }
        }
    }

    // Extract inverse matrix from the right side
    Matrix inverse(n, n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            inverse.data[i][j] = augmented.data[i][j + n];

    return inverse;
}

double Matrix::DeterminantMatrix()
{
    if (rows != cols)
    {
        cerr << "Error: Determinant can only be computed for square matrices!" << endl;
        return 0.0;
    }

    int n = rows;
    Matrix temp(*this);
    double det = 1.0;

    for (int i = 0; i < n; i++)
    {
        int maxIndex = i;
        for (int k = i + 1; k < n; k++)
        {
            if (fabs(temp.data[k][i]) > fabs(temp.data[maxIndex][i]))
            {
                maxIndex = k;
            }
        }

        if (fabs(temp.data[maxIndex][i]) < 1e-9)
            return 0.0;

        // Swap rows if needed
        if (maxIndex != i)
        {
            swap(temp.data[i], temp.data[maxIndex]);
            det *= -1;
        }

        det *= temp.data[i][i];

        for (int k = i + 1; k < n; k++)
        {
            double factor = temp.data[k][i] / temp.data[i][i];
            for (int j = i; j < n; j++)
            {
                temp.data[k][j] -= factor * temp.data[i][j];
            }
        }
    }

    return det;
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

