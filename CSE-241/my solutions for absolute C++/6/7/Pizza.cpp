#include <iostream>

using namespace std;

enum class PizzaType{DeepDish, HandTossed, Pan};
enum class PizzaSize{Small, Medium, Large};

class Pizza{

public:
    void setType(PizzaType newType);
    void setSize(PizzaSize newSize);
    void setPepperoni(int newPepperoni);
    void setCheese(int newCheese);
    void outputDescription();
    void computePrice();

    PizzaType getType();
    PizzaSize getSize();
    int getPepperoni();
    int getCheese();

private:
    PizzaType type;
    PizzaSize size;

    int pepperoni,
        cheese,
        price;

};

void Pizza::setType(PizzaType newType){
    type = newType;
}

void Pizza::setSize(PizzaSize newSize){
    size = newSize;
}

void Pizza::setPepperoni(int newPepperoni){
    pepperoni = newPepperoni;
}

void Pizza::setCheese(int newCheese){
    cheese = newCheese;
}

PizzaType Pizza::getType(){
    return type;
}

PizzaSize Pizza::getSize(){
    return size;
}

int Pizza::getPepperoni(){
    return pepperoni;
}

int Pizza::getCheese(){
    return cheese;
}

string pizzaTypeStr(PizzaType type){
    if(type == PizzaType::DeepDish)
        return "DeepDish";
    
    else if(type == PizzaType::HandTossed)
        return "HandTossed";

    else if(type == PizzaType::Pan)
        return "Pan";
}

string pizzaSizeStr(PizzaSize size){
    if(size == PizzaSize::Small){
        return "Small";
    }
    else if(size == PizzaSize::Medium){
        return "Medium";
    }
    else if(size == PizzaSize::Large){
        return "Large";
    }
}

void Pizza::outputDescription(){
    computePrice();
    cout << pizzaTypeStr(getType()) << " typed pizza (" << pizzaSizeStr(getSize()) << " size)"
        << " has " << getPepperoni() << " pepperonis and " << getCheese() << " cheeses.\n";
    cout << "$" << price << endl;
}

void Pizza::computePrice(){
    price = 10;
    if(size == PizzaSize::Medium)
        price += 4;
    else if(size == PizzaSize::Large)
        price += 7;
    price += 2 * (pepperoni + cheese); // topping
}

int main(){ // test
    Pizza myPizza;
    myPizza.setType(PizzaType::DeepDish);
    myPizza.setSize(PizzaSize::Medium);
    myPizza.setPepperoni(3);
    myPizza.setCheese(2);
    myPizza.outputDescription();

    Pizza myPizza2;
    myPizza2.setType(PizzaType::HandTossed);
    myPizza2.setSize(PizzaSize::Small);
    myPizza2.setPepperoni(1);
    myPizza2.setCheese(1);
    myPizza2.outputDescription();
    return(0);
}