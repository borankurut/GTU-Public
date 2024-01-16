#include "gate.h"

Gate::Gate(Token* newIn0, Token* newIn1, Token* out):
    Component(newIn0, out), in1(newIn1){/*empty*/}