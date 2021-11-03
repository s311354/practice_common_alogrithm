#ifndef PROJECT_BINARY_SEARCH_TREE_H
#define PROJECT_BINARY_SEARCH_TREE_H
#include <stdlib.h>
#include <iostream>
#include <queue>

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
// Returns true if tree is binary search tree
bool IsBinarySearchTree(BSTNode* node);
// Returns true if all items in the given tree are between the given values
bool IsBetween(BSTNode* node, int min, int max);
// Returns the minimum node stored in the tree
BSTNode* GetMinNode(BSTNode* node);
// Returns the minimum value stored in the tree or -1 if tree is empty
int GetMin(BSTNode* node);
// Returns the maximum node stored in the tree
BSTNode* GetMaxNode(BSTNode* node);
// Returns the maximum value stored in the tree or -1 if tree is empty
int GetMax(BSTNode* node);
// Returns the height of the tree, 0 if empty
int GetHeight(BSTNode* node);
// Delete a specific node from the node
BSTNode* DeleteValue(BSTNode* node, int value);
// Frees memory allocated for the tree
void DeleteTree(BSTNode* node);
// Print out the items in the tree in order
void PrintInOrder(BSTNode* node);
// Print out the items in the tree
void PrintBFS(BSTNode* node);
#endif /* ifndef PROJECT_BINARY_SEARCH_TREE_H */
