#ifndef TOKEN_H
#define TOKEN_H

#include <iostream>
using std::string;
using std::ostream;

class Token     // Token is a name value pair.
{
public:
    string name;    // name of the variable
    bool val;       // value of the variable
    friend ostream& operator<<(ostream& out, const Token& token); // prints the token (debug purposes)
};

#endif
