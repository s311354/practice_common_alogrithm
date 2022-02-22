#include "./graph_representation.h"
#include <map>

#ifndef GRAPH_H
#define GRAPH_H

namespace common {

class Graph
{
private:

public:
    Graph() {};
    Graph(const string ) {};
    Graph(const Graph &) {};
    virtual ~Graph() {};

    virtual void DFS() {};
    virtual void AddEdge(const int source, const int destination) {};

    unique_ptr<common::GraphRepresentation> representation;
    int vertices;
};

} /* namespace  */

#endif /* GRAPH_H */
