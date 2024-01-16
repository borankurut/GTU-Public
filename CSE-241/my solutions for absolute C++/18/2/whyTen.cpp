#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void f1(int val) throw(int);
void f2(int val) throw(int);
void f3(int val) throw(int);
void f4(int val) throw(int);
void f5(int val) throw(int);
void f6(int val) throw(int);
void f7(int val) throw(int);
void f8(int val) throw(int);
void f9(int val) throw(int);
void f10(int val) throw(int);

int main(){
    int value;

    try{
        cout << "Enter value: ";
        cin >> value;

        if(value == 0)
            throw value;

        f1(value);
    }
    catch(int e){
        cout << "Thrown Exception: " << e << endl;
    }

    cout << "Value: " << value << endl;

    return 0;
}

void f1(int val) throw(int){
    if(val == 1)
        throw(val);
    else 
        f2(val);
}

void f2(int val) throw(int){
    if(val == 2)
        throw(val);
    else 
        f3(val);
}

void f3(int val) throw(int){
    if(val == 3)
        throw(val);
    else 
        f4(val);
}

void f4(int val) throw(int){
    if(val == 4)
        throw(val);
    else 
        f5(val);
}

void f5(int val) throw(int){
    if(val == 5)
        throw(val);
    else 
        f6(val);
}

void f6(int val) throw(int){
    if(val == 6)
        throw(val);
    else 
        f7(val);
}

void f7(int val) throw(int){
    if(val == 7)
        throw(val);
    else 
        f8(val);
}

void f8(int val) throw(int){
    if(val == 8)
        throw(val);
    else 
        f9(val);
}

void f9(int val) throw(int){
    if(val == 9)
        throw(val);
    else 
        f10(val);
}

void f10(int val) throw(int){
    if(val == 10)
        throw(val);
}