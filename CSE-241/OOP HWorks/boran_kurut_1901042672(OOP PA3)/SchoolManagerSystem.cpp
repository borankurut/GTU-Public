#include "SchoolManagerSystem.h"
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace PA3{

    SchoolManagerSystem::SchoolManagerSystem():
        studentRefs(nullptr), courseRefs(nullptr),
        studentRefSize(0), courseRefSize(0){/**/}

    SchoolManagerSystem::~SchoolManagerSystem()
    {
        delete[] studentRefs;
        delete[] courseRefs;
    }

    void SchoolManagerSystem::addStudent(const Student& student){
        // updates the reference array of student and size with added student.
        Student * newRef = new Student[studentRefSize + 1];
        for(int i = 0; i < studentRefSize; ++i)
            newRef[i] = studentRefs[i]; 

        newRef[studentRefSize] = student;
        studentRefSize++;

        delete [] studentRefs;
        studentRefs = newRef;
    }

    void SchoolManagerSystem::addStudent(string name, int id){
        addStudent(Student(name, id));
    }

    void SchoolManagerSystem::addCourse(const Course& course){
        // updates the reference array of course and size with added course.
        Course * newRef = new Course[courseRefSize + 1];
        for(int i = 0; i < courseRefSize; ++i)
            newRef[i] = courseRefs[i]; // may need assignment overload.

        newRef[courseRefSize] = course;
        courseRefSize++;

        delete [] courseRefs;
        courseRefs = newRef;
    }

    void SchoolManagerSystem::addCourse(string name, string code){
        addCourse(Course(name, code));
    }

    Student& SchoolManagerSystem::getStudent(const Student& toGetStudent){
        int studentix = studentIx(toGetStudent);
        if(studentix != -1)
            return studentRefs[studentix];
        else{
            cout << ("no such student") << endl;
            exit(0);
        }
    }

    Course& SchoolManagerSystem::getCourse(const Course& toGetCourse){
        int courseix = courseIx(toGetCourse);
        if(courseix != -1)
            return courseRefs[courseix];
        else{
            cout << ("no such course") << endl;
            exit(0);
        }
    }

    Course& SchoolManagerSystem::getCourse(int ix){
        return courseRefs[ix];    
    }

    int SchoolManagerSystem::courseIx(const Course& course) const{
        int ix = -1;

        for(int i = 0; i < courseRefSize; ++i)
            if(courseRefs[i] == course)
                ix = i;

        return ix;
    }

    int SchoolManagerSystem::studentIx(const Student& student) const{
        bool ix  = -1;

        for(int i = 0; i < studentRefSize; ++i)
            if(studentRefs[i] == student)
                ix = i;
                
        return ix;
    }

    void SchoolManagerSystem::print() const{
        for(int i = 0; i < studentRefSize; ++i)
            studentRefs[i].print();
        cout << endl;
        for(int i = 0; i < courseRefSize; ++i)
            courseRefs[i].print();
    }

    void SchoolManagerSystem::add_student(){
        Student to_add;
        cin >> to_add;
        addStudent(to_add);
    }

    Student& SchoolManagerSystem::select_student(){
        Student to_select;
        cin >> to_select;
        return getStudent(to_select);
    }

    void SchoolManagerSystem::add_course(){
        Course to_add;
        cin >> to_add;
        addCourse(to_add);
    }

    Course& SchoolManagerSystem::select_course(){
        Course to_select;
        cin >> to_select;
        return getCourse(to_select);
    }

    void SchoolManagerSystem::deleteStudent(Student& student){
        // drops the student from all courses
        for(int i = 0; i < courseRefSize; ++i)
            courseRefs[i].dropStudent(student);

        int stuix = studentIx(student);

        // shift all references from student index to last element
        if(stuix != -1){
            for(int i = stuix; i < studentRefSize - 1; ++i){
                studentRefs[i] = studentRefs[i+1];
            }
            // delete duplicated last element
            delete &studentRefs[studentRefSize - 1];
            // reduce size.
            studentRefSize -= 1;
        }
    }

    void SchoolManagerSystem::deleteCourse(Course& course){
        //drop the course for each student

        for(int i = 0; i < studentRefSize; ++i)
            studentRefs[i].dropCourse(course);
        int courseix = courseIx(course);

        if(courseix != -1){
            // shift elements to left, delete rightmost.
            for(int i = courseix; i < courseRefSize - 1; ++i){
                courseRefs[i] = courseRefs[i+1];
            }
            delete &courseRefs[courseRefSize - 1];
            courseRefSize -= 1;
        }
    }

    void SchoolManagerSystem::listAllStudents() const{
        for(int i = 0; i < studentRefSize; ++i)
            cout << i+1 << ": " << studentRefs[i] << endl;
    }

    void SchoolManagerSystem::listAllCourses() const{
        for(int i = 0; i < courseRefSize; ++i)
            cout << i+1 << ": " <<  courseRefs[i] << endl;
    }

    int SchoolManagerSystem::menu() const{
        int choice;
        cout << "Main Menu\n0 exit\n1 student\n2 course\n3 list_all_students\n4 list_all_courses\n>>";
        cin >> choice;
        return choice;
    }

    int SchoolManagerSystem::studentMenu() const{
        int choice;
        cout << "0 up\n1 add_student\n2 select_student\n>>";
        cin >> choice;
        return choice;
    }

    int SchoolManagerSystem::selectStudentMenu() const{
        int choice;
        cout << "0 up\n1 delete_student\n"
        <<  "3 add_selected_student_to_a_course\n"
        <<  "4 drop_selected_student_from_a_course\n>>";
        cin >> choice;
        return choice;
    }

    int SchoolManagerSystem::courseMenu() const{
        int choice;
        cout << "0 up\n1 add_course\n2 select_course\n>>";
        cin >> choice;
        return choice;
    }

    int SchoolManagerSystem::selectCourseMenu() const{
        int choice;
        cout << "0 up\n1 delete_course\n"
        << "2 list_students_registered_to_the_selected_course\n>>";
        cin >> choice;
        return choice;
    }

}//PA3