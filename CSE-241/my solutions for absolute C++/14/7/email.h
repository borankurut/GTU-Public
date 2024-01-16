#ifndef EMAIL_H
#define EMAIL_H

#include "document.h"
#include <string>

using std::string;

namespace KurutDocument{
    class Email: public Document{
    public:
        Email();
        Email(const string& theText, const string& theSender,
                const string& theRecipient, const string& theTitle);
        
        void setSender(const string& newSender);
        void setRecipient(const string& newRecipient);
        void setTitle(const string& newTitle);

        string getSender() const;
        string getRecipient() const;
        string getTitle() const;

        Email& operator=(const Email& rtSide);

        void debugPrint() const;

    private:
        string sender;
        string recipient;
        string title;
    };
}

#endif