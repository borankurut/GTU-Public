#include "and.h"

#include <iostream> // delete
using namespace std;

And::And(Token* newIn0, Token* newIn1, Token* out):
    Gate(newIn0, newIn1, out){/*empty*/}

void And::evaluate(){
    output->val = in0->val && in1->val; // output value is the anded inputs
}