#include <iostream>
#include <string>

using namespace std;

class DynamicStringArray
{

public:
    DynamicStringArray();
    DynamicStringArray(const DynamicStringArray& dsaObj);
    ~DynamicStringArray();
    void addEntry(string entry);
    int getSize() const;
    int indexOf(string element);
    bool deleteEntry(string entry);
    string getEntry(int index);
    DynamicStringArray& operator=(const DynamicStringArray& rightSide);
    friend ostream& operator<<(ostream& outputStream, const DynamicStringArray& obj);


private:
    string* dynamicArray;
    int size;

    static string nullString;
    
};

string DynamicStringArray::nullString = "null";


int main(){
    DynamicStringArray my;
    my.addEntry("rick");
    my.addEntry("morty");
    my.addEntry("wubba");

    cout << my << endl;

    DynamicStringArray your;
    your = my;
    cout << your << endl;

    my.deleteEntry("morty");
    cout << my << endl;
    cout << your << endl;



    return(0);
}

DynamicStringArray::DynamicStringArray(): dynamicArray(nullptr), size(0){/*empty*/}

DynamicStringArray::DynamicStringArray(const DynamicStringArray& dsaObj){
    size = dsaObj.size;
    dynamicArray = new string[size];
    int i;
    for(i = 0; i < size; ++i)
        dynamicArray[i] = dsaObj.dynamicArray[i];
}

DynamicStringArray::~DynamicStringArray(){
    delete [] dynamicArray;
}

void DynamicStringArray::addEntry(string entry){
    string *newArray = new string[size + 1];

    int i;
    for(i = 0; i < size; ++i)
        newArray[i] = dynamicArray[i];

    newArray[size] = entry;

    delete [] dynamicArray;
    dynamicArray = newArray;

    ++size;
}

int DynamicStringArray::getSize() const{
    return(size);
}

int DynamicStringArray::indexOf(string element){
    int index = -1;
    int i;
    for(i = 0; i < size; ++i)
        if(dynamicArray[i] == element){
            index = i;
            break;
        }
    return(index);
}

bool DynamicStringArray::deleteEntry(string entry){
    if(indexOf(entry) == -1)
        return(false);
       
    string *newArray = new string[size - 1];

    int i,
        j = 0;
    for(i = 0; i < size; ++i){
        if(i != indexOf(entry))
            newArray[j++] = dynamicArray[i];
    }

    delete [] dynamicArray;
    dynamicArray = newArray;
    --size;

    return(true);
}

string DynamicStringArray::getEntry(int index){
    if(index < 0 || index >= size)
        return(nullString);
    else
        return(dynamicArray[index]);
}

DynamicStringArray& DynamicStringArray::operator=(const DynamicStringArray& rightSide){
    if(size != rightSide.size){
        size = rightSide.size;
        delete [] dynamicArray;
        dynamicArray = new string[size];
    }
    int i;
    for(i = 0; i < size; ++i)
        dynamicArray[i] = rightSide.dynamicArray[i];

    return(*this);
}

ostream& operator<<(ostream& outputStream, const DynamicStringArray& obj){
    outputStream << "{";
    int i;
    for(i = 0; i < obj.size; ++i)
        if(i != obj.size - 1)
            outputStream << "'" << obj.dynamicArray[i] << "'" << ", ";
        else
            outputStream << "'" << obj.dynamicArray[i] << "'";
    outputStream << "}";

    return(outputStream);
}

