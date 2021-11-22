#include "./graph_representation.h"
#include <iostream>
#include <queue>  //queues are a type of container adaptor, specifically designed to operate in a FIFO context (first-in first-out)
#include <stack>  //stacks are a type of container adaptor, specifically designed to operate in a LIFO context (last-in first-out)

using namespace std;

namespace common {

const string GraphRepresentation::kRepresentationTypeList("list");
const string GraphRepresentation::kRepresentationTypeMatrix("matrix");
const string GraphRepresentation::kGraphTypeDirected("directed");
const string GraphRepresentation::kGraphTypeUndirected("undirected");

unique_ptr<GraphRepresentation> GraphRepresentation::GetRepresentation(const string representation_type, const string graph_type) {
    if (representation_type == kRepresentationTypeList) {
        return unique_ptr<GraphRepresentation>(new GraphRepresentationList(graph_type));
    } else {
        std::cout << "Graph Representation type not supported." << std::endl;
        exit(EXIT_FAILURE);
    }
}

GraphRepresentation::GraphRepresentation(const string graph_type) {
    vertices = 0;

    if (graph_type == kGraphTypeDirected) {
        type = kGraphTypeDirected;
    } else if (graph_type == kGraphTypeDirected) {
        type = kGraphTypeUndirected;
    }
}

void GraphRepresentationList::AddEdge(const int source, const int destination) {

    /* static_cast can be used to convert from an int to a char. However, the resulting char may not have enough bits to hold the entire int vaule */
    unsigned long source_index = static_cast<unsigned long>(source);

    int size_required = max(source, destination) + 1;

    while (adjust_list.size() < size_required) {
        adjust_list.push_back(vector<int>());
    }

    /* Operator[] does not do range checking. Accessing element not presenting in vector silently leads to undefined behaviors; .ar() member function does range checking and throws an expception when you are tring to access nonexisting element.*/
    auto adjacent_vertices = adjust_list.at(source_index);

    std::vector<int>::iterator it = find(adjacent_vertices.begin(), adjacent_vertices.end(), destination);


    if (it == adjacent_vertices.end()) {
        adjust_list.at(source_index).push_back(destination);
    }

    vertices = static_cast<int>(adjust_list.size());
}

/*! \brief Brief function description here
 *
 *  Detailed description: Breadth First Search is traversing algorithm where you should start traversing from a selected node (source or parent node) and traverse the graph layerwise thus exploring the neighbour nodes. refer to https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/practice-problems/
 *
 * \return Return parameter description
 */
void GraphRepresentationList::BFS() {
    std::vector<int> components;

    const int NULL_PARENT = -1;
    // creates an array on the heap that has a lifetime for as long as you need it
    int *parents = new int [vertices];
    assert(parents);

    /* Assigns vaule to the frist n elements of sequence pointed by first */
    fill_n(parents, vertices, NULL_PARENT);

    std::cout << "\n----------------\nBFS: " << std::endl;

    for (unsigned long i = 0; i < adjust_list.size(); ++i) {
        if (parents[i] == NULL_PARENT) {
            components.push_back(i);
        }

        std::queue<int> to_visit;
        to_visit.push(i);

        while(!to_visit.empty()){
            int vertex = to_visit.front();
            to_visit.pop();
            std::cout << vertex << " ";

            for (unsigned long n = 0; n < adjust_list[vertex].size(); ++n) {
                int neighbor = adjust_list[vertex].at(n);

                if (parents[neighbor] == NULL_PARENT) {
                    parents[neighbor] = vertex;
                    to_visit.push(neighbor);
                }
            }
        }
    }

    std::cout << "\n\n Parents: "<< std::endl;

    for (int i = 0; i < vertices; ++i) {
        std::cout << i << " : " << parents[i] << std::endl;
    }

    std::cout << "\n Components: " << components.size() << std::endl;
    for (auto it = components.begin();  it != components.end() ; ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    delete [] parents;
}

/*! \brief Brief function description here
 *
 *  Detailed description: Depth First Search is a recursive algorithm that uses the idea of backtracking. It involves searches of all the nodes by going ahead if possible, else by backtracking. refer to https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
 *
 * \return Return parameter description
 */
void GraphRepresentationList::DFS() {
    std::vector<int> components;

    const int NULL_PARENT = -1;
    int *parents = new int [vertices]();
    assert(parents);
    fill_n(parents, vertices, NULL_PARENT);

    std::cout << "\n----------------\nDFS: " << std::endl;

    for (unsigned long i = 0; i < adjust_list.size(); ++i) {
        if (parents[i] == NULL_PARENT) {
            components.push_back(i);
        }

        std::stack<int> to_visit;

        to_visit.push(i);

        while (!to_visit.empty()) {
            int vertex = to_visit.top();
            to_visit.pop();

            std::cout << vertex << " ";

            for (unsigned long n = 0; n < adjust_list[vertex].size(); n++) {
                int neighbor = adjust_list[vertex].at(n);
                if (parents[neighbor] == NULL_PARENT) {
                    parents[neighbor] = vertex;
                    to_visit.push(neighbor);
                }
            }
        }
    }

    std::cout << "\n\nParents: " << std::endl;

    for (int i = 0; i < vertices; ++i) {
        std::cout << i << " : " << parents[i] << std::endl;
    }

    std::cout << "\n Components: " << components.size() << std::endl;
    for (auto it = components.begin();  it != components.end() ; ++it) {
        std::cout << *it << std::endl;
    }

    std::cout << std::endl;

    delete [] parents;
}

bool GraphRepresentationList::ContainsCycle() {
    bool contains_cycle = false;
    const int STATUS_NEW = 0;
    const int STATUS_STARTED = 1;
    const int STATUS_FINISHED = 2;

    for (unsigned long i = 0; i < adjust_list.size(); ++i) {
        int * nodes = new int [vertices]();
        assert(nodes);
        fill_n(nodes, vertices, STATUS_NEW);
        std::stack<int> to_visit; // LIFO

        to_visit.push(i);
        while (!(to_visit.empty() || contains_cycle)) {
            int vertex = to_visit.top();
            to_visit.pop();

            if (nodes[vertex] == STATUS_STARTED) {
                nodes[vertex] = STATUS_FINISHED;
                continue;
            }

            nodes[vertex] = STATUS_STARTED;

            // push back onto stack so we can tell when vertex is finished.
            to_visit.push(vertex);

            for (unsigned long n = 0; n < adjust_list[vertex].size(); ++n) {
                int neighbor = adjust_list[vertex].at(n);

                if (nodes[neighbor] == STATUS_NEW) {
                    to_visit.push(neighbor);
                } else if (nodes[neighbor] == STATUS_STARTED) {
                    contains_cycle = true;
                    break;
                } else if (nodes[neighbor] == STATUS_FINISHED) {
                    // skip, already seen
                }
            }
        }

        delete[] nodes;
    }

    return contains_cycle;
}

void GraphRepresentationList::PrintDebug() {
    std::cout << "Adjacency List:" << std::endl;
    std::cout << "Vertices: " << vertices << std::endl;

    for (unsigned long i = 0;  i < adjust_list.size(); ++ i) {
        std::cout << i << ":"  << std::endl;
        for (unsigned long j = 0; j < adjust_list[i].size(); ++j) {
            std::cout << " " << adjust_list[i].at(j) << std::endl;
        }
        std::cout << std::endl;
    }
}

} /* namespace common */


