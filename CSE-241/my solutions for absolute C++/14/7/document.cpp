#include <string>
#include "document.h"

using std::string;

namespace KurutDocument{
    Document::Document(): text(""){/**/}
    Document::Document(const string& theText): text(theText){/**/}

    void Document::setText(const string& newText) {text = newText;}

    string Document::getText() const {return text;}

    Document& Document::operator=(const Document& rtSide) {
        text = rtSide.text;
        return(*this);
    }

    bool ContainsKeyword(const Document& docObject, string keyword)
    {
        if (docObject.getText().find(keyword) != string::npos)
        return true;
        return false;
    }

}
