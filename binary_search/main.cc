#include <stdlib.h>
#include "binary_search.h"
#include "binary_search.cc"


int main(int argc, char *argv[])
{
    using namespace common;
    BSTNode* root = nullptr;
    auto binarysearch = new BinarySearch();

    int idex;
    for (idex = 0; idex < 10; ++idex) {
        int data = rand()%100;
        root = binarysearch->Insert(root, data);
    }


    if (binarysearch->IsBinarySearchTree(root)) {

        int min = binarysearch->GetMin(root);
        int max = binarysearch->GetMax(root);
        int height = binarysearch->GetHeight(root);

        binarysearch->PrintBFS(root);
        std::cout << std::endl;
        binarysearch->PrintInOrder(root);
        std::cout << std::endl;

        std::cout << "Search 44 in the binary tree: "<< binarysearch->Search(root, 44) << std::endl;

        std::cout << "Min: " << min << std::endl;
        std::cout << "Max: " << max << std::endl;
        std::cout << "Height: " << height << std::endl;

        binarysearch->DeleteValue(root, 49);
        binarysearch->PrintInOrder(root);
        std::cout << std::endl;

        binarysearch->DeleteTree(root);
    }
    else
        std::cout << "The tree is not binary search tree" << std::endl;


    delete binarysearch;
    return 0;
}
