#include "./graph_representation.h"
#include "./graph_directed.h"
#include "./graph.h"
#include <iostream>

int main(int argc, char *argv[])
{

    using namespace common;

    // Girected Graph
    auto graph_node = new GraphDirected(GraphRepresentation::kRepresentationTypeList);


    graph_node->AddEdge(0, 1);
    graph_node->AddEdge(0, 5);
    graph_node->AddEdge(1, 2);
    graph_node->AddEdge(2, 4);
    graph_node->AddEdge(2, 6);
    graph_node->AddEdge(3, 2);
    graph_node->AddEdge(5, 8);
    graph_node->AddEdge(6, 5);
    graph_node->AddEdge(7, 5);

    graph_node->DFS();
    graph_node->BFS();
    graph_node->PrintDebug();


//     std::cout << "Contains Cycle: " << graph_node->ContainsCycle() << std::endl;

    delete graph_node;
    return 0;
}
