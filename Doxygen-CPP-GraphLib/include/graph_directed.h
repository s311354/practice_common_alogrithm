#include "./graph.h"

#ifndef GRAPH_DIRECTED_H
#define GRAPH_DIRECTED_H

using namespace std;

namespace graphlib {

class GraphDirected : public Graph
{
private:

public:
    GraphDirected() {};
    GraphDirected(const string);
    virtual ~GraphDirected() {};

    void DFS();
    void AddEdge(const int source, const int destination);
};

} /* namespace graphlib */

#endif /* GRAPH_DIRECTED_H */
