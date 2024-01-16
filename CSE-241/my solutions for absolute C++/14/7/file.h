#ifndef FILE_H
#define FILE_H

#include "document.h"
#include <string>

using std::string;

namespace KurutDocument{
    class File: public Document{

    public:
        File();
        File(const string& theText, const string& thePathName);

        void setPathName(const string& newPathName);
        string getPathName() const;

        File& operator=(const File& rtSide);
        
    private:  
        string pathName;
    };
}

#endif