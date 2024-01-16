#include <iostream>
#include <math.h>

using namespace std;

class MyInteger{

public:

    int getInteger();
    void setInteger(int newInt);
    int operator[](int index);

private:
    int integer;

};

int main(){
    MyInteger myInt;
    myInt.setInteger(15244);

    cout << myInt[0] << endl;
    cout << myInt[1] << endl;
    cout << myInt[2] << endl;
    cout << myInt[3] << endl;
    cout << myInt[4] << endl;

    return(0);
}

int MyInteger::getInteger(){
    return(integer);
}

void MyInteger::setInteger(int newInt){
    integer = newInt;
}

int MyInteger::operator[](int index){   
    int digitNum = 0,
        intCopy = integer,
        ix;

    while(intCopy != 0){
        intCopy /= 10;
        digitNum += 1;
    }

    if(index >= 0 && index < digitNum){
        // 0 -> %10
        // 1 -> /10 %10
        // 2 -> /100 %10
        intCopy = integer;
        for(ix = 0; ix < index; ++ix){
            intCopy /= 10;
        }
        return (intCopy%10);
    }
    else{
        return -1;
    }
}