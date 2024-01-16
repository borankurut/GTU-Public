#include <iostream>
using namespace std;

int main(){
    const double GAL_TO_ML = 3785.41;

    double  milkVolume,
            milkInGal;

    int packets;

    cout << "Enter the volume of a package of milk (ml)\n>";
    cin >> milkVolume;

    milkInGal = milkVolume / GAL_TO_ML;
    packets = milkInGal;

    cout << "volume in gallons: " << milkInGal << " packets needed: " << packets << endl;


    return(0);
}