#include "email.h"
#include <iostream> //debug.

using std::cout;    //debug.
using std::endl;    //debug.

namespace KurutDocument{
    Email::Email(): Document(), sender(""), recipient(""), title("")
    {/*empty*/}

    Email::Email(const string& theText, const string& theSender,
                const string& theRecipient, const string& theTitle):
            Document(theText), sender(theSender), 
            recipient(theRecipient), title(theTitle)
    {/*empty*/}

    void Email::setSender(const string& newSender)
    {sender = newSender;}

    void Email::setRecipient(const string& newRecipient)
    {recipient = newRecipient;}

    void Email::setTitle(const string& newTitle)
    {title = newTitle;}

    string Email::getSender() const
    {return sender;}

    string Email::getRecipient() const
    {return recipient;}

    string Email::getTitle() const
    {return title;}

    Email& Email::operator=(const Email& rtSide){
        Document::operator=(rtSide);
        sender = rtSide.sender;
        recipient = rtSide.recipient;
        title = rtSide.title;
        return(*this);
    }

    void Email::debugPrint() const{
        cout << getText() << endl;
        cout << getSender() << endl;
        cout << getRecipient() << endl;
        cout << getTitle() << endl;
    }
}