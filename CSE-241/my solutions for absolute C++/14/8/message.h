#ifndef MESSAGE_H
#define MESSAGE_H

#include <iostream>
#include <string>


using std::string;
using std::ostream;

namespace KurutBlog{
    class Message{

    public:
        Message();
        Message(int theId);
        Message(string theContent);
        Message(int theId, string theContent);

        void setId(int newId);
        void setContent(string newContent);

        int getId() const;
        string getContent() const;

        friend ostream& operator<<(ostream& outputStr, const Message& message);

    private:
        int id;
        string content;
    };
}

#endif