#include <iostream>
#include "complex.h" // complex class

using namespace std;

//constructors
Complex::Complex(double newReal, double newImaginary): 
                re(newReal), im(newImaginary){/*empty*/}   

Complex::Complex(double newReal): 
                re(newReal), im(0){/*empty*/}

Complex::Complex(): re(0), im(0){/*empty*/}

double imag(const Complex &complex){return complex.im;}
double real(const Complex &complex){return complex.re;}

bool operator ==(const Complex &op1, const Complex &op2){
    return(op1.re == op2.re && op2.im == op2.im);
}

const Complex operator +(const Complex &op1, const Complex &op2){
    return Complex(op1.re + op2.re, op1.im + op2.im); // complex addition
}

const Complex operator -(const Complex &op1, const Complex &op2){
    return Complex(op1.re - op2.re, op1.im + op2.im); //complex subtraction
}

// comples multiplication
const Complex operator *(const Complex &op1, const Complex &op2){
    return Complex( op1.re * op2.re - op1.im * op2.im,    //ac - bd
                    op1.re * op2.im + op1.im * op2.re);   //ad + bc
}

const Complex operator /(const Complex &op1, double op2){
    return Complex(op1.re / op2, op1.im / op2); //complex division by double
}

istream& operator >>(istream &inputStream, Complex &op){
    char ch;
    double r, i;

    inputStream >> ch;

    if(ch != '('){  //bracket
        cout << "Bad complex form found.\n";
        exit(1);
    }
    inputStream >> r;   // take real part
    inputStream >> ch;  //comma
    if(ch != ','){
        cout << "Bad complex form found.\n";
        exit(1);
    }

    inputStream >> i;   // take imaginary part
    
    inputStream >> ch;  //bracket

    if(ch != ')'){      
        cout << "Bad complex form found.\n";
        exit(1);
    }

    op = Complex(r, i);

    return(inputStream);
}

ostream& operator <<(ostream &outputStream, const Complex &op){
    cout << "(" << op.re << "," << op.im << ")";
    return(outputStream);
}