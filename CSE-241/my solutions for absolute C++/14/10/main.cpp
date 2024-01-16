#include <iostream>
#include "pet.h"
#include "dog.h"
#include "rock.h"

using namespace std;

int main(){
    Pet newPet;
    Dog newDog;
    Rock newRock;

    cout << "Pet: " << newPet.getLifespan() << endl
        <<  "Dog: " << newDog.getLifespan() << endl
        <<  "Rock: " << newRock.getLifespan() << endl;

    return(0);
}