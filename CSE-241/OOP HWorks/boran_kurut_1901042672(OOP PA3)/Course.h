#ifndef COURSE_H
#define COURSE_H

#include "Student.h"
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

namespace PA3{
    class Student;

    class Course
    {
    private:
        string name;            // name of the class
        string code;            // code of the class
        Student** studentRefs;  // student references(dynamically allocated pointer arrays)
        int studentRefSize;     // size of references
        friend class Student;   // Course can use student data
        
    public:
        Course(/* args */);                     //constructors
        Course(string newName, string newCode);

        ~Course();                              // destructor

        string getName() const;             // returns the name of the course
        void setName(string newName);       // sets name 

        string getCode() const;             // returns the code of the course
        void setCode(string newCode);       // sets code

        void assignStudent(Student& student);   // assign Student to the course
        void dropStudent(Student& student);     // drop Student from course

        bool doesHave(const Student& student) const;    // return whether student is in course

        void print() const;     // print the information for debug purposes.

        void printRegistered() const;       // print the students registered to this course

        friend bool operator==(const Course& op1, const Course& op2);   // == overload
        
        friend bool operator!=(const Course& op1, const Course& op2);   // != overload

        friend istream& operator>>(istream& in, Course& course);        
        // >> expects code and then name to assign into course object

        friend ostream& operator<<(ostream& out, const Course& course);
        // << overload.
    };
}//PA3

#endif