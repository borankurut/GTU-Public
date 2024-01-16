#include "Student.h"
#include "Course.h"
#include "SchoolManagerSystem.h"
#include <iostream>

using namespace std;
using namespace PA3;

int main(){
    SchoolManagerSystem system;

    int choice = system.menu();

    while(choice != 0){
        if(choice == 1){
            choice = system.studentMenu();
            while(choice != 0){     // student menu
                if(choice == 1){
                    cout << ">>";
                    system.add_student();
                }
                if(choice == 2){    // select student
                    system.listAllStudents();

                    cout << ">>";
                    Student& s = system.select_student();
                    choice = system.selectStudentMenu();

                    if (choice == 0)
                        break;
                    else if(choice == 1){
                        system.deleteStudent(s);
                    }
                    else if(choice == 3){
                        system.listAllCourses();
                        cout << ">>";
                        int courseIx;
                        cin >> courseIx;
                        Course &c = system.getCourse(courseIx - 1);
                        s.assignCourse(c);
                    }
                    else if(choice == 3){
                        system.listAllCourses();
                        cout << ">>";
                        Course &c = system.select_course();
                        s.dropCourse(c);
                    }
                }
                choice = system.studentMenu();
            }
        }
        else if(choice == 2){
            choice = system.courseMenu();
            while(choice != 0){ // Course Menu
                if(choice == 1){
                    cout << ">>";
                    system.add_course();
                }
                else if(choice == 2){ // Select course
                    system.listAllCourses();

                    cout << ">>";
                    Course& c = system.select_course();
                    choice = system.selectCourseMenu();

                    if (choice == 0)
                        break;
                    else if(choice == 1){
                        system.deleteCourse(c);
                    }
                    else if(choice == 2){
                        c.printRegistered();
                    }
                }

                choice = system.courseMenu();
            }
        }
        else if(choice == 3){
            system.listAllStudents();
        }
        else if(choice == 4){
            system.listAllCourses();
        }
        choice = system.menu();
    }

    return 0;
}