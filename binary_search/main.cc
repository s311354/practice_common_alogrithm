#include <stdlib.h>
#include "binary_search.h"
#include "binary_search.cc"

int main(int argc, char *argv[])
{
    BSTNode* root = nullptr;

    int idex;
    for (idex = 0; idex < 10; ++idex) {
        int data = rand()%100;
        root = Insert(root, data);
    }


    if (IsBinarySearchTree(root)) {

        int min = GetMin(root);
        int max = GetMax(root);
        int height = GetHeight(root);

        PrintBFS(root);
        std::cout << std::endl;
        PrintInOrder(root);
        std::cout << std::endl;

        std::cout << "Search 44 in the binary tree: "<< Search(root, 44) << std::endl;

        std::cout << "Min: " << min << std::endl;
        std::cout << "Max: " << max << std::endl;
        std::cout << "Height: " << height << std::endl;

        DeleteValue(root, 49);
        PrintInOrder(root);
        std::cout << std::endl;

        DeleteTree(root);
    }
    else
        std::cout << "The tree is not binary search tree" << std::endl;

    return 0;
}
