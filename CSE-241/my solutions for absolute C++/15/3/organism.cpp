#include "organism.h"
#include "grid.h"
#include <iostream>

using std::cout;

namespace KurutSimulation{
    Organism::Organism(Cell theLocation, Grid *theGridRef): 
        location(theLocation), gridRef(theGridRef), breedTime(0){/**/}

    Cell Organism::getLocation() const {return location;}

    void Organism::setLocation(Cell newLocation){
        if(gridRef->isEmpty(newLocation) && gridRef->isInside(newLocation)){
            gridRef->getOrganism(getLocation())->location = newLocation;
            location = newLocation;
        }
    }

    void Organism::die(){
        Cell toDieLocation = getLocation();
        int i;
        for(i = 0; i < gridRef->organisms.size(); ++i)
            if(toDieLocation == gridRef->organisms[i]->getLocation()){
                Organism* toDie = gridRef->organisms[i];
                delete toDie;
                toDie = nullptr;
                gridRef->organisms.erase(gridRef->organisms.begin() + i);
            }
    }

    ostream& operator<<(ostream& outputStream, const Organism& organism){
        organism.print(outputStream);
        return(outputStream);
    }
}