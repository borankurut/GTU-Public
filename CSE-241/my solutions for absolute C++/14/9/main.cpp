#include <iostream>
#include "balrog.h"
#include "cyberdemon.h"
#include "elf.h"
#include "human.h"

using namespace std;
using namespace KurutRpg;


int main(){
    Balrog newBalrog;
    Cyberdemon newCyber;
    Elf newElf;
    Human newHuman;
    

    newBalrog.getDamage();
    newCyber.getDamage();
    newElf.getDamage();   
    newHuman.getDamage();

    return(0);
}