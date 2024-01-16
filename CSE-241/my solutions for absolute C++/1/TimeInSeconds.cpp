#include <iostream>
using namespace std;

int main(){
    int hours,      // OUT
        minutes,    // OUT
        seconds;    // IN - OUT

    cout << "Total seconds: ";
    cin >> seconds;

    hours = seconds / (60 * 60);
    seconds %= (60 * 60);

    minutes = seconds / 60;
    seconds %= 60;

    cout << hours << " hours, " << minutes << " minutes, " 
        << seconds <<" seconds.\n";
    return(0);
}