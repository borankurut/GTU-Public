#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "component.h"
#include "token.h"
#include "and.h"
#include "or.h"
#include "flipflop.h"
#include "not.h"
#include "decoder.h"
#include <iostream>
#include <vector>
// all components included

using std::vector;

class Circuit{
public:
    vector<Token*> variables;       // variables are token pointers in order to input an output to another component
    vector<Token> outputs;
    vector<Token> inputs;
    
    vector<Component*> components; // components are pointer in order to use virtual functions

    Circuit(const vector<Token>& inputs, const vector<Token>& newOutputs);
    Circuit();
    ~Circuit(); // destructor (deletes all components and variables created)

    Token* getToken(const string& name); // returns token which named name. If there is not, creates it.
    bool isIn(const string& name) const; // returns if there is token which named name in variables.

    void addAnd(const string& in0, const string& in1, const string& out); // adds an and to the circuit
    void addOr(const string& in0, const string& in1, const string& out);  // ..
    void addNot(const string& in0, const string& out);                      //..
    void addFlipflop(const string& in0, const string& out);//..
    void addDecoder(const string& in0, const string& in1, const string& out, //..
        const string& out1, const string& out2, const string& out3);

    void printCircuit()const;   // prints all variables and values for debug purposes

    void addInput(const Token& in);     // adds an input to circuit
    void addOutput(const Token& out);   // adds an output to circuit

    void addInput(const string& in);
    void addOutput(const string& out);

    void printOutputs()const;       // prints all outputs by definition order.
    void updateOutputs();           // updates output values (to use after evaluation).

    void evaluate();                // evaluates all the components.

    void setInputs(const vector<bool>& newInputs); // sets input values from the newInputs vector

};

#endif