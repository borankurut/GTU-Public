#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include "circuit.h"

using namespace std;

void createCircuit(Circuit& cir, const string& fileName); // create the circuit coded by fileName
void processLine(Circuit& cir, stringstream& ss);         // createCircuit helper function
void processInput(Circuit& cir, const string& fileName);  // evaluates the inputs and prints the outputs.

int main(){

    Circuit circ;
    createCircuit(circ, "circuit.txt");
    processInput(circ, "input.txt");
    return 0;
}

void createCircuit(Circuit& cir, const string& fileName){
    ifstream file;
    file.open(fileName);    // opens the file
    
    while(file.peek() != EOF){
        stringstream ss;    // get current line to stringstream
        string line;
        getline(file, line);
        ss.str(line);
        processLine(cir, ss); // updates the circuit by the code in the line
    }

    file.close();
}

void processLine(Circuit& cir, stringstream& ss){
    string keyword;                 // keywords: INPUT OUTPUT AND OR NOT FLIPFLOP DECODER
    string in0, in1, o0, o1, o2, o3;// input and output names in the line
    ss >> keyword;                  // gets the keyword

    if(keyword == "INPUT"){         // adds the inputs into circuit
        while(ss.peek() != EOF){
            ss >> in0;          
            cir.addInput(in0);  
        }
    }

    else if(keyword == "OUTPUT"){   // adds the outputs into circuit
        while(ss.peek() != EOF){
            ss >> in0;
            cir.addOutput(in0);
        }
    }

    else if(keyword == "AND"){      // adds an and to circuit
        ss >> o0 >> in0 >> in1;
        cir.addAnd(in0, in1, o0);   
    }

    else if(keyword == "OR"){       // adds an or to circuit
        ss >> o0 >> in0 >> in1;
        cir.addOr(in0, in1, o0);
    }

    else if(keyword == "NOT"){      // adds a not to circuit
        ss >> o0 >> in0;
        cir.addNot(in0, o0);
    }

    else if(keyword == "FLIPFLOP"){ // adds a flipflop to circuit
        ss >> o0 >> in0;
        cir.addFlipflop(in0, o0);
    }

    else if(keyword == "DECODER"){  // adds a decoder to circuit
        ss >> o0 >> o1 >> o2 >> o3 >> in0 >> in1;
        cir.addDecoder(in0, in1, o0, o1, o2, o3);
    }
}

void processInput(Circuit& cir, const string& fileName){
    ifstream file;
    file.open(fileName);
    
    while(file.peek() != EOF){
        bool input;
        vector<bool> inputs;
        stringstream ss;
        string line;
        getline(file, line);
        ss.str(line);       // gets the input line

        while(ss.peek() != EOF){    // gets the values into vector from line
            ss >> input;            
            inputs.push_back(input);
        }
        cir.setInputs(inputs);      // sets inputs using inputs vector
        cir.evaluate();             // evaluates the circuit
        cir.printOutputs();         // prints the outputs
    }

    file.close();
}