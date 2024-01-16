#include <iostream>
using namespace std;

int main(){
    double toReceive,       // IN - amount of money costumer needs to receive
            interestRate,   // IN
            faceValue,      // OUT - face value required in order for the consumer to
                            // receive the amount needed.
            monthlyPayment, // OUT

            durationYear;   // duration in year

    int duration;           // IN - duration of the loan (in months)

    cout << "Enter the amount of money costumer needs to receive\n$";
    cin >> toReceive;

    cout << "Enter the interest rate\n%";
    cin >> interestRate;

    cout << "Enter the duration of the loan (in months)\n>";
    cin >> duration;

    interestRate /= 100.0;
    durationYear = static_cast<double>(duration) / 12.0;

    faceValue = toReceive / (1 - interestRate * durationYear);
    monthlyPayment = faceValue / static_cast<double>(duration);

    cout << "Face value: " << faceValue << endl;
    cout << "Monthly payment: " << monthlyPayment << endl;

    return(0);
}
