#ifndef UNIVERSITYSTAFF_H
#define UNIVERSITYSTAFF_H

#include <string>
#include <iostream>

using std::string;
using std::istream;
using std::ostream;

namespace UniversityStaffKurut{
    class UniversityStaff{
    public: 
        UniversityStaff();
        UniversityStaff(string theName);
        UniversityStaff(const UniversityStaff& theObject);
        string getName() const;
        UniversityStaff& operator=(const UniversityStaff& rtSide);
        
        friend istream& operator >>(istream& inputStream, UniversityStaff& staffObject);
        friend ostream& operator <<(ostream& outputStream, const UniversityStaff& staffObject);
    private:
        string name;
    };
}

#endif