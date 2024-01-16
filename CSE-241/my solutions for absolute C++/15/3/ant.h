// The ants behave according to the following model:

// ■ Move. For every time step, the ants randomly try to move up, down, left, or
// right. If the neighboring cell in the selected direction is occupied or would
// move the ant off the grid, then the ant stays in the current cell.

// ■ Breed. If an ant survives for three time steps, at the end of the time step (i.e.,
// after moving) the ant will breed. This is simulated by creating a new ant in an
// adjacent (up, down, left, or right) cell that is empty. If there is no empty cell
// available, no breeding occurs. Once an offspring is produced, an ant cannot
// produce an offspring again until it has survived three more time steps.

// draw: O.

#ifndef ANT_H
#define ANT_H

#include "organism.h"
#include <string>

using std::string;

namespace KurutSimulation{
    class Ant: public Organism{

    public:
        Ant(Cell theLocation, Grid *gridRef);

        void move() override;

        bool canBreed() const override;

        void breed() override;

        void print(ostream& outputStream) const override;

        string type() const override;

    };
}

#endif