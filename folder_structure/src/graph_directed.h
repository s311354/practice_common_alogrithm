#include "./graph.h"

#ifndef GRAPH_DIRECTED_H
#define GRAPH_DIRECTED_H

using namespace std;

namespace common {

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

} /* namespace common */

#endif /* GRAPH_DIRECTED_H */
