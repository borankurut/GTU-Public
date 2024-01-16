#include "token.h"

ostream& operator<<(ostream& out, const Token& token){
    out << token.name << ": " << token.val;
    return out;
}