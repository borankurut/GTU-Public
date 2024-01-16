#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>

using namespace std;

class Complex{
public:
    Complex(double newReal, double newImaginary);
    Complex(double newReal);
    Complex();

    double real() const{return re;}
    double imag() const{return im;}

    friend double imag(const Complex &complex);
    friend double real(const Complex &complex);
    friend bool operator ==(const Complex &op1, const Complex &op2);
    friend const Complex operator +(const Complex &op1, const Complex &op2);
    friend const Complex operator -(const Complex &op1, const Complex &op2);
    friend const Complex operator *(const Complex &op1, const Complex &op2);
    friend const Complex operator /(const Complex &op1, double op2);
    friend istream& operator >>(istream &inputStream, Complex &op);
    friend ostream& operator <<(ostream &outputStream, const Complex &op);
    

private:
    double  re,
            im;    
};

const Complex i(0.0, 1.0);

#endif