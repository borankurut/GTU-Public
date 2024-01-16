#ifndef GRID_H
#define GRID_H

#include "cell.h"
#include <vector>
#include "organism.h"

using std::vector;

namespace KurutSimulation{
    class Organism;
    class Grid{

    public:
        Grid(int theMaxRow, int theMaxColumn);

        bool addOrganism(Organism* organism);

        void addAnt(int amount);

        void addDoodlebug(int amount);

        bool isEmpty(const Cell& location) const;

        bool isInside(const Cell& location) const;

        void emptyLocation(const Cell& location);

        Organism* getOrganism(const Cell& location) const;

        void printFilledLocations() const;

        void print() const;

        void nextTurn();

        int getAntNum() const;

        int getDoodlebugNum() const;

    private:
        int maxRow;
        int maxColumn;
        vector<Organism*> organisms;
        friend class Organism;
    };
} // namespace KurutSimulation

#endif