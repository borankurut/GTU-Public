#ifndef COMPONENT_H
#define COMPONENT_H

#include "token.h"
#include <iostream>

using std::string;

class Component     // component abstract class: gates, flipflop, not, decoder.
{
protected:
    Token* output;  // output
    Token* in0;     // input
public:
    Component(Token* newIn0, Token* out);
    virtual void evaluate() = 0;        // sets out token to evaluated output value
};

#endif
