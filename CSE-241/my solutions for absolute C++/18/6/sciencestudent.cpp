#include <iostream>
#include <string>
#include "sciencestudent.h"
#include "InvalidDataError.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;
using namespace UniversityStaffKurut;

int main(){
    try{
        ScienceStudent boran("gtu", -1, UniversityStaff("guy"), "comp", "graduate");
    }
    catch(InvalidDataError e){
        cout << e.message();
    }

    return(0);
}

namespace UniversityStaffKurut{
    ScienceStudent::ScienceStudent(): Student(), 
    scienceDiciplin("no diciplin yet"), course("no course yet"){/**/}
    
    ScienceStudent::ScienceStudent(string theUniversityName, int theRegistNum, 
        const UniversityStaff& theProctor,
        string theScienceDiciplin, string theCourse):
            Student(theUniversityName, theRegistNum, theProctor),
            scienceDiciplin(theScienceDiciplin), course(theCourse)
        {
            if(theCourse != "undergraduate" && theCourse != "postgraduate")
                throw InvalidDataError(theRegistNum, theCourse, 
                    "science students either undergraduate or postgraduate.");
        }


    ScienceStudent::ScienceStudent(const ScienceStudent& scienceStudentObj):
        Student(scienceStudentObj.getUniversityName(), 
            scienceStudentObj.getRegitsNum(),
            scienceStudentObj.getProctor()), 
        scienceDiciplin(scienceStudentObj.scienceDiciplin),
        course(scienceStudentObj.course){/**/}

    string ScienceStudent::getScienceDiciplin(){
        return scienceDiciplin;
    }

    string ScienceStudent::getCourse(){
        return course;
    }


    void ScienceStudent::setScienceDiciplin(string newScienceDiciplin){
        scienceDiciplin = newScienceDiciplin;
    }

    void ScienceStudent::setCourse(string newCourse){
        course = newCourse;
    }


    ScienceStudent& ScienceStudent::operator=(const ScienceStudent& rtSide){
        setUniversityName(rtSide.getUniversityName());
        setRegistNum(rtSide.getRegitsNum());
        setProctor(rtSide.getProctor());
        scienceDiciplin = rtSide.scienceDiciplin;
        course = rtSide.course;
        return(*this);
    }

    ostream& operator <<(ostream& outputStream, const ScienceStudent& scienceStudentObject){
        outputStream << "University Name: " << scienceStudentObject.getUniversityName() << endl
                    <<  "Registration num: " << scienceStudentObject.getRegitsNum() << endl
                    <<  "Proctor: "  << scienceStudentObject.getProctor() << endl
                    <<  "Science Diciplin: " << scienceStudentObject.scienceDiciplin << endl
                    <<  "Course: " << scienceStudentObject.course;

        return(outputStream);
    }

    istream& operator >>(istream& inputStream, ScienceStudent& scienceStudentObject){
        string universityName;
        int registNum;
        UniversityStaff proctor;

        cin >> universityName >> registNum >> proctor
        >> scienceStudentObject.scienceDiciplin
        >> scienceStudentObject.course;

        scienceStudentObject.setUniversityName(universityName);
        scienceStudentObject.setRegistNum(registNum);
        scienceStudentObject.setProctor(proctor);

        return(inputStream);
    }
}