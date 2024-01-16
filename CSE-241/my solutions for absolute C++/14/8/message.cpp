#include <iostream>
#include <string>
#include "message.h"

using std::string;
using std::ostream;

namespace KurutBlog{
    Message::Message(): id(0), content(""){/**/}
    Message::Message(int theId): id(theId), content(""){/**/}
    Message::Message(string theContent): id(0), content(theContent){/**/}
    Message::Message(int theId, string theContent): id(theId), content(theContent){/**/}

    void Message::setId(int newId){id = newId;}
    void Message::setContent(string newContent){content = newContent;}

    int Message::getId() const {return id;}
    string Message::getContent() const {return content;}

    ostream& operator<<(ostream& outputStr, const Message& message){
        outputStr << message.content;
        return outputStr;
    }

}