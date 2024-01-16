#include <iostream>
#include <cstdlib>

using namespace std;

class CharPair{

public:
    CharPair();
    CharPair(int sz);
    char& operator[](int index);
    int getSize();
private:
    char array[100];
    int size;
};

int main(){



    return(0);
}

CharPair::CharPair(){
    int ix;
    for(ix = 0; ix < 10; ++ix)
        array[ix] = '#';
    size = 10;
}

CharPair::CharPair(int sz){
    int ix;
    if(sz <= 100){
        for(ix = 0; ix < sz; ++ix)
            array[ix] = '#';
        size = sz;
    }
}

char& CharPair::operator[](int index){
    if(index >= 0 && index < getSize())
        return(array[index]);
    else{
        cout << "Illegal index value.\n";
        exit(1);
    }
}

int CharPair::getSize(){
    return(size);
}