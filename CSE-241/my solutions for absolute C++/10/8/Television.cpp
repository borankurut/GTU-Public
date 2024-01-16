#include <iostream>

using namespace std;

class DynamicStringArray
{

public:
    DynamicStringArray();
    DynamicStringArray(const string array[], int arrSize);
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

class Television
{

public:
    Television();
    void setDisplayType(string newDisplayType);
    void setDimension(double newDimension);
    void setConnectivitySupport(const DynamicStringArray& newConnectivity);
    string getDisplayType() const;
    double getDimension() const;
    const DynamicStringArray& getConnectivitySupport() const;

    void display();

private:
    string displayType;                         // display type of the television
    double dimension;                           // stores the dimension of the television in inches.
    DynamicStringArray connectivitySupport;     // connectivity modes supported by the television.
};

string DynamicStringArray::nullString = "null";

int main(){
    Television myTv;
    string consup[] = {"sup1", "sup2", "sup3"};
    DynamicStringArray connectivity(consup, 3);

    myTv.display();
    cout << endl;

    myTv.setDimension(2.0);
    myTv.setDisplayType("Lcd");
    myTv.setConnectivitySupport(connectivity);
    myTv.display();
    return(0);
}

Television::Television(){
    displayType = "Null";
    dimension = 0.0;
}


void Television::setDisplayType(string newDisplayType){
    displayType = newDisplayType;
}

void Television::setDimension(double newDimension){
    dimension = newDimension;
}

void Television::setConnectivitySupport(const DynamicStringArray& newConnectivity){
    connectivitySupport = newConnectivity;
}

string Television::getDisplayType() const{
    return(displayType);
}

double Television::getDimension() const{
    return(dimension);
}

const DynamicStringArray& Television::getConnectivitySupport() const{
    return(connectivitySupport);
}

void Television::display(){
    cout << "display type: " << displayType << endl
        <<  "dimension: " << dimension << endl
        <<  "connectivitySupport: " << connectivitySupport << endl;
}




DynamicStringArray::DynamicStringArray(): dynamicArray(nullptr), size(0){/*empty*/}

DynamicStringArray::DynamicStringArray(const string array[], int arrSize){
    size = arrSize;
    dynamicArray = new string[size];
    int i; 
    for(i = 0; i < size; ++i)
        dynamicArray[i] = array[i];
}

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