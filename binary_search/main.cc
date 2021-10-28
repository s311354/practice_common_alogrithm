#include <stdlib.h>
#include "binary_search.h"
#include "binary_search.cc"

int main(int argc, char *argv[])
{

    BSTNode* root = nullptr;

    int idex;
    for (idex = 0; idex < 10; ++idex) {
        root = Insert(root, rand()%100);
    }

    int min = GetMin(root);
    int max = GetMax(root);

    PrintInOrder(root);

    return 0;
}
