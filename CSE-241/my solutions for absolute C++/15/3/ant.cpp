#include "ant.h"
#include <string>

using std::string;

namespace KurutSimulation{
    Ant::Ant(Cell theLocation, Grid *gridRef): Organism(theLocation, gridRef){/**/}

    void Ant::move(){
        if(canBreed())
            breed();
        setLocation(getLocation().randomNeighbour());
        breedTime++;
    }

    bool Ant::canBreed() const{return (breedTime >= 3);}

    void Ant::breed(){
        bool gaveBirth = false;

        Ant *baby = new Ant(getLocation().up(), gridRef);

        if(gridRef->addOrganism(baby) == true){
            gaveBirth = true;
        }

        if(!gaveBirth){
            delete baby;
            baby = new Ant(getLocation().down(), gridRef);
            if(gridRef->addOrganism(baby) == true)
                gaveBirth = true;
        }

        if(!gaveBirth){
            delete baby;
            baby = new Ant(getLocation().left(), gridRef);
            if(gridRef->addOrganism(baby) == true)
                gaveBirth = true;
        }

        if(!gaveBirth){
            delete baby;
            baby = new Ant(getLocation().right(), gridRef);
            if(gridRef->addOrganism(baby) == true)
                gaveBirth = true;
        }

        if(gaveBirth)
            breedTime = 0;
    }

    void Ant::print(ostream& outputStream) const{
        outputStream << "O";
    }

    string Ant::type() const{
        return("ant");
    }

}