#include <iostream>
#include "graph.h"
#include "bargraph.h"
#include "linegraph.h"

using namespace std;
using namespace KurutGraph;

int main(){

    Graph newGraph;
    BarGraph newBarGraph;
    LineGraph newLineGraph;

    newGraph.draw();
    newGraph.erase();
    newBarGraph.draw();
    newBarGraph.erase();
    newLineGraph.draw();
    newLineGraph.erase();

    newGraph.callEraseDraw();
    newBarGraph.callEraseDraw();
    newLineGraph.callEraseDraw();

    return(0);
}
