#include <iostream>
#include <string>

using namespace std;

template<class T>
class Set{

public:
    Set();
    Set(const Set<T>& setObj);

    void add(const T& element);
    int size() const;
    void print() const;

    Set<T>& operator =(const Set<T>& rtSide);

    virtual ~Set();

private:
    T* elements;
    int _size;
    int memory;
    void incrementMemory(int additionalMemory);
};

int main(){
    Set<int> intSet;
    intSet.add(1);
    intSet.add(8);
    intSet.add(5);
    intSet.add(3);
    intSet.add(2);
    intSet.add(10);

    intSet.print();

    return(0);
}

template<class T>
Set<T>::Set(): elements(nullptr), _size(0), memory(5){
    elements = new T[memory];
}

template<class T>
Set<T>::Set(const Set<T>& setObj): 
elements(nullptr), _size(setObj._size), memory(setObj.memory){
    elements = new T[memory];
    int i;
    for(i = 0; i < _size; ++i)
        elements[i] = setObj.elements[i];
}

template<class T>
void Set<T>::add(const T& element){
    if(_size >= memory)
        incrementMemory(5);
    elements[_size++] = element;
}

template<class T>
int Set<T>::size() const{return _size;}

template<class T>
Set<T>& Set<T>::operator =(const Set<T>& rtSide){
    if(memory != rtSide.memory){
        delete [] elements;
        memory = rtSide.memory;
    }
    _size = rtSide._size;
    int i;
    for(i = 0; _size; ++i)
        elements[i] = rtSide.elements[i];

    (*this);
}

template<class T>
void Set<T>::incrementMemory(int additionalMemory){
    T *newElementsP = new T[memory + additionalMemory];
    int i;
    for(i = 0; i < _size; ++i)
        newElementsP[i] = elements[i];
    
    delete [] elements;
    elements = newElementsP;
    memory += additionalMemory;
}

template<class T>
void Set<T>::print() const{
    cout << "{";
    int i;
    for(i = 0; i < _size - 1; ++i)
        cout << "'" << elements[i] << "'" << ", ";
    
    cout << "'" << elements[_size - 1] << "'" << "}\n";
}

template <class T>
Set<T>::~Set(){
    delete [] elements;
}