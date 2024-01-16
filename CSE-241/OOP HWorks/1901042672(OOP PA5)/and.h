#ifndef AND_H
#define AND_H

#include "gate.h"
#include "token.h"
#include <string>
class And: public Gate{
public:
    And(Token* newIn0, Token* newIn1, Token* out);
    void evaluate() override;
};

#endif