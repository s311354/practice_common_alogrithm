#include <string>
#include <vector>

#ifndef GRAPH_REPRESENTATION_H
#define GRAPH_REPRESENTATION_H

using namespace std;

namespace common {


class GraphRepresentation
{
private:
    

public:
    GraphRepresentation() {};
    GraphRepresentation(const string graph_type);
    GraphRepresentation(const GraphRepresentation&) {};
    virtual ~GraphRepresentation() {};

    /* static is just a global variable with visibility limited to one function. So if you declare it static, there is exactly one variable shared by all the levels of recursion. Without static, the variable is local, which means each function invocation has its own copy of variable's state. from https://www.cplusplus.com/forum/general/68835/#msg367544 */
    static const string kRepresentationTypeList; 
    static const string kRepresentationTypeMatrix;
    static const string kGraphTypeDirected;
    static const string kGraphTypeUndirected;

    virtual void AddEdge(const int source, const int destination) {};
    virtual void DFS() {};
    virtual void BFS() {};
    virtual bool ContainsCycle() { return 0; } ;
    virtual void PrintDebug() {};

    /* unique_ptr manages the storage of a pointer, providing a limited garbage-collection facility. example: https://www.cplusplus.com/reference/memory/unique_ptr/get/ */
    static unique_ptr<common::GraphRepresentation> GetRepresentation(const string representation_type, const string graph_type);
    string type;
    int vertices;

};

/*! \class GraphRepresentationList
 *  \brief Brief class description
 *
 *  Detailed description
 */
class GraphRepresentationList : public GraphRepresentation
{
public:
    GraphRepresentationList(const string graph_type) : GraphRepresentation(graph_type) {};
    virtual ~GraphRepresentationList() {};

    void AddEdge(const int source, const int destination);
    void BFS();
    void DFS();
    bool ContainsCycle();
    void PrintDebug();

    vector<vector<int> >  adjust_list;
protected:

};

} /* namespace common */

#endif /* GRAPH_REPRESENTATION_H */
