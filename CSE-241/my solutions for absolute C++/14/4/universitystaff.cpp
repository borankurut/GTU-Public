#include <iostream>
#include <string>
#include "universitystaff.h"

using std::cout;
using std::cin;
using std::istream;
using std::ostream;
using std::endl;

namespace UniversityStaffKurut{
    UniversityStaff::UniversityStaff(): name(""){/**/}
    UniversityStaff::UniversityStaff(string theName):
        name(theName){/**/}
    UniversityStaff::UniversityStaff(const UniversityStaff& theObject):
        name(theObject.name){/**/}
    
    string UniversityStaff::getName() const{
        return name;
    }

    UniversityStaff& UniversityStaff::operator=(const UniversityStaff& rtSide){
        name = rtSide.name;
        return(*this);
    }

    istream& operator >>(istream& inputStream, UniversityStaff& staffObject){
        inputStream >> staffObject.name;
        return(inputStream);
    }

    ostream& operator <<(ostream& outputStream, const UniversityStaff& staffObject){
        outputStream << "Staff name: " << staffObject.name;
        return(outputStream);
    }
}