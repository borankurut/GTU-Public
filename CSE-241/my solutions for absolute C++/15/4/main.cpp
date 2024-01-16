#include <iostream>
#include "balrog.h"
#include "cyberdemon.h"
#include "elf.h"
#include "human.h"

using namespace std;
using namespace KurutRpg;

void battleArena(Creature& cr1, Creature& cr2);

int main(){
    Balrog newBalrog;
    Cyberdemon newCyber;
    Elf newElf,
        elfFriend;
    Human newHuman;
    Human scapegoat;
    

    //battleArena(newBalrog, scapegoat);

    battleArena(newElf, newCyber);
    battleArena(elfFriend, newCyber);

    return(0);
}

void battleArena(Creature& cr1, Creature& cr2){
    bool gameEnd = false;

    while(!gameEnd){
        cr1.attack(cr2);
        cr2.attack(cr1);

        cout << cr1 << endl << cr2 << endl;

        gameEnd = (cr1.getHitpoints() <= 0 || cr2.getHitpoints() <= 0);
    }
}