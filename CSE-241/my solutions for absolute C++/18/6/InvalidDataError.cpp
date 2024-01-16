#include "InvalidDataError.h"
#include <string>

using std::string;

namespace UniversityStaffKurut{
    InvalidDataError::InvalidDataError(int theId, string theCourse, string theMsg):
        id(theId), course(theCourse), msg(theMsg){}

    string InvalidDataError::message() const{
        return ("object with id " + std::to_string(id) +
        " and course: " + course + " is invalid because " + msg);
    }
}