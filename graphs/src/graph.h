#include "./graph_representation.h"
#include <map>

#ifndef GRAPH_H
#define GRAPH_H

namespace common {


struct Convert
{
    Convert() {};
    virtual ~Convert() {};

    bool isValidChar(char achar);
    int str2num(std::string name);
    std::string num2str(int id);

};

class Graph
{
private:

public:
    Graph() {};
    Graph(const string ) {};
    Graph(const Graph &) {};
    virtual ~Graph() {};

    /*ISO 14882 wrote: A virtual function call uses the default arguments in the declaration of the virtual function determined by the static type of the pointer or reference denoting the object. An overriding function in a derived class does not acquire default arguments from the function it overrides. */
    virtual void BFS() {};
    virtual void DFS() {};
    virtual void AddEdge(const int source, const int destination) {};
    virtual void PrintDebug() {};

    /* unique pointer manages the storage of a pointer, providing a limited garbage-collection facility, with little to no overhead over built-in pointers */
    unique_ptr<common::GraphRepresentation> representation;
    int vertices;

};

} /* namespace  */

#endif /* GRAPH_H */
