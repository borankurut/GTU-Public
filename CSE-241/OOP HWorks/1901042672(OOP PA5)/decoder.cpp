#include "decoder.h"
Decoder::Decoder(Token* newIn0, Token* newIn1, Token* out, Token* out1, Token* out2, Token* out3):
    Gate(newIn0, newIn1, out), output1(out1), output2(out2), output3(out3){/*empty*/} 
// sets token pointer values

void Decoder::evaluate(){       // decoder evaluation by truth table.
    if(in0->val == false && in1->val == false){
        output->val = 1;
        output1->val = 0;
        output2->val = 0;
        output3->val = 0;
    }
    else if(in0->val == false && in1->val == true){
        output->val = 0;
        output1->val = 1;
        output2->val = 0;
        output3->val = 0;
    }
    else if(in0->val == true && in1->val == false){
        output->val = 0;
        output1->val = 0;
        output2->val = 1;
        output3->val = 0;
    }
    else if(in0->val == true && in1->val == true){
        output->val = 0;
        output1->val = 0;
        output2->val = 0;
        output3->val = 1;
    }
}