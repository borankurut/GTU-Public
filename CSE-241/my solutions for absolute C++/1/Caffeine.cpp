#include <iostream>
using namespace std;

int main(){

    const double OVERDOSE_CF = 10000.0;     // overdose of caffeine (mg)
    const double COLA_CF = 34.0 / 12.0;     // 12-ounce can of cola contains 34mg caffeine
    const double COFFEE_CF = 160.0 / 16.0;  // 16-ounce cup of coffee contains 160 mg caffeine

    int odCola,     // can of cola amount that is enough to overdose
        odCoffee;   // cup of coffee amount that is enough to overdose

    odCola = static_cast<int>(OVERDOSE_CF / COLA_CF + 0.5);
    odCoffee = static_cast<int>(OVERDOSE_CF / COFFEE_CF + 0.5);

    cout << odCola << "-ounce can of cola and " 
        << odCoffee << "-ounce cup of coffee can kill you.\n";

    return(0);
}