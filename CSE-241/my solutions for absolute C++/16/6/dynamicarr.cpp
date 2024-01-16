#include <iostream>
#include <string>

using namespace std;

template<class T>
class DynamicArray
{

public:
    DynamicArray();
    DynamicArray(const DynamicArray<T>& dsaObj);
    ~DynamicArray();
    void addEntry(T entry);
    int getSize() const;
    int indexOf(T element);
    bool deleteEntry(T entry);
    T getEntry(int index);
    DynamicArray<T>& operator=(const DynamicArray<T>& rightSide);

    template<class U> 
    friend ostream& operator<<(ostream& outputStream, const DynamicArray<U>& obj);


private:
    T* arr;
    int size;

};

int main(){
    DynamicArray<string> my;
    my.addEntry("rick");
    my.addEntry("morty");
    my.addEntry("wubba");

    cout << my << endl;

    DynamicArray<string> your;
    your = my;
    cout << your << endl;

    my.deleteEntry("morty");
    cout << my << endl;
    cout << your << endl;

    DynamicArray<int> myInt;
    DynamicArray<int> yourInt;

    myInt.addEntry(1);
    myInt.addEntry(2);
    myInt.addEntry(3);

    yourInt.addEntry(4);
    yourInt.addEntry(5);
    yourInt.addEntry(6);

    cout << myInt << endl
        <<  yourInt << endl;

    return(0);
}

template<class T>
DynamicArray<T>::DynamicArray(): arr(nullptr), size(0){/*empty*/}

template<class T>
DynamicArray<T>::DynamicArray(const DynamicArray<T>& dsaObj){
    size = dsaObj.size;
    arr = new T[size];
    int i;
    for(i = 0; i < size; ++i)
        arr[i] = dsaObj.arr[i];
}

template<class T>
DynamicArray<T>::~DynamicArray(){
    delete [] arr;
}

template<class T>
void DynamicArray<T>::addEntry(T entry){
    T *newArray = new T[size + 1];

    int i;
    for(i = 0; i < size; ++i)
        newArray[i] = arr[i];

    newArray[size] = entry;

    delete [] arr;
    arr = newArray;

    ++size;
}

template<class T>
int DynamicArray<T>::getSize() const{
    return(size);
}

template<class T>
int DynamicArray<T>::indexOf(T element){
    int index = -1;
    int i;
    for(i = 0; i < size; ++i)
        if(arr[i] == element){
            index = i;
            break;
        }
    return(index);
}

template<class T>
bool DynamicArray<T>::deleteEntry(T entry){
    if(indexOf(entry) == -1)
        return(false);
       
    T *newArray = new T[size - 1];

    int i;
    int j = 0;
    for(i = 0; i < size; ++i)
        if(arr[i] != entry)
            newArray[j++] = arr[i];

    delete [] arr;
    arr = newArray;
    --size;

    return(true);
}

template<class T>
T DynamicArray<T>::getEntry(int index){
    if(index < 0 || index >= size){
        cout << "index out of range in getEntry()\n";
        exit(1);
    }
    else
        return(arr[index]);
}

template<class T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& rightSide){
    if(size != rightSide.size){
        size = rightSide.size;
        delete [] arr;
        arr = new T[size];
    }
    int i;
    for(i = 0; i < size; ++i)
        arr[i] = rightSide.arr[i];

    return(*this);
}

template<class T>
ostream& operator<<(ostream& outputStream, const DynamicArray<T>& obj){
    outputStream << "{";
    int i;
    for(i = 0; i < obj.size; ++i)
        if(i != obj.size - 1)
            outputStream << "'" << obj.arr[i] << "'" << ", ";
        else
            outputStream << "'" << obj.arr[i] << "'";
    outputStream << "}";

    return(outputStream);
}