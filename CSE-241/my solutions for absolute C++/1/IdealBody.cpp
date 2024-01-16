#include <iostream>
using namespace std;

int main(){

    const int FT_TO_INC = 12;       // feet to inch
    const int FST_HGH = 5;          // first height for the first weight in feet
    const int FST_WGH = 110;        // first weight for the first height in pounds
    const int ADD_POUNDS = 5;       // additional pounds for each additional inch

    int heightFt,       // IN - height of the person in feet
        additInc,       // IN - additional inches
        idealBw,        // OUT - ideal body weight
        totalHghInc;    // total height of the person excluding FST_HGH in inches.

    cout << "Enter the height in feet\n>";
    cin >> heightFt;
    cout << "Enter the additional inches\n>";    
    cin >> additInc;

    totalHghInc = (heightFt - FST_HGH) * FT_TO_INC;
    totalHghInc += additInc;

    idealBw = ADD_POUNDS * totalHghInc + FST_WGH;
    
    cout << "Your ideal body weight is: " << idealBw << endl;

    return(0);
}