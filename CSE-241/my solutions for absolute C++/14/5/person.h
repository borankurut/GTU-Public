#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using std::istream;
using std::ostream;
using std::string;

namespace KurutClinic{

    class Person{

    public:
        Person();
        Person(string theName);
        Person(const Person& personObj);

        Person& operator=(const Person& rtSide);

        string getName() const;
        void setName(string newName);

        friend ostream& operator <<(ostream& outputStream, const Person& personObj);
        friend istream& operator >>(istream& inputStream, Person& personObj);

    private:
        string name;
        
    };

}

#endif