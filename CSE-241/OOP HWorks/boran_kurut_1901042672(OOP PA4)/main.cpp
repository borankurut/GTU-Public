#include <iostream>
#include "Robot.h"
#include "Bulldozer.h"
#include "Roomba.h"
#include "Humanic.h"
#include "Optimusprime.h"
#include "Robocop.h"

using namespace std;

void warzone(Robot& rob0, Robot& rob1);

int main(){
    Optimusprime myRobot(50, 250);

    Robocop myRobot2(80, 250);

    warzone(myRobot, myRobot2);    

    return 0;
}

void warzone(Robot& rob0, Robot& rob1){
    while(rob0.getHp() > 0 && rob1.getHp() > 0){
        cout << rob0.typeOf() << "'s health: " << rob0.getHp() << "  ";
        cout << rob1.typeOf() << "'s health: " << rob1.getHp() << endl;

        int damage = rob0.getDamage();
        cout << rob0.typeOf() << " is attacked with: " << damage  << "  ";
        rob1.setHp(rob1.getHp() - damage);

        damage = rob1.getDamage();
        cout << rob1.typeOf() << " is attacked with: " << damage << endl;
        rob0.setHp(rob0.getHp() - damage);
    }
    cout << rob0.typeOf() << "'s health: " << rob0.getHp() << "  ";
    cout << rob1.typeOf() << "'s health: " << rob1.getHp() << endl;

    if(rob0.getHp() <= 0 && rob1.getHp() <= 0)
        cout << "Draw\n";
    else if(rob0.getHp() > rob1.getHp())
        cout << rob0.typeOf() << " is won.\n";
    else
        cout << rob1.typeOf() << " is won.\n";
}