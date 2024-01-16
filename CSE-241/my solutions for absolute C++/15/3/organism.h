#ifndef ORGANISM_H
#define ORGANISM_H

#include "cell.h"
#include "grid.h"
#include <iostream>
#include <string>

using std::string;
using std::ostream;


namespace KurutSimulation{
    class Grid;
    
    class Organism{
    public:
        Organism(Cell theLocation, Grid *gridRef);

        Cell getLocation() const;

        void setLocation(Cell newLocation);

        void die();

        virtual void print(ostream& outputStream) const = 0;

        virtual void move() = 0;

        virtual bool canBreed() const = 0;

        virtual void breed() = 0;

        virtual string type() const = 0;

        friend ostream& operator<<(ostream& outputStream, const Organism& organism);


    protected:
        Cell location;
        Grid* gridRef;
        int breedTime;
        friend class Grid;
    };
} // namespace KurutSimulation


#endif