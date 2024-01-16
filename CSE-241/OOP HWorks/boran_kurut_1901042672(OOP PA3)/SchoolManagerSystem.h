#ifndef SCHOOLMANAGERSYSTEM_H
#define SCHOOLMANAGERSYSTEM_H
#include "Course.h"
#include "Student.h"

#include <iostream>
using std::string;

namespace PA3{
    class SchoolManagerSystem
    {
    private:
        Course * courseRefs;    // dynamically allocated Course array.
        Student * studentRefs;  // dynamically allocated Student array.
        int courseRefSize;      // course size
        int studentRefSize;     // student size

    public:
        SchoolManagerSystem();
        void addStudent(const Student& student);
        void addStudent(string name, int id);       

        void add_student(); // gets a student from cin and adds it

        // gets student from cin and returns reference if it exist in SchoolManagerSystem
        Student& select_student();  

        void addCourse(const Course& course);   
        void addCourse(string name, string code);

        void add_course();      // gets a course from cin and adds it

        //gets course from cin and returns reference if it exist in SchoolManagerSystem
        Course& select_course();

        // deletes the student
        void deleteStudent(Student& student);

        // deletes the course
        void deleteCourse(Course& course);

        Student& getStudent(const Student& toGetStudent);
        Course& getCourse(const Course& toGetCourse);
        Course& getCourse(int ix);

        int courseIx(const Course& course) const;   // returns the given course index or -1
        int studentIx(const Student& student) const;// returns the given student index or -1

        void print() const; // prints data for debug purposes

        void listAllStudents() const;

        void listAllCourses() const;

        // menu functions returns choice.
        int menu() const;

        int studentMenu() const;

        int courseMenu() const;

        int selectStudentMenu() const;

        int selectCourseMenu() const;

        ~SchoolManagerSystem();// destructor
    };

}//PA3
#endif