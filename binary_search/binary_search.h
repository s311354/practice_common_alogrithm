#ifndef PROJECT_BINARY_SEARCH_TREE_H
#define PROJECT_BINARY_SEARCH_TREE_H

struct BSTNode {
    int data;
    BSTNode* left;
    BSTNode* right;
};

// Returns a new node for our BST
BSTNode* GetNewNode(int value);

// Returns a node with insert new node
BSTNode* Insert(BSTNode* node, int value);

// Returns true if given value is in our tree
bool Search(BSTNode* node, int value);

// Returns the minimum node stored in the tree
BSTNode* GetMinNode(BSTNode* node);

// Returns the minimum value stored in the tree
int GetMin(BSTNode* node);

// Returns the maximum node stored in the tree
BSTNode* GetMaxNode(BSTNode* node);

// Returns the maximum value stored in the tree
int GetMax(BSTNode* node);

// Returns the height of the tree, 0 if empty
int GetHeight(BSTNode* node);

// Frees memory allocated for the tree
void DeleteTree(BSTNode* node);

// Print out the items in the tree in order
void PrintInOrder(BSTNode* node);

#endif /* ifndef PROJECT_BINARY_SEARCH_TREE_H */
