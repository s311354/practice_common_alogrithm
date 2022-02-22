#include "./graph.h"
#include "./graph_directed.h"

namespace common {

GraphDirected::GraphDirected(const string representation_type)
{
    // Interface
    representation = GraphRepresentation::GetRepresentation(representation_type, GraphRepresentation::kGraphTypeDirected);
}

void GraphDirected::DFS()
{
    representation->DFS();
}

void GraphDirected::AddEdge(const int source, const int destination)
{
    representation->AddEdge(source, destination);
}
    
} /* namespace common */
