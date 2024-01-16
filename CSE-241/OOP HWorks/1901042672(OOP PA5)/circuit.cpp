#include "circuit.h"
#include <iostream>

using std::cout;
using std::endl;

Circuit::Circuit(){/**/}
Circuit::Circuit(const vector<Token>& inputs, const vector<Token>& newOutputs){
    for (const auto& i : inputs)
        variables.push_back(new Token(i));

    for (const auto& o : newOutputs)
        outputs.push_back(o);
}

Token* Circuit::getToken(const string& name){
    if(isIn(name)){
        for(auto* v : variables){
            if(v->name == name)
                return v;
        }
    }

    else{
        variables.push_back(new Token{name, false});
        return variables.back();
    }
}

bool Circuit::isIn(const string& name) const{
    for(const auto& v : variables)
        if(v->name == name)
            return true;

    return false;
}

void Circuit::printCircuit() const{
    for(const auto* v : variables)
        cout << *v << endl;       
}

void Circuit::printOutputs()const{
    for(const auto& o: outputs)
        cout << o.val << " ";
    cout << endl;
}

void Circuit::updateOutputs(){
    for(const auto* v : variables){
        for(auto& o: outputs){
            if(v->name == o.name)
                o.val = v->val;
        }
    }
}

// all components takes input and output tokens from the circuit data.

// if the components input or output name is the same with another components,
// then they refer to same token
void Circuit::addAnd(const string& in0, const string& in1, const string& out){
    And* newAnd = new And(getToken(in0), getToken(in1), getToken(out));
    components.push_back(newAnd);
}

void Circuit::addOr(const string& in0, const string& in1, const string& out){
    Or* newOr = new Or(getToken(in0), getToken(in1), getToken(out));
    components.push_back(newOr);
}

void Circuit::addDecoder(const string& in0, const string& in1, const string& out, 
        const string& out1, const string& out2, const string& out3)
{
    Decoder* newDecoder = new Decoder(getToken(in0), getToken(in1), getToken(out), 
        getToken(out1), getToken(out2), getToken(out3));
    components.push_back(newDecoder);
}

void Circuit::addFlipflop(const string& in0, const string& out){
    Flipflop* newF= new Flipflop(getToken(in0), getToken(out));
    components.push_back(newF);
}

void Circuit::addNot(const string& in0, const string& out){
    Not* newN= new Not(getToken(in0), getToken(out));
    components.push_back(newN);
}

void Circuit::addInput(const Token& in){
    inputs.push_back(in);
    getToken(in.name)->val = in.val;
}

void Circuit::addOutput(const Token& out){
    bool has = false;
    for(const auto& o: outputs)
        if(out.name == o.name)
            has = true;
    if(!has)
        outputs.push_back(out);
}

void Circuit::addInput(const string& in){
    addInput(Token{in, false});
}

void Circuit::addOutput(const string& out){
    addOutput(Token{out, false});
}

void Circuit::evaluate(){
    for(int i = 0; i < components.size(); ++i){
        Component* c = components[i];
        c->evaluate();
    }
    updateOutputs();
}

void Circuit::setInputs(const vector<bool>& newInputs){
    for(int i = 0; i < inputs.size(); ++i)
        getToken(inputs[i].name)->val = newInputs[i];
}

Circuit::~Circuit(){
    for(auto* c : components)
        delete c;
    for(auto* v : variables)
        delete v;
}