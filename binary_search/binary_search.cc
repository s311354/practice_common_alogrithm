#include "binary_search.h"

namespace common {

BSTNode* GetNewNode(int value) {
    BSTNode* node = new BSTNode;
    node->data = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}

BSTNode* Insert(BSTNode* node, int value) {
    // First Node
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
    if (node == nullptr) return false;

    if (value < node->data) {
        return Search(node->left, value);
    } else if (value > node->data) {
        return Search(node->right, value);
    } else {
        return true;
    }
}

bool IsBinarySearchTree(BSTNode* node) {
    return IsBetween(node, INT_MIN, INT_MAX);
}

bool IsBetween(BSTNode* node, int min, int max) {
    if (node == nullptr) return true;

    if (node->data > min && node->data < max && 
        IsBetween(node->left, min, node->data) && 
        IsBetween(node->right, node->data, max))
        return true;
    else
        return false;
}

BSTNode* GetMinNode(BSTNode* node) {
    if (node == nullptr) return nullptr;

    if(node->left == nullptr)
        return node;

    return GetMinNode(node->left);
}

int GetMin(BSTNode* node) {
    if (node == nullptr) return -1;

    if (node->left == nullptr)
        return node->data;

    return GetMin(node->left);
}

BSTNode* GetMaxNode(BSTNode* node) {
    if (node == nullptr) return nullptr;

    if (node->right == nullptr)
        return node;

    return GetMaxNode(node->right);
}

int GetMax(BSTNode* node) {
    if (node == nullptr) return -1;

    if (node->right == nullptr)
        return node->data;

    return GetMax(node->right);
}

int GetHeight(BSTNode* node) {
    if (node == nullptr) return 0;

    return 1 + std::max(GetHeight(node->left), GetHeight(node->right));
}

void DeleteTree(BSTNode* node) {
    if (node == nullptr) return;

    if (node->left != nullptr) DeleteTree(node->left);
    if (node->right != nullptr) DeleteTree(node->right);

    delete node;
}

BSTNode* DeleteValue(BSTNode* node, int value) {
    if (node == nullptr) return nullptr;

    if (value < node->data)
        node->left = DeleteValue(node->left, value);
    else if (value > node->data)
        node->right = DeleteValue(node->right, value);
    else { 
        // Delete the matching value
        if (node->left == nullptr && node->right == nullptr) {
            delete node;
            node = nullptr;
        } else if (node->left == nullptr) {
            BSTNode* temp = node;
            node = node->right;
            delete temp;
        } else if (node->right == nullptr) {
            BSTNode* temp = node;
            node = node->left;
            delete temp;
        } else {
            BSTNode* temp = GetMinNode(node->right);
            node->data = temp->data; // replace min data in the right node with deleted value
            node->right = DeleteValue(node->right, temp->data); // reconstruct binary tree
        }
    }

    return node;
}

void PrintBFS(BSTNode* node) {
    std::queue<BSTNode*> node_queue;

    BSTNode* current;
    node_queue.push(node);

    while (! node_queue.empty()) {
        current = node_queue.front();
        node_queue.pop();

        if (current != nullptr) {
            std::cout << current->data << " ";
            if (current->left != nullptr) node_queue.push(current->left);
            if (current->right != nullptr) node_queue.push(current->right);
        }
    }
}

void PrintInOrder(BSTNode* node) {
    if (node == nullptr) return;

    if (node->left != nullptr) PrintInOrder(node->left);

    std::cout << node->data << " ";

    if (node->right != nullptr) PrintInOrder(node->right);
}

}
