#ifndef NOT_H
#define NOT_H

#include "component.h"

class Not : public Component
{
public:
    Not(Token* newIn0, Token* out);
    void evaluate() override;
};


#endif
