#include <iostream>
#include <vector>

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
    int computePrice();
    bool isEqual(Pizza other);

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

class Order{
public:
    void output();
    void add(Pizza newPizza);
    Pizza remove(int pizzaIx);
    Pizza remove(Pizza toRemove);
    int computeTotalPrice();
    Order(vector<Pizza> pizzas);

private:
    vector<Pizza> pizzas;
    int totalPrice;
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
    cout << pizzaTypeStr(getType()) << " typed pizza (" << pizzaSizeStr(getSize()) << " size)"
        << " has " << getPepperoni() << " pepperonis and " << getCheese() << " cheeses.\n";
    cout << "$" << computePrice() << endl;
}

int Pizza::computePrice(){
    price = 10;
    if(size == PizzaSize::Medium)
        price += 4;
    else if(size == PizzaSize::Large)
        price += 7;
    price += 2 * (pepperoni + cheese); // topping

    return(price);
}

void Order::output(){
    int i;
    cout << "Order:\n";
    for(i = 0; i < pizzas.size(); ++i){
        pizzas[i].outputDescription();
    }
    cout << "\nWith total $" << computeTotalPrice() << endl << endl;
}

void Order::add(Pizza newPizza){
    pizzas.push_back(newPizza);
}

Pizza Order::remove(int pizzaIx){
    Pizza Removed = pizzas[pizzaIx];
    pizzas.erase(pizzas.begin() + pizzaIx);
    return(Removed);
}

Pizza Order::remove(Pizza toRemove){
    int i;
    for(i = 0; i < pizzas.size(); ++i){
        if(toRemove.isEqual(pizzas[i])){
            return(remove(i));
        }
    }
}

int Order::computeTotalPrice(){
    totalPrice = 0;
    int i;
    for(i = 0; i < pizzas.size(); ++i){
        totalPrice += pizzas[i].computePrice();
    }
    return(totalPrice);
}

Order::Order(vector<Pizza> newPizzas){
    pizzas = newPizzas;
    computeTotalPrice();
}

bool Pizza::isEqual(Pizza other){
    return( getType() == other.getType() &&
            getSize() == other.getSize() &&
            getPepperoni() == other.getPepperoni() &&
            getCheese() == other.getCheese());
}


int main(){ // test
    Pizza myPizza;
    myPizza.setType(PizzaType::DeepDish);
    myPizza.setSize(PizzaSize::Medium);
    myPizza.setPepperoni(3);
    myPizza.setCheese(2);

    Pizza myPizza2;
    myPizza2.setType(PizzaType::HandTossed);
    myPizza2.setSize(PizzaSize::Small);
    myPizza2.setPepperoni(1);
    myPizza2.setCheese(1);

    Pizza myPizza3;
    myPizza3.setType(PizzaType::Pan);
    myPizza3.setSize(PizzaSize::Large);
    myPizza3.setPepperoni(5);
    myPizza3.setCheese(5);

    vector<Pizza> que;
    que.push_back(myPizza);
    que.push_back(myPizza2);

    Order myOrder(que);
    myOrder.output();

    myOrder.add(myPizza3);
    myOrder.output();

    cout << "Removed:";
    myOrder.remove(myPizza).outputDescription();
    myOrder.output();
    
    return(0);
}