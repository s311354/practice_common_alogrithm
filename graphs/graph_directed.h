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


    void BFS();
    void DFS();
    void AddEdge(const int source, const int destination);
    bool ContainsCycle() { return 0;};
    void PrintDebug();
    const int GetVertexCount();
};

} /* namespace common */

#endif /* GRAPH_DIRECTED_H */
