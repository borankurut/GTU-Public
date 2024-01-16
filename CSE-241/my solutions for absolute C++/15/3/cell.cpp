#include "cell.h"
#include <stdlib.h> //random

namespace KurutSimulation{
    Cell::Cell(int theRow, int theColumn):
        row(theRow), column(theColumn){/**/}
    
    void Cell::setRow(int newRow){row = newRow;}
    void Cell::setColumn(int newColumn){column = newColumn;}

    int Cell::getRow() const{return row;}
    int Cell::getColumn() const{return column;}

    Cell Cell::up() const{return Cell(row - 1, column);}
    Cell Cell::down() const{return Cell(row + 1, column);}
    Cell Cell::left() const{return Cell(row, column - 1);}
    Cell Cell::right() const{return Cell(row, column + 1);}

    Cell Cell::randomNeighbour() const{
        int randomNumber = rand();
        if(randomNumber % 4 == 0)
            return up();
        if(randomNumber % 4 == 1)
            return down();
        if(randomNumber % 4 == 2)
            return left();
        if(randomNumber % 4 == 3)
            return right();
    }

    bool operator==(const Cell& op1, const Cell& op2){
        return( op1.row == op2.row   &&
                op1.column == op2.column);
    }

    ostream& operator<<(ostream& outputStream, const Cell& cellObj){
        outputStream << "(" << cellObj.row << ", " << cellObj.column << ")";
        return(outputStream);
    }
}