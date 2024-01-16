#include <iostream>

using namespace std;

template<class T, class V>
class Pair{
public: 
    Pair();
    Pair(T theFirst, V theSecond);

    void setFirst(T newFirst);
    void setSecond(V newSecond);

    T getFirst() const;
    V getSecond() const;

private:
    T first;
    V second;

};

template<class T, class V>
T addUp(const Pair<T, V>& thePair);

int main(){
    Pair<double, int> newDoubleIntPair(1.5, 2);
    cout << addUp(newDoubleIntPair) << endl;

    Pair<int, char> newintCharPair(1, 'b');
    cout << addUp(newintCharPair) << endl;

    cout << newintCharPair.getFirst() << ", "
        << newintCharPair.getSecond() << endl;

    return(0);
}

template<class T, class V>
Pair<T, V>::Pair(){/**/}

template<class T, class V>
Pair<T, V>::Pair(T theFirst, V theSecond):  first(theFirst), second(theSecond){/**/}

template<class T, class V>
void Pair<T, V>::setFirst(T newFirst){first = newFirst;}

template<class T, class V>
void Pair<T, V>::setSecond(V newSecond){second = newSecond;}

template<class T, class V>
T Pair<T, V>::getFirst() const{return first;}

template<class T, class V>
V Pair<T, V>::getSecond() const{return second;}

template<class T, class V>
T addUp(const Pair<T, V>& thePair){
    return (thePair.getFirst() + thePair.getSecond());
}