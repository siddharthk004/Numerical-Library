
#include <iostream>
using namespace std;

class Matrix
{
public:
    int rows, cols;
    int **data;

    Matrix(int r, int c);
    ~Matrix();
    void inputMatrix(Matrix &mat);
    void displayMatrix(Matrix &mat);
    void GaussElimination(Matrix &mat);
    
};
