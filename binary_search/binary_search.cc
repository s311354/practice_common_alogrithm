#include <stdlib.h>
#include <iostream>
#include "binary_search.h"

BSTNode* GetNewNode(int value) {
    BSTNode* node = new BSTNode;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

BSTNode* Insert(BSTNode* node, int value) {
    // Protect
    if (node == nullptr) {
        node = GetNewNode(value);
        return node;
    }

    if (value < node->data) {
        node->left = Insert(node->left, value);
    } else if (value > node->data) {
        node->right = Insert(node->right, value);
    }

    return node;
}

bool Search(BSTNode* node, int value) {
    if (node == nullptr) {
        return false;
    }

    if (value < node->data) {
        return Search(node->left, value);
    } else if (value > node->data) {
        return Search(node->right, value);
    } else {
        return true;
    }
}

BSTNode* GetMinNode(BSTNode* node) {
    if (node == nullptr) {
        return nullptr;
    }

    if(node->left == nullptr) {
        return node;
    }

    return GetMinNode(node->left);
}

int GetMin(BSTNode* node) {
    if (node == nullptr) {
        return -1;
    }

    if (node->left == nullptr) {
        return node->data;
    }

    return GetMin(node->left);
}

BSTNode* GetMaxNode(BSTNode* node) {
    if (node == nullptr) {
        return nullptr;
    }

    if (node->right == nullptr) {
        return node;
    }

    return GetMaxNode(node->right);
}

int GetMax(BSTNode* node) {
    if (node == nullptr) {
        return -1;
    }

    if (node->right == nullptr) {
        return node->data;
    }

    return GetMax(node->right);
}

void PrintInOrder(BSTNode* node) {
    if (node == nullptr) {
        return;
    }

    if (node->left != nullptr) PrintInOrder(node->left);

    std::cout << node->data << " ";

    if (node->right != nullptr) PrintInOrder(node->right);
}


