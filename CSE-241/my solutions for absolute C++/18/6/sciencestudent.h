#ifndef SCIENCESTUDENT_H
#define SCIENCESTUDENT_H

#include <iostream>
#include <string>
#include "student.h"

using std::string;
using std::istream;
using std::ostream;

namespace UniversityStaffKurut{
    class ScienceStudent: public Student{
    public:
        ScienceStudent();
        ScienceStudent(string theUniversityName, int theRegistNum, const UniversityStaff& theProctor,
            string theScienceDiciplin, string theCourse);
        ScienceStudent(const ScienceStudent& scienceStudentObj);

        string getScienceDiciplin();
        string getCourse();

        void setScienceDiciplin(string newScienceDiciplin);
        void setCourse(string newCourse);

        ScienceStudent& operator=(const ScienceStudent& rtSide);

        friend ostream& operator <<(ostream& outputStream, const ScienceStudent& scienceStudentObject);
        friend istream& operator >>(istream& inputStream, ScienceStudent& scienceStudentObject);

    private:
        string scienceDiciplin;
        string course;
    };
}

#endif