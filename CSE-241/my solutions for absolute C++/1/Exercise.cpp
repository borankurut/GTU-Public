#include <iostream>
using namespace std;

int main(){
    const double SPD_TO_MET = 10.0/6.0, // speed to met constant
                CALLORIES_CON = 0.0175; // constant in the callories formula

    const int FRST_DURATION = 3,    // first speed time interval
            NEXT_DURATION = 4,      // time interval between speed increase
            SPEED_INC = 2;          // increase speed by this amount

    double caloriesBurned = 0,
            met,
            weight;

    int curSpeed = 4;

    cout << "Enter your weight(kg)\n>";
    cin >> weight;   

    // time interval: 0 - 3
    met = curSpeed * SPD_TO_MET;
    caloriesBurned += FRST_DURATION * (CALLORIES_CON * met * weight);

    // time interval: 3 - 7
    curSpeed += SPEED_INC;
    met = curSpeed * SPD_TO_MET;
    caloriesBurned += NEXT_DURATION * (CALLORIES_CON * met * weight);

    // time interval: 7 - 11
    curSpeed += SPEED_INC;
    met = curSpeed * SPD_TO_MET;
    caloriesBurned += NEXT_DURATION * (CALLORIES_CON * met * weight);

    // time interval: 7 - 15
    curSpeed += SPEED_INC;
    met = curSpeed * SPD_TO_MET;
    caloriesBurned += NEXT_DURATION * (CALLORIES_CON * met * weight);

    cout << "Burned calories: " << caloriesBurned << endl;

    return(0);
}