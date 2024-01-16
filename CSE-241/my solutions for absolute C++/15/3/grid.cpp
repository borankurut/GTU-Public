#include "grid.h"
#include <iostream>
#include <stdlib.h> //rand
#include "ant.h"
#include "doodlebug.h"
#include "string"
#include <vector>

using std::cout;
using std::endl;
using std::string;
using std::vector;

namespace KurutSimulation{
    Grid::Grid(int theMaxRow, int theMaxColumn):
    maxRow(theMaxRow), maxColumn(theMaxColumn){/**/}

    bool Grid::isEmpty(const Cell& location) const{
        int ix;
        for(ix = 0; ix < organisms.size(); ++ix)
            if(organisms[ix]->getLocation() == location)
                return false;
        return true;
    }

    bool Grid::isInside(const Cell& location) const{
        return (location.getRow() >= 0 && location.getRow() < maxRow &&
                location.getColumn() >= 0 && location.getColumn() < maxColumn);
    }

    bool Grid::addOrganism(Organism* organismP){
        bool empty = isEmpty(organismP->getLocation());
        bool inside = isInside(organismP->getLocation());
        bool added = false;

        if(empty && inside){
            organisms.push_back(organismP);
            added = true;
        }
        return added;
    }

    void Grid::printFilledLocations() const{
        int i,
            j;
        cout << "Filled Locations: ";
        cout << "(" << organisms.size() << " location)\n";
        for(j = 0; j < maxColumn*2 +1; ++j)
                cout << "-";
            cout << endl;

        for(i = 0; i < maxRow; ++i){
            cout << "|";
            for(j = 0; j < maxColumn; ++j){
                if(isEmpty(Cell(i, j)))
                    cout << " |";
                else
                    cout << "*|";
            }
            cout << endl;

            for(j = 0; j < maxColumn*2 +1; ++j)
                cout << "-";
            cout << endl;
                
        }
    }


    void Grid::print() const{
        int i,
            j;
        cout << "Ants: " << getAntNum() << " Doodlebugs: " << getDoodlebugNum() << endl;
        for(j = 0; j < maxColumn*2 +1; ++j)
                cout << "-";
            cout << endl;

        for(i = 0; i < maxRow; ++i){
            cout << "|";
            for(j = 0; j < maxColumn; ++j){
                if(isEmpty(Cell(i, j)))
                    cout << " |";
                else
                    cout << *getOrganism(Cell(i, j)) << "|";
            }
            cout << endl;

            for(j = 0; j < maxColumn*2 +1; ++j)
                cout << "-";
            cout << endl;
                
        }
    }

    Organism* Grid::getOrganism (const Cell& location) const{
        bool found = false;
        int i;
        for(i = 0; i < organisms.size(); ++i)
            if(location == organisms[i]->getLocation()){
                found = true;
                return organisms[i];
            }
        if(!found){
            cout << "getOrganism function invalid location.";
            exit(1);
        }
    }

    void Grid::emptyLocation(const Cell& location){
        int i;
        for(i = 0; i < organisms.size(); ++i)
            if(organisms[i]->getLocation() == location)
                organisms[i]->die();
    }

    void Grid::addAnt(int amount){
        int curOrgAmt = organisms.size();
        if(amount + curOrgAmt > maxRow * maxColumn)
            cout << "not enough space!\n";
        else{
            while(organisms.size() - curOrgAmt < amount){
                Ant *newAnt = new Ant(Cell(rand()%maxRow, rand()%maxColumn), this);
                if(addOrganism(newAnt) == false)
                    delete newAnt;
            }
        }
    }

    void Grid::addDoodlebug(int amount){
        int curOrgAmt = organisms.size();
        if(amount + curOrgAmt > maxRow * maxColumn)
            cout << "not enough space!\n";
        else{
            while(organisms.size() - curOrgAmt < amount){
                Doodlebug *newDoodlebug = new Doodlebug(Cell(rand()%maxRow, rand()%maxColumn), this);
                if(addOrganism(newDoodlebug) == false)
                    delete newDoodlebug;
            }
        }
    }

    int Grid::getAntNum() const{
        int antNum = 0;
        int i;
        for(i = 0; i < organisms.size(); ++i)
            if(organisms[i]->type() == "ant")
                antNum++;
        return antNum;
    }

    int Grid::getDoodlebugNum() const{
        int doodlebugNum = 0;
        int i;
        for(i = 0; i < organisms.size(); ++i)
            if(organisms[i]->type() == "doodlebug")
                doodlebugNum++;

        return doodlebugNum;
    }

    void Grid::nextTurn(){
        int i;
        vector<Organism*> toMove;

        for(i = 0; i < organisms.size(); ++i){
            if(organisms[i]->type() == "doodlebug"){
                toMove.push_back(organisms[i]);
            }
        }

        for(i = 0; i < toMove.size(); ++i){
            toMove[i]->move();
        }

        toMove.clear();

        for(i = 0; i < organisms.size(); ++i){
            if(organisms[i]->type() == "ant"){
                toMove.push_back(organisms[i]);
            }
        }

        for(i = 0; i < toMove.size(); ++i){
            toMove[i]->move();
        }
    }
}