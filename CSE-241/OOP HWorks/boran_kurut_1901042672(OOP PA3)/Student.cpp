#include "Student.h"
#include "Course.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

namespace PA3{
    Student::Student():
        name(""), id(0), courseRefSize(0), courseRefs(nullptr){/**/}

    Student::Student(string newName, int newId):
        name(newName), id(newId), courseRefSize(0), courseRefs(nullptr){/**/}

    Student::~Student(){
        delete [] courseRefs;
    }

    string Student::getName() const{return name;}
    void Student::setName(string newName){name = newName;}

    int Student::getId() const{return id;}
    void Student::setId(int newId){id = newId;}

    void Student::assignCourse(Course& course){
        // same with the assignStudent
        // updates the references, calls new elements assign function.
        if(!isIn(course)){
            Course **newRef = new Course*[courseRefSize + 1];
            for(int i = 0; i < courseRefSize; ++i)
                newRef[i] = courseRefs[i];

            newRef[courseRefSize] = &course;
            courseRefSize++;
            delete[] courseRefs;
            courseRefs = newRef;
            
            courseRefs[courseRefSize-1]->assignStudent(*this);
        }
    }

    void Student::dropCourse(Course& course){
        // same with the dropStudent.
        if(isIn(course)){
            Course* to_drop;
            Course **newRef = new Course*[courseRefSize - 1];
            for(int i = 0; i < courseRefSize; ++i){
                if(*courseRefs[i] != course)
                    newRef[i] = courseRefs[i];
                else
                    to_drop = courseRefs[i];
            }
            courseRefSize--;
            delete[] courseRefs;
            courseRefs = newRef;

            to_drop->dropStudent(*this);
        }
    }

    bool Student::isIn(const Course& course) const{
        bool in = false;
        for(int i = 0; i < courseRefSize; ++i)
            if(*courseRefs[i] == course)
                in = true;

        return in;
    }

    bool operator==(const Student& op1, const Student& op2){
        bool same = true;
        for(int i = 0; i < op1.courseRefSize && i < op2.courseRefSize; ++i)
            if(op1.courseRefs[i] != op2.courseRefs[i])
                same = false;
        return op1.name == op2.name && op1.id == op2.id && same;
    }

    bool operator!=(const Student& op1, const Student& op2){
        return ! (op1 == op2);
    }

    void Student::print() const{
        cout << name << " " << id << " is in: ";
        for(int i = 0; i < courseRefSize; ++i)
            cout << courseRefs[i]->name << " " << courseRefs[i]->code;
    }

    istream& operator>>(istream& in, Student& student){
        string name, surname;
        int id;
        in >> name;
        in >> surname;
        in >> id;

        student = Student(name + " " + surname, id);

        return in;
    }

    ostream& operator<<(ostream& out, const Student& student){
        out << student.name << " " << student.id;
        return out;
    }   
}