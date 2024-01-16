#include <iostream>
#include "balrog.h"

using std::cout;
using std::endl;

namespace KurutRpg{
    Balrog::Balrog(): Demon(100, 150){/**/}
    Balrog::Balrog(int theStrength, int theHitpoints):
        Demon(theStrength, theHitpoints){/**/}

    int Balrog::getDamage() const{
        int first,
            second;
        
        cout << getSpecies() << "'s first attack:" << (first = Demon::getDamage()) << endl 
            << "second attack: " << (second = Demon::getDamage()) << endl;

        return(first + second);
    }

    string Balrog::getSpecies() const{return "Balrog";}
}