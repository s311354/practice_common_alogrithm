#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include "./graph_directed.h"

int main(int argc, char *argv[])
{
    using namespace graphlib;
    auto graph_node = new GraphDirected(GraphRepresentation::kRepresentationTypeList);

    // Input Tree table
    /* ========================================= */
    std::vector<int> pidnums;
    std::vector<int> idnums;
    std::ifstream file("input.txt");
    if (file.is_open()) {
        std::string line;
        std::string id, p_id;
        while (std::getline(file, line)) {
            std::istringstream iss(line);
            if ((iss >> id >> p_id)) {
                pidnums.insert(pidnums.end(), std::stoi(p_id.find("null") ? p_id : "0"));
                idnums.insert(idnums.end(), std::stoi(id.find("null") ? id : "0"));
            } else {
                std::cout << "The format of input tree table is incorrect" << std::endl;
                break;
            }
        }
        file.close();
    }
    /* ========================================= */

    if ( pidnums.size() == idnums.size()) {
        for (int i = 0; i < pidnums.size(); ++i) {
            graph_node->AddEdge(pidnums[i], idnums[i]);
        }
    } else
        std::cout << "The input tree table is inconsistent" << std::endl;

    // Output Folder Table
    graph_node->DFS();

    delete graph_node;
    return 0;
}
