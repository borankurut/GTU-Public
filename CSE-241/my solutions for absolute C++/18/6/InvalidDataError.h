#include <string>

using std::string;

namespace UniversityStaffKurut{
    class InvalidDataError{
    public:
        InvalidDataError(int theId, string theCourse, string theMsg);
    
        string message() const;
    private:
        int id;
        string course;
        string msg;
    };
}