#include "flipflop.h"

Flipflop::Flipflop(Token* newIn0, Token* out):
    Component(newIn0, out)
{
    output->val = 0; // flipflop former output is zero 
}

void Flipflop::evaluate(){
    output->val = (output->val || in0->val) && (output->val != in0->val); 
    // former output xor input (from truth table)
}