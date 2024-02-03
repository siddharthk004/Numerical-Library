#include "./cmplx.hpp"
#include "math.h"

cmplx::cmplx()
{
    real = 0.0;
    img = 0.0;
}
cmplx::cmplx(double x, double y)
{
    real = x;
    img = y;
}

cmplx cmplx::add(cmplx addV)
{
    cmplx temp;
    temp.real = real + addV.real;
    temp.img = img + addV.img;
    return temp; 
}
cmplx cmplx::sub(cmplx addV)
{
    cmplx temp;
    temp.real = real - addV.real;
    temp.img = img - addV.img;
    return temp; 
}
cmplx cmplx::mult(cmplx addV)
{
    cmplx temp;
    
    temp.real = (real*addV.real) - (img*addV.img);
    temp.img = (real*addV.img) + (img*addV.real);

    return temp; 
}
cmplx cmplx::div(cmplx addV)
{
    cmplx temp;
    double ans;
    temp.real = (real*addV.real) + (img*addV.img);
    temp.img = (img*addV.real) - (real*addV.img);

    ans = addV.real*addV.real + addV.img*addV.img;
    temp.real = temp.real / ans;
    temp.img = temp.img / ans;
    return temp; 
}

void cmplx::display()
{
    std::cout << real << " + " << img << "i \n" << std::endl;
}

double cmplx::norm()
{
    return (sqrt((this->real*this->real) + (this->img*this->img)));
}


void cmplx::complexConjugate()
{
    std::cout << real << " - " << img << "i \n" << std::endl;
}