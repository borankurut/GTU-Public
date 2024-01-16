// The doodlebugs behave according to the following model:

// ■ Move. For every time step, the doodlebug will move to an adjacent cell containing
// an ant and eat the ant. If there are no ants in adjoining cells, the doodlebug
// moves according to the same rules as the ant. Note that a doodlebug cannot eat
// other doodlebugs.

// ■ Breed. If a doodlebug survives for eight time steps, at the end of the time step it
// will spawn off a new doodlebug in the same manner as the ant.

// ■ Starve. If a doodlebug has not eaten an ant within three time steps, at the end
// of the third time step it will starve and die. The doodlebug should then be removed
// from the grid of cells.

// draw: X.
#ifndef DOODLEBUG_H
#define DOODLEBUG_H

#include "organism.h"
#include <string>

using std::string;

namespace KurutSimulation{
    class Doodlebug: public Organism{

    public:
        Doodlebug(Cell theLocation, Grid *gridRef);

        void eat(const Cell& location);

        void move() override;

        bool canBreed() const override;

        void breed() override;

        void print(ostream& outputStream) const override;

        string type() const override;

        bool starved() const;

    private:
        int starving;

    };
}

#endif