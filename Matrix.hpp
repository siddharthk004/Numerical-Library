
#include <iostream>
using namespace std;

class Matrix
{
public:
    int rows, cols;
    double **data;

    Matrix();
    Matrix(int r, int c);
    Matrix(const Matrix &mat);
    ~Matrix();
    void inputFileMatrix(const std::string File);
    Matrix AddMatrix(const Matrix &mat);
    Matrix GaussElimination();
    Matrix SubMatrix(const Matrix &mat);
    bool isDiagonal();
    bool isIdentity();
    void displayMatrix();
};
