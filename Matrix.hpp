
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
    Matrix MultMatrix(const Matrix &mat);
    Matrix SubMatrix(const Matrix &mat);
    
    Matrix GaussElimination();
    
    bool isDiagonal();
    bool isIdentity();
    void displayMatrix();
};
