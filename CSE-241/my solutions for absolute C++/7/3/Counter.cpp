#include <iostream>

using namespace std;

class Counter{

private:
    int upto,
        reading;
    void incr1();
    void incr10();
    void incr100();
    void incr1000();

public:
    Counter(int newUpto);
    Counter();
    void show() const;
    void reset();
    bool overflow() const;
    void addMoney(char key, int value);
};

Counter::Counter(){
    upto = 9999;
    reading = 0;
}

Counter::Counter(int newUpto){
    upto = newUpto;
    reading = 0;
}

void Counter::incr1000(){
    reading += 1000;
}

void Counter::incr100(){
    reading += 100;
}

void Counter::incr10(){
    reading += 10;
}

void Counter::incr1(){
    reading += 1;
}

void Counter::show() const{
    cout << "Money: " << reading << endl;
}

void Counter::reset(){
    reading = 0;
}

bool Counter::overflow() const{
    return (reading > upto);
}

void Counter:: addMoney(char key, int value){
    if(key != 'a' && key != 's' && key != 'd' && key != 'f'){
        cerr << "Invalid key.";
        exit(1);
    }
    else if(value < 0 || value > 9){
        cerr << "Invalid value.";
        exit(1);
    }

    for(int i = 0; i < value; i++){
        if(key == 'a')  
            incr1();
        if(key == 's')  
            incr10();
        if(key == 'd')  
            incr100();
        if(key == 'f')  
            incr1000();
    }
}

int main(){
    Counter yoMum(9999);
    char key;   //asdfor
    int value;  

    cout << "a: cents, s: dimes, d: dollars, f: tens of dollars, o: show overflow, r: reset.\n";

    yoMum.show();
    while(true){
        cout << "\n>";
        cin >> key;

        if(key == 'o'){
            yoMum.show();
            continue;
        }
        if(key == 'r'){
            yoMum.reset();
            yoMum.show();
            continue;
        }
        cin >> value;

        yoMum.addMoney(key, value);

        if(yoMum.overflow())
            cout << "yoMum overflowed.\n";
        else
            yoMum.show();
    }

    return(0);
}