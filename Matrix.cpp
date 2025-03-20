#include <fstream>
#include <iostream>
#include "Matrix.hpp"
#include <math.h>
#include <iomanip>
#include "Function/polynomial.hpp"

using namespace std;

Matrix::Matrix()
{
    rows = 0;
    cols = 0;
}

Matrix::Matrix(int r, int c) : rows(r), cols(c), data(r, vector<double>(c, 0))
{
}

Matrix::Matrix(const Matrix &mat) : rows(mat.rows), cols(mat.cols), data(mat.data)
{
}

Matrix::~Matrix()
{
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

    // Update matrix dimensions
    rows = newRows;
    cols = newCols;

    // Resize the vector with zero-initialization
    data.resize(rows, vector<double>(cols, 0.0));

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
            result.data[i][j] = 0;         // Initialize result cell
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

Matrix Matrix::GaussElimination(const Matrix &mat)
{
    if (rows != mat.rows || mat.cols != 1)
    {
        cerr << "Error: Augment matrix must have the same number of rows and exactly one column." << endl;
        return *this;
    }

    // Augment the matrix
    Matrix obj1(*this); // Copy current matrix

    obj1.cols += 1; // Increase column count

    for (int i = 0; i < rows; i++)
    {
        // Check if row size is as expected before augmentation
        if (obj1.data[i].size() == obj1.cols - 1)
        {
            obj1.data[i].push_back(mat.data[i][0]); // Append column
        }
        else
        {
            cerr << "Error: Row " << i << " has unexpected size! Expected " << obj1.cols - 1 << ", got " << obj1.data[i].size() << endl;
            return *this;
        }
    }

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
            std::swap(obj1.data[i], obj1.data[maxIndex]);
        }

        if (fabs(obj1.data[i][i]) < 1e-9)
        {
            obj1;
        }

        for (int j = i + 1; j < obj1.cols; j++)
        {
            obj1.data[i][j] /= obj1.data[i][i];
        }

        obj1.data[i][i] = 1;

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
    Matrix result(n, 1);

    for (int i = n - 1; i >= 0; i--)
    {
        result.data[i][0] = obj1.data[i][n];

        for (int j = i + 1; j < n; j++)
        {
            result.data[i][0] -= obj1.data[i][j] * result.data[j][0];
        }
    }

    return result;
}

Matrix Matrix::UpperMatrix()
{
    Matrix U(*this);

    int n = U.rows;

    for (int i = 0; i < n; i++)
    {
        if (fabs(U.data[i][i]) < 1e-9)
        {
            throw std::runtime_error("LU decomposition is not possible (zero pivot detected).");
        }

        for (int k = i + 1; k < n; k++)
        {
            double factor = U.data[k][i] / U.data[i][i];

            for (int j = i; j < U.cols; j++)
            {
                U.data[k][j] -= factor * U.data[i][j];
            }
        }
    }

    return U;
}

Matrix Matrix::LowerMatrix()
{
    int n = rows;
    Matrix L(n, n);

    for (int i = 0; i < n; i++)
    {
        L.data[i][i] = 1;

        for (int k = i + 1; k < n; k++)
        {
            if (fabs(data[i][i]) < 1e-9)
            {
                throw std::runtime_error("LU decomposition is not possible (zero pivot detected).");
            }

            L.data[k][i] = data[k][i] / data[i][i]; // Store elimination factor
        }
    }
    return L;
}

Matrix Matrix::DolittleLU()
{
    Matrix U(*this);

    int n = U.rows;

    for (int i = 0; i < n; i++)
    {
        if (fabs(U.data[i][i]) < 1e-9)
        {
            throw std::runtime_error("LU decomposition is not possible (zero pivot detected).");
        }

        for (int k = i + 1; k < n; k++)
        {
            double factor = U.data[k][i] / U.data[i][i];

            for (int j = i; j < U.cols; j++)
            {
                U.data[k][j] -= factor * U.data[i][j];
            }
        }
    }

    n = rows;
    Matrix L(n, n);

    for (int i = 0; i < n; i++)
    {
        L.data[i][i] = 1;

        for (int k = i + 1; k < n; k++)
        {
            if (fabs(data[i][i]) < 1e-9)
            {
                throw std::runtime_error("LU decomposition is not possible (zero pivot detected).");
            }

            L.data[k][i] = data[k][i] / data[i][i]; // Store elimination factor
        }
    }
    Matrix ans = L.MultMatrix(U);
    return ans;
}

