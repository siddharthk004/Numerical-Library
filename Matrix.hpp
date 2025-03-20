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

    void inputFileMatrix(const std::string File);

    Matrix AddMatrix(const Matrix &mat);
    Matrix MultMatrix(const Matrix &mat);
    Matrix SubMatrix(const Matrix &mat);

    double func(int row, double x, double y, int a, int b);

    Matrix GaussElimination(const Matrix &mat);
    Matrix UpperMatrix();
    Matrix LowerMatrix();

    Matrix DolittleLU();
    void GaussJacobi();
    void GaussSeidal();

    Matrix MakeDominant();
    void IterativeMethod();
    void IterativeMethodS();
    bool isDiagonal();
    bool isIdentity();
    void displayMatrix();
    double DeterminantMatrix();
    Matrix InverseMatrix();
};
