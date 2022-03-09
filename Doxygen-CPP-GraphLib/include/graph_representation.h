#include <string>
#include <vector>
#include <map>

#ifndef GRAPH_REPRESENTATION_H
#define GRAPH_REPRESENTATION_H

using namespace std;

namespace graphlib {

class GraphRepresentation
{
private:

public:
    GraphRepresentation() {};
    GraphRepresentation(const string graph_type);
    GraphRepresentation(const GraphRepresentation&) {};
    virtual ~GraphRepresentation() {};
    static const string kRepresentationTypeList; 
    static const string kRepresentationTypeMatrix;
    static const string kGraphTypeDirected;

    virtual void AddEdge(const int source, const int destination) {};
    virtual void DFS() {};

    static unique_ptr<graphlib::GraphRepresentation> GetRepresentation(const string representation_type, const string graph_type);
    string type;
    int vertices;

};

/*! \class GraphRepresentationList
 *  \brief Interface of Graph Representation
 *
 *  The strategy pattern seperates the selection of algorithm from the implementation og the algorithm. Allows for the selection to be made based upon context.
 */
class GraphRepresentationList : public GraphRepresentation
{
public:
    GraphRepresentationList(const string graph_type) : GraphRepresentation(graph_type) {};
    virtual ~GraphRepresentationList() {};

    void AddEdge(const int source, const int destination);
    void DFS();

    vector<vector<int> >  adjust_list; // [source][destination]

protected:
    int size_string_required = 5;
};

} /* namespace graphlib */

#endif /* GRAPH_REPRESENTATION_H */
