#include <iostream>
#include <time.h>

using namespace std;

class BoxOfProduce{

public:
    void setFruits(string newFruits[3]);
    void setVegetables(string newVegetables[3]);
    void addFruit(string fruit);
    void addVegetable(string vegetable);
    void output();
    void removeFruit(string fruit);
    void removeVegetable(string vegetable);

    string *getFruits();
    string *getVegetables();


private:
    string fruits[3],
            vegetables[3];

};

void BoxOfProduce::setFruits(string newFruits[3]){
    for(int i = 0; i < 3; ++i)
        fruits[i] = newFruits[i];
}

void BoxOfProduce::setVegetables(string newVegetables[3]){
    for(int i = 0; i < 3; ++i)
        vegetables[i] = newVegetables[i];
}

string *BoxOfProduce::getFruits(){
    return fruits;
}

string *BoxOfProduce::getVegetables(){
    return vegetables;
}

void BoxOfProduce::output(){
    cout << "Box:\n";
    cout << "Fruits: ";
    for(int i = 0; i < 3; i++)
        cout << getFruits()[i] << " ";
    cout << endl;

    cout << "Vegetables: ";
    for(int i = 0; i < 3; i++)
        cout << getVegetables()[i] << " ";
    cout << endl;
}

void BoxOfProduce::addVegetable(string vegetable){
    for(int i = 0; i < 3; i++)
        if(vegetables[i] == ""){
            vegetables[i] = vegetable;
            break;
        }
}


void BoxOfProduce::addFruit(string fruit){
    for(int i = 0; i < 3; i++)
        if(fruits[i] == ""){
            fruits[i] = fruit;
            break;
        }
}

void BoxOfProduce::removeFruit(string fruit){
    for(int i = 0; i < 3; ++i)
        if(fruits[i] == fruit){
            fruits[i] = "";
            break;
        }
}

void BoxOfProduce::removeVegetable(string vegetable){
    for (int i = 0; i < 3; ++i)
        if(vegetables[i] == vegetable){
            vegetables[i] = "";
            break;
        }
}

bool isVegetable(string check){
    return check == "brocoli" || check == "kale";
}


int main(){
    srand(time(0));
    // vege:    broccoli, kale
    // frui:    tomato, kiwi, tomatillo
    BoxOfProduce myBox;
    string fruits[3],
            vegetables[3],
            allStuff[5] = {"brocoli", "kale", "tomato", "kiwi", "tomatillo"},
            userCommand,
            toReplace,
            toAssign;

    myBox.setFruits(fruits);
    myBox.setVegetables(vegetables);

    for(int i =0; i < 3; ++i){
        string stuff = allStuff[rand() % 5];
        if(isVegetable(stuff))
            myBox.addVegetable(stuff);
        else
            myBox.addFruit(stuff);
    }

    myBox.output();

    while(userCommand != "quit"){
        cout << "enter the stuff you want to replace (enter 'quit' to quit.)\n>";
        cin >> toReplace;

        if(isVegetable(toReplace))
            myBox.removeVegetable(toReplace);
        else
            myBox.removeFruit(toReplace);

        cout << "enter the stuff you want to replace with\n>";
        cin >> toAssign;

        if(isVegetable(toAssign))
            myBox.addVegetable(toAssign);
        else
            myBox.addFruit(toAssign);

        myBox.output();
    }

    return (0);
}

