#ifndef DECODER_H
#define DECODER_H
#include "gate.h"

class Decoder: public Gate
{
protected:
    Token* output1;     // has 3 more output values than gate.
    Token* output2;
    Token* output3;
    
public:
    Decoder(Token* newIn0, Token* newIn1, Token* out, Token* out1, Token* out2, Token* out3);
    void evaluate() override;

};


#endif