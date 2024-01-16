#include <iostream>
using namespace std;

int main(){
    const double FRST_KM = 2.0,     // first kilometers to be charged FRST_CHG
                FRST_CHG = 2.0,     // first charge for the first FRST_KM kilometers
                NEXT_KM = 6.0,      // next kilometers 
                NEXT_CHG = 0.50,    // next charge
                LAST_CHG = 1.0,     // last charge after first+next kilometers
                MNT_CHG = 0.2;      // charge based total travel duration (per minute)
    
    double km_travelled,    // IN - distance travelled
            time_passed,    // IN - time passed
            charge;         // OUT - computed charge

    cout << "Enter distance travelled(km)\n>";
    cin >> km_travelled;
    cout << "Enter time elapsed(minute)\n>";
    cin >> time_passed;
    
    charge = MNT_CHG * time_passed;

    if(km_travelled <= FRST_KM){
        charge += km_travelled * FRST_CHG;
    }
    else if(km_travelled <= FRST_KM + NEXT_KM){
        charge += FRST_KM * FRST_CHG;
        charge += (km_travelled - FRST_KM) * NEXT_CHG;
    }
    else{
        charge += FRST_KM * FRST_CHG;
        charge += NEXT_KM * NEXT_CHG;
        charge += (km_travelled - FRST_KM - NEXT_KM) * LAST_CHG;
    }

    cout << "Your total charge is: $" << charge << endl;

    return (0);
}