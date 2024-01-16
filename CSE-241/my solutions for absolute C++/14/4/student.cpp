#include <iostream>
#include <string>
#include "student.h"

using std::cin;
using std::cout;
using std::endl;
using std::istream;
using std::ostream;
using std::string;


namespace UniversityStaffKurut{
    
    Student::Student():
        universityName("no university name yet"), registNum(0),
        proctor(UniversityStaff()){/**/}

    Student::Student(string theUniversityName, int theRegistNum, const UniversityStaff& theProctor):
        universityName(theUniversityName), registNum(theRegistNum),
        proctor(theProctor){/**/}

    Student::Student(const Student& theObject){
        universityName = theObject.universityName;
        registNum = theObject.registNum;
        proctor = theObject.proctor;
    }

    string Student::getUniversityName() const{
        return universityName;
    }

    int Student::getRegitsNum() const{
        return registNum;
    }

    const UniversityStaff& Student::getProctor() const{
        return proctor;
    }


    void Student::setUniversityName(string newUniversityName){
        universityName = newUniversityName;
    }

    void Student::setRegistNum(int newRegistNum){
        registNum = newRegistNum;
    }

    void Student::setProctor(const UniversityStaff& newProctor){
        proctor = newProctor;
    }


    Student& Student::operator=(const Student& rtSide){
        universityName = rtSide.universityName;
        registNum = rtSide.registNum;
        proctor = rtSide.proctor;

        return(*this);
    }

    ostream& operator <<(ostream& outputStream, const Student& student){
        outputStream << "University Name: " << student.universityName << endl
                    <<  "Registration number: " << student.registNum << endl
                    <<  "Proctor: " << student.proctor;
        return (outputStream);
    }

    istream& operator >>(istream& inputStream, Student& student){
        inputStream >> student.universityName >> student.registNum 
                    >> student.proctor;

        return(inputStream);
    }
}