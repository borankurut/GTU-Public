#include "file.h"

namespace KurutDocument{
    File::File(): Document(), pathName(""){/**/}

    File::File(const string& theText, const string& thePathName):
        Document(theText), pathName(thePathName){/**/}

    void File::setPathName(const string& newPathName)
    {pathName = newPathName;}

    string File::getPathName() const
    {return pathName;}

    File& File::operator=(const File& rtSide){
        Document::operator=(rtSide);
        pathName = rtSide.pathName;
        return(*this);
    }
}
