#include <iostream>

using namespace std;

class Fraction{

public:

    void setNum(int newNum);
    void setDenum(int newDenum);
    double toDouble();
    Fraction reduce();
    void display();
    
private:

    int num,
        denum;
};

void Fraction::setNum(int newNum){
    num = newNum;
}

void Fraction::setDenum(int newDenum){
    denum = newDenum;
}

double Fraction::toDouble(){
    return static_cast<double>(num)/static_cast<double>(denum);
}

Fraction Fraction::reduce(){
    Fraction reduced;
    int newNum = num;
    int newDenum = denum;


    for(int i = 1; i < newNum || i < newDenum; ++i){
        if(newNum % i == 0 && newDenum % i == 0){
            newNum /= i;
            newDenum /= i;
            i = 1;
        }
    }

    reduced.setNum(newNum);
    reduced.setDenum(newDenum);

    return(reduced);
}

void Fraction::display(){
    Fraction reduced = reduce();
    cout << reduced.num << "/" << reduced.denum << endl;
}

int main(){
    
    Fraction myFraction;
    myFraction.setNum(20);
    myFraction.setDenum(60);
    myFraction.display();

    Fraction hard;
    hard.setNum(11420);
    hard.setDenum(50020);
    hard.display();
    
    
    return(0);
}