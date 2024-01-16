#include <iostream>
#include "complex.h"

using namespace std;

int main(){
    Complex x, y(3), z(-3.2, 2.1);
    cout << "x = " << x << " y = " << y << " z = " << z << endl;
    x = Complex(3, -4);

    cout << "testing members and support functions as well as"
    <<      " output operator:\n"
    <<      "complex number x = " << x << endl
    <<      "real part: " << x.real() << endl
    <<      "real part from friend real(x): " << real(x) << endl
    <<      "imaginary part: " << x.imag() << endl
    <<      "imaginary part from friend imag(x) : " << imag(x) <<endl;

    return 0;
}