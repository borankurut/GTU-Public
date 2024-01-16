#ifndef CELL_H
#define CELL_H

#include <iostream>

using std::ostream;

namespace KurutSimulation{
    class Cell{

    public:
        Cell(int theRow, int theColumn);

        void setRow(int newRow);
        void setColumn(int newColumn);

        int getRow() const;
        int getColumn() const;

        Cell up() const;    // return up cell
        Cell down() const;  // return down cell
        Cell left() const;  // return left cell
        Cell right() const; // return right cell

        Cell randomNeighbour() const;

        friend bool operator==(const Cell& op1, const Cell& op2);
        friend ostream& operator<<(ostream& outputStream, const Cell& cellObj);

    private:
        int row;
        int column;
    };
}

#endif