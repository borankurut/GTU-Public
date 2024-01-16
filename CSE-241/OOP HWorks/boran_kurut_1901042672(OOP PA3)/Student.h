#ifndef STUDENT_H
#define STUDENT_H

#include "Course.h"
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

namespace PA3{
    class Course;

    class Student
    {
    private:
        string name;        // name of the student
        int id;             // id of the student
        Course** courseRefs;// course references(dynamically allocated pointer array)
        int courseRefSize;  // reference size
        friend class Course;// Student class can use Course data
        
    public:
        Student(string newName, int newId); // constructors
        Student();

        ~Student(); //destructor

        //getters setters
        string getName() const;
        void setName(string newName);

        int getId() const;
        void setId(int newId);

        void assignCourse(Course& course);  // assigns a course to student
        void dropCourse(Course& course);    // student drops the course

        bool isIn(const Course& course) const;  // return whether student is in course

        void print() const;         // print data for debug purposes

        friend bool operator==(const Student& op1, const Student& op2); // == overlaod

        friend bool operator!=(const Student& op1, const Student& op2); // != overlaod

        friend istream& operator>>(istream& in, Student& student);
        // >> overlaod: expects for a name and then integer

        friend ostream& operator<<(ostream& out, const Student& student);
        // << overlaod
    };
}//PA3

#endif