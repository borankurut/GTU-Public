#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
#include "universitystaff.h"

using std::string;
using std::istream;
using std::ostream;

namespace UniversityStaffKurut{
    class Student{
    public:
        Student();
        Student(string theUniversityName, int theRegistNum, const UniversityStaff& theProctor);
        Student(const Student& theObject);

        string getUniversityName() const;
        int getRegitsNum() const;
        const UniversityStaff& getProctor() const;

        void setUniversityName(string newUniversityName);
        void setRegistNum(int newRegistNum);
        void setProctor(const UniversityStaff& newProctor);

        Student& operator=(const Student& rtSide);

        friend ostream& operator <<(ostream& outputStream, const Student& student);
        friend istream& operator >>(istream& inputStream, Student& student);

    private:
        string universityName;
        int registNum;
        UniversityStaff proctor;
    };
}


#endif