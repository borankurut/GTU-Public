#ifndef FLIPFLOP_H
#define FLIPFLOP_H
#include "component.h"

class Flipflop : public Component
{
public:
    Flipflop(Token* newIn0, Token* out); 
    void evaluate() override;
};

#endif
