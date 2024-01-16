#include <iostream>
#include "cell.h"
#include "organism.h"
#include "grid.h"
#include "ant.h"
#include "doodlebug.h"

using namespace std;
using namespace KurutSimulation;

void play();

int main(){
    cout <<  "O's are ants and X's are doodlebugs\n" 
        <<  "You can skip times pressing enter.\nEnter 'q' to quit\n";

    char ans = 'y';
    while(ans == 'y'){
        play();
        cout << "Play again?\n(y/n)>";
        cin >> ans;
    }

    return(0);
}

void play(){
    int row,
        column,
        ants,
        doodlebugs;

    cout << "How many rows?\n>";
    cin >> row;
    cout << "How many column?\n>";
    cin >> column;

    if(row < 2 || column < 2){
        cout << "minimum grid is 2 x 2 so it is setted to 2 x 2.\n";
        row = 2;
        column = 2;
    }

    cout << "How many ants?\n>";
    cin >> ants;

    while(ants > row*column || ants < 0){
        cout << "Please enter valid amounts.\nHow many ants?\n>";
        cin >> ants;
    }
    cout << "How many doodlebugs?\n>";
    cin >> doodlebugs;

    while(doodlebugs > row*column - ants || doodlebugs < 0){
        cout << "Please enter valid amounts.\nHow many doodlebugs?\n>";
        cin >>doodlebugs;
    }

    Grid newGrid(row, column);

    newGrid.addAnt(ants);
    newGrid.addDoodlebug(doodlebugs);

    char enter = cin.get();

    while(enter == '\n'){
        newGrid.print();
        enter = cin.get();
        newGrid.nextTurn();
    }
}