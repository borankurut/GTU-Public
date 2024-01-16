#include <iostream>
using namespace std;

int main(){
    double maxCap,      // IN - truck's maximum load capacity (in metric tons)
            avWghtBox,  // IN - average weight of a box (kg)
            curLoad;    // truck's current load

    int nmbBox;         // IN - number of boxes truck is carrying

    cout << "Enter the max load capacity of truck (in metric tons)\n>";
    cin >> maxCap;
    maxCap *= 1000; // metric tons to kg

    cout << "Enter the number of boxes\n>";
    cin >> nmbBox;

    cout << "Enter the average weight of a box (kg)\n>";
    cin >> avWghtBox;

    curLoad = static_cast<double>(nmbBox) * avWghtBox;

    if(curLoad <= maxCap){
        int toAdd = (maxCap - curLoad) / static_cast<double>(nmbBox);
        
        cout << "Truck can legally carry all boxes " 
            << "with additional " << toAdd << " box(es)" << endl;
    }
    else{
        int toRemove = 1 + (curLoad - maxCap) / static_cast<double>(nmbBox);
        
        cout << "Truck is overloaded, " << toRemove 
        << " amount of box(es) should be removed." << endl;
    }

    return(0);
}