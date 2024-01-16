#include "not.h"

Not::Not(Token* newIn0, Token* out):
    Component(newIn0, out){/**/}

void Not::evaluate(){
    output->val = !in0->val;
}
