#include "person.h"
#include <string>

using std::string;
using std::istream;
using std::ostream;
using std::cin;
using std::cout;

namespace KurutClinic{
    Person::Person(): name(""){/**/}

    Person::Person(string theName): name(theName){/**/}

    Person::Person(const Person& personObj): name(personObj.name){/**/}

    Person& Person::operator=(const Person& rtSide){
        name = rtSide.name;
    }

    string Person::getName() const{
        return name;
    }

    void Person::setName(string newName){
        name = newName;
    }

    ostream& operator <<(ostream& outputStream, const Person& personObj){
        outputStream << personObj.name;
        return(outputStream);
    }

    istream& operator >>(istream& inputStream, Person& personObj){
        inputStream >> personObj.name;
        return(inputStream);
    }
}