#include <iostream>
#include "linegraph.h"

using namespace std;

namespace KurutGraph{
    void LineGraph::erase(){
        cout << "LineGraph::erase() called.\n";
    }

    void LineGraph::draw(){
        cout << "LineGraph::draw() called.\n";
    }
}