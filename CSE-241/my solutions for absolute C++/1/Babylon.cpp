#include <iostream>
using namespace std;

int main(){

    double n,
            guess,
            r;

    // magic formula 2 double precision
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    
    cout << "Enter the n: ";
    cin >> n;

    guess = n / 2.0;    // make guess

    // 1
    r = n / guess;
    guess = (guess + r) / 2.0;

    // 2
    r = n / guess;
    guess = (guess + r) / 2.0;

    // 3
    r = n / guess;
    guess = (guess + r) / 2.0;

    // 4
    r = n / guess;
    guess = (guess + r) / 2.0;

    // 5
    r = n / guess;
    guess = (guess + r) / 2.0;

    cout << "Final guess is: " << guess << endl;

    return(0);
}