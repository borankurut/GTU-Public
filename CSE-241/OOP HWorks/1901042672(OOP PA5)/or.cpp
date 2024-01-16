#include "or.h"

Or::Or(Token* newIn0, Token* newIn1, Token* out):
    Gate(newIn0, newIn1, out){/*empty*/}

void Or::evaluate(){
    output->val = in0->val || in1->val; // output value is the 'or'ed inputs
}