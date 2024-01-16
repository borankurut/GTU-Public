#include <iostream>
#include "graph.h"

using namespace std;

namespace KurutGraph{
    void Graph::erase(){
        cout << "Graph::erase() called.\n";
    }

    void Graph::draw(){
        cout << "Graph::draw() called.\n";
    }

    void Graph::callEraseDraw(){
        draw();
        erase();
    }
}