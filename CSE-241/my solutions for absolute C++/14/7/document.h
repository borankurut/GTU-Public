#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <string>

using std::string;

namespace KurutDocument{
    class Document{

    public:
        Document();
        Document(const string& theText);

        void setText(const string& newText);
        string getText() const;
        
        Document& operator=(const Document& rtSide);

    private:
        string text;
    };

    bool ContainsKeyword(const Document& docObject, string keyword);
}

#endif