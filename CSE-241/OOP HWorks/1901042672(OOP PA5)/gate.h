#ifndef GATE_H
#define GATE_H

#include "component.h"
#include "token.h"

class Gate: public Component    // gates are components with 2 input
{
protected:
    Token* in1;     // second input
public:
    Gate(Token* newIn0, Token* newIn1, Token* out);


};
#endif
