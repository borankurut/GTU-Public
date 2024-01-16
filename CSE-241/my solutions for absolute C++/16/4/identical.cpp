#include <iostream>
#include <string>

using namespace std;

template<class T>
bool isIdentical(T val1, T val2);

int main(){
    cout << isIdentical(1, 1) << endl;
    cout << isIdentical(1, 2) << endl;

    cout << isIdentical('a', 'a') << endl;
    cout << isIdentical('a', 'b') << endl;

    cout << isIdentical(1.5, 1.5) << endl;
    cout << isIdentical(1.5, 2.5) << endl;

    cout << isIdentical("same", "same") << endl;
    cout << isIdentical("not-same", "not-same-so") << endl;

    return(0);
}

template<class T>
bool isIdentical(T val1, T val2){
    return(val1 == val2);
}