#include "Student.h"
#include "Course.h"
#include <iostream>

using std::string;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;

namespace PA3{
    Course::Course():
        name(""), code(""), studentRefSize(0), studentRefs(nullptr){/**/}


    Course::Course(string newName, string newCode): 
        name(newName), code(newCode), studentRefSize(0), studentRefs(nullptr){/**/}

    Course::~Course(){
        delete [] studentRefs;    
    }

    string Course::getName() const{return name;}
    void Course::setName(string newName){name = newName;}

    string Course::getCode() const{return code;}
    void Course::setCode(string newCode){code = newCode;}

    void Course::assignStudent(Student& student){
        if(!doesHave(student)){     // if student is not in this class.
            Student **newRef = new Student *[studentRefSize+ 1];    // 
            for(int i = 0; i < studentRefSize; ++i)                 // copy the studentRef to newRef
                newRef[i] = studentRefs[i];

            newRef[studentRefSize] = &student;      // add the student

            studentRefSize++;                       // increase ref size

            delete[] studentRefs;                   // delete old reference

            studentRefs = newRef;

            studentRefs[studentRefSize - 1]->assignCourse(*this); 
            // update the assigned student's course references.
        }
    }

    void Course::dropStudent(Student& student){
        if(doesHave(student)){      // checks whether student is in course
            Student* to_drop;       // back up of the student reference to drop course from

            // shift all elements right and save to_drop
            Student **newRef = new Student*[studentRefSize - 1];
            for(int i = 0; i < studentRefSize; ++i){
                if(*studentRefs[i] != student)
                    newRef[i] = studentRefs[i]; 
                else
                    to_drop = studentRefs[i];
            }

            // delete old reference, update size.
            studentRefSize--;
            delete[] studentRefs;
            studentRefs = newRef;

            to_drop->dropCourse(*this); //drop the course from backup student pointer.
        }
    }

    bool Course::doesHave(const Student& student) const{
        bool in = false;
        
        for(int i = 0; i < studentRefSize; ++i)
            if(*studentRefs[i] == student)
                in = true;

        return in;

    }

    void Course::print() const{     // prints the course and students in for debug purposes
        cout << "course: " << code << " " << name << endl;
        cout << "Students: " << endl;
        for(int i = 0; i < studentRefSize; ++i)
            cout << studentRefs[i]->name << " " << studentRefs[i]->id << endl;
        cout << endl;
    }

    void Course::printRegistered() const{   // prints the dereferenced students from pointer array
        for(int i = 0; i < studentRefSize; ++i){
            cout << i+1 << " :" << *studentRefs[i] << endl;
        }
    }

    bool operator==(const Course& op1, const Course& op2){ 
        bool same = true;
        for(int i = 0; i < op1.studentRefSize && i < op2.studentRefSize; ++i)
            if(op1.studentRefs[i] != op2.studentRefs[i])    // check all references same
                same = false; 
        return op1.name == op2.name && op1.code == op2.code && same;
    }

    bool operator!=(const Course& op1, const Course& op2){
        return !(op1 == op2);
    }

    istream& operator>>(istream& in, Course& course){
        string name;
        string code;
        in >> code; 
        char c;     
        in >> c; // first letter of name
        getline(in, name);
        name = c + name;        // c and name concatanated to prevent space in getline
        course = Course(name, code);

        return in;
    }
    ostream& operator<<(ostream& out, const Course& course){
        out << course.code << " " << course.name;
        return out;
    }
}