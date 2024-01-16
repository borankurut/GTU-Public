#include "doodlebug.h"
#include <string>

using std::string;

namespace KurutSimulation{
    Doodlebug::Doodlebug(Cell theLocation, Grid *gridRef):
        Organism(theLocation, gridRef), starving(0){/**/}

    void Doodlebug::move(){
        bool dead = false;
        if(starved()){
            die();
            dead = true;
        }
        if(!dead && canBreed())
            breed();

        if(!dead){
            if(!gridRef->isEmpty(getLocation().up()) &&
                gridRef->getOrganism(getLocation().up())->type() == "ant")
                    eat(getLocation().up());
            else if(!gridRef->isEmpty(getLocation().down()) &&
                 gridRef->getOrganism(getLocation().down())->type() == "ant")
                    eat(getLocation().down());
            else if(!gridRef->isEmpty(getLocation().left()) && 
                gridRef->getOrganism(getLocation().left())->type() == "ant")
                    eat(getLocation().left());
            else if(!gridRef->isEmpty(getLocation().right()) &&
                gridRef->getOrganism(getLocation().right())->type() == "ant")
                    eat(getLocation().right());
            else
                setLocation(getLocation().randomNeighbour());

            breedTime++;
            starving++;
        }
    }

    void Doodlebug::eat(const Cell& location){
        gridRef->getOrganism(location)->die();
        setLocation(location);
        starving = 0;
    }

    bool Doodlebug::canBreed() const{return (breedTime >= 8);}

    void Doodlebug::breed(){
        bool gaveBirth = false;

        Doodlebug *baby = new Doodlebug(getLocation().up(), gridRef);

        if(gridRef->addOrganism(baby) == true){
            gaveBirth = true;
        }

        if(!gaveBirth){
            delete baby;
            baby = new Doodlebug(getLocation().down(), gridRef);
            if(gridRef->addOrganism(baby) == true)
                gaveBirth = true;
        }

        if(!gaveBirth){
            delete baby;
            baby = new Doodlebug(getLocation().left(), gridRef);
            if(gridRef->addOrganism(baby) == true)
                gaveBirth = true;
        }

        if(!gaveBirth){
            delete baby;
            baby = new Doodlebug(getLocation().right(), gridRef);
            if(gridRef->addOrganism(baby) == true)
                gaveBirth = true;
        }

        if(gaveBirth)
            breedTime = 0;
    }

    void Doodlebug::print(ostream& outputStream) const{
        outputStream << "X";
    }

    string Doodlebug::type() const{return "doodlebug";}

    bool Doodlebug::starved() const{return (starving >= 3);}
}