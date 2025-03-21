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
    void GaussSeidal();
    void IterativeMethod();
    void IterativeMethodS();
    void displayMatrix();
    void inputFileMatrix(const std::string File);
    double func(int row, double x, double y, int a, int b);
    double DeterminantMatrix();
};
