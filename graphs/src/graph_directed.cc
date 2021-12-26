#include "./graph.h"
#include "./graph_directed.h"

namespace common {

GraphDirected::GraphDirected(const string representation_type) {
    representation = GraphRepresentation::GetRepresentation(representation_type, GraphRepresentation::kGraphTypeDirected);
}

void GraphDirected::BFS() {
   representation->BFS(); 
}

void GraphDirected::DFS() {
    representation->DFS();
}

void GraphDirected::AddEdge(const int source, const int destination) {
    representation->AddEdge(source, destination);
}

void GraphDirected::PrintDebug() {
    representation->PrintDebug();
}

const int GraphDirected::GetVertexCount() {
    return representation->vertices;
}
    
} /* namespace common */
