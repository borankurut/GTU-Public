#ifndef OR_H
#define OR_H

#include "gate.h"
#include "token.h"
#include <string>
class Or: public Gate{
public:
    Or(Token* newIn0, Token* newIn1, Token* out);
    void evaluate() override;
};

#endif
