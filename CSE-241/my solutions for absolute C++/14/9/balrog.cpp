#include <iostream>
#include "balrog.h"

using std::cout;
using std::endl;

namespace KurutRpg{
    Balrog::Balrog(): Demon(100, 150){/**/}
    Balrog::Balrog(int theStrength, int theHitpoints):
        Demon(theStrength, theHitpoints){/**/}

    int Balrog::getDamage() const{
        int first = Demon::getDamage(),
            second = Demon::getDamage();
        
        cout << getSpecies() << " Attacked with " << first << endl 
            << "and attacked again with " << second << endl;

        return(first + second);
    }

    string Balrog::getSpecies() const{return "Balrog";}
}