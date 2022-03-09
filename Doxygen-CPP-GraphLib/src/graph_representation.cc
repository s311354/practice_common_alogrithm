#include "./graph_representation.h"
#include <iostream>
#include <stack>

using namespace std;

namespace graphlib {

const string GraphRepresentation::kRepresentationTypeList("list");
const string GraphRepresentation::kRepresentationTypeMatrix("matrix");
const string GraphRepresentation::kGraphTypeDirected("directed");

//  Interface of graph representation ()
unique_ptr<GraphRepresentation> GraphRepresentation::GetRepresentation(const string representation_type, const string graph_type)
{
    if (representation_type == kRepresentationTypeList) {
        return unique_ptr<GraphRepresentation>(new GraphRepresentationList(graph_type));
    } else {
        std::cout << "Graph Representation type not supported." << std::endl;
        exit(EXIT_FAILURE);
    }
}

GraphRepresentation::GraphRepresentation(const string graph_type) 
{
    vertices = 0;

    if (graph_type == kGraphTypeDirected) {
        type = kGraphTypeDirected;
    }
}

void GraphRepresentationList::AddEdge(const int source, const int destination)
{
    unsigned long source_index = static_cast<unsigned long>(source);

    int size_required = std::max(source, destination) + 1;

    while (adjust_list.size() < size_required) {
        adjust_list.push_back(vector<int>()); // total node
    }

    auto adjacent_vertices = adjust_list.at(source_index);

    std::vector<int>::iterator it = std::find(adjacent_vertices.begin(), adjacent_vertices.end(), destination);

    // Don't add edge twice
    if (it == adjacent_vertices.end()) {
        adjust_list.at(source_index).push_back(destination);
    }

    vertices = static_cast<int>(adjust_list.size());
}

void GraphRepresentationList::DFS()
{
    std::vector<int> components;

    const int NULL_PARENT = -1, NULL_CHILD = -1;
    int *parents = new int [vertices]();
    int *childs = new int[vertices]();

    assert(parents);
    assert(childs);
    fill_n(parents, vertices, NULL_PARENT);
    fill_n(childs, vertices, NULL_CHILD);

    for (unsigned long i = 0; i < adjust_list.size(); ++i) {
        if (parents[i] == NULL_PARENT) {
            components.push_back(i);
        }

        std::stack<int> to_visit; // LIFO

        to_visit.push(i);

        // exploring all nodes
        while (!to_visit.empty()) {
            int vertex = to_visit.top();
            to_visit.pop();
            for (unsigned long n = 0; n < adjust_list[vertex].size(); n++) {
                int neighbor = adjust_list[vertex].at(n);
                if (parents[neighbor] == NULL_PARENT) {
                    parents[neighbor] = vertex;
                    to_visit.push(neighbor);
                }

                if (childs[neighbor] == NULL_CHILD) {
                    childs[vertex] = neighbor;
                }
            }
        }
    }

    for (int i = 1; i < vertices; ++i) {
        if (parents[i] == 0 || parents[i] == NULL_PARENT)
            std::cout << i << " : Root" << std::endl;
        else if (childs[i] > 0 )
             std::cout << i << " : Inner" << std::endl;
        else
             std::cout << i << " : Leaf" << std::endl;
    }

    delete [] parents;
    delete [] childs;
}

} /* namespace graphlib */
