#include <iostream>
using namespace std;

int main(){
    const double SWT_PER_SODA = 0.001;  // Sweetener percentage in a soda

    double  swtKillMouse,   // Sweetener needed to kill the mouse
            swtKillDieter,  // Sweetener needed to kill the dieter
            weightMouse,    // Weight of the mouse
            weightDieter;   // Weight of the dieter

    int maxSoda;            // Maximum amount of soda dieter can drink without dying

    cout << "Enter the artificial sweetener needed to kill the mouse(?) \n>";
    cin >> swtKillMouse;
    cout << "Enter the weight of the mouse(kg) \n>";
    cin >> weightMouse;
    cout << "Enter the target weight of the dieter after diet(kg) \n>";
    cin >> weightDieter;

    swtKillDieter = (swtKillMouse / weightMouse) * weightDieter;
    maxSoda = (swtKillDieter / SWT_PER_SODA) - 1;

    cout << "The dieter can drink " << maxSoda 
    << " soda which contains less sweetener than " 
    << swtKillDieter << endl;
    

    return(0);
}