Matrix Matrix::MakeDominant()
{
    Matrix dominantMatrix(*this);
    int n = rows;

    std::vector<bool> used(n, false); // Track used rows
    Matrix newMat(n, cols);

    for (int i = 0; i < n; i++)
    {
        int bestRow = -1;

        for (int j = 0; j < n; j++)
        {
            if (!used[j])
            {
                double diag = fabs(data[j][i]);
                double rowSum = 0.0;

                for (int k = 0; k < n; k++)
                {
                    if (k != i)
                    {
                        rowSum += fabs(data[j][k]);
                    }
                }

                if (diag >= rowSum)
                {
                    bestRow = j;
                    break;
                }
            }
        }

        if (bestRow == -1)
        {
            throw std::runtime_error("Cannot rearrange matrix into a diagonally dominant form.");
        }

        newMat.data[i] = data[bestRow]; // Assign row
        used[bestRow] = true;
    }

    return newMat;
}

void Matrix::GaussJacobi()
{
    Matrix obj1(*this);
    // Matrix ans = obj1.MakeDominant();
    if (1)
    {
        std::cout << "The given matrix is dominant." << std::endl;
        obj1.IterativeMethod();
    }
}

void Matrix::GaussSeidal()
{
    Matrix obj1(*this);
    // Matrix ans = obj1.MakeDominant();
    if (1)
    {
        std::cout << "The given matrix is dominant." << std::endl;
        obj1.IterativeMethodS();
    }
}

double Matrix::func(int row, double x, double y, int a, int b)
{
    Matrix obj1(*this);
    return ((obj1.data[row][3]) + (-1 * obj1.data[row][a] * x) + (-1 * obj1.data[row][b] * y)) / obj1.data[row][row];
}

void Matrix::IterativeMethodS()
{
    Matrix obj1(*this);
    double tolerance = 0.00001;
    double a = 0.0, x, y, z;
    double b = 0.0;
    double c = 0.0;
    int itr = 0;
    while (itr < 20)
    {
        x = obj1.func(0, b, c, 1, 2);
        y = obj1.func(1, x, c, 0, 2);
        z = obj1.func(2, x, y, 0, 1);

        double ans = a - x;

        if (ans < 0)
        {
            if ((ans * -1) <= tolerance)
                break;
        }
        else if ((ans) <= tolerance)
            break;

        cout << "Iteration " << itr << ": (" << a << ", " << b << ", " << c << ")" << endl;

        // a = x;
        b = y;
        c = z;

        itr++;
    }
}

void Matrix::IterativeMethod()
{
    Matrix obj1(*this);

    double tolerance = 0.00001;
    double a = 0.0, y, x, z;
    double b = 0.0;
    double c = 0.0;
    int itr = 0;
    for (int i = 1; i < 20; i++)
    {
        x = obj1.func(0, b, c, 1, 2);
        y = obj1.func(1, a, c, 0, 2);
        z = obj1.func(2, a, b, 0, 1);

        double ans = a - x;

        if (ans < 0)
        {
            if ((ans * -1) <= tolerance)
                break;
        }
        else if ((ans) <= tolerance)
            break;

        cout << "Iteration " << itr << ": (" << a << ", " << b << ", " << c << ")" << endl;

        a = x;
        b = y;
        c = z;

        itr++;
    }
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

    // augmented Matrix
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            augmented.data[i][j] = this->data[i][j]; // Copy original matrix

        for (int j = 0; j < n; j++)
            augmented.data[i][j + n] = (i == j) ? 1 : 0;
    }

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
