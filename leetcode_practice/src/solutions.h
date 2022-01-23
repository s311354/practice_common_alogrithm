#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <ctype.h>

// STL Containers
#include <set>
#include <unordered_set>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include <stack>
#include <numeric>

namespace leetcode {

struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(0), left(left), right(right) {};

};


class Solutions
{
private:
    bool isPalindrome(std::string s);
    bool isValidChar(char c);
    bool isValidString(std::string s);
    bool isUniqieString(std::string s);
    void checkLen( std::vector<std::string> & arr, std::string str, int index, int& count);
    void bfs(int column, int row, std::vector< std::vector<int> > &grid, std::vector< std::vector<int> > &distance, std::vector< std::vector<int> >  &visit);
    void countGoodNode(TreeNode* node, int value, int& count);

    void PrintInorder(TreeNode * node);

    int gcd (int a, int b);

    TreeNode* getNewNode(int value);

public:
    Solutions(){};
    virtual ~Solutions(){};

    std::vector<int> PrintBFS(TreeNode* node);
    TreeNode* insertBTNode(TreeNode* node, int value, int index);

    /* ========== Microsoft OA ============ */

    // 1647. Miniumum Deletions to Make Character Frequencies Unique
    int minDeletions(std::string s);

    // OA 2019 Minimum Adjacent Swaps to Make Palindrome
    int minSwaps(std::string s);

    // 1. Two Sum 
    std::vector<int> twoSum(std::vector<int>& num, int target);

    // OA 2019 Min Steps to Make Piles Equal Height
    int minStpes( std::vector<int>& nums );

    // OA 2019 Largest K such that both K and -K exist in array
    int largestK( std::vector<int>& nums);

    // 1239. Maximum length of a Concatenated String with Unique Characters 
    int maxLength( std::vector< std::string > & arr);

    // 1304. Find N Unique Integers Sum up to Zero
    std::vector<int> sumZero(int n);

    // 31 Next Permutation
    void nextPermutation( std::vector<int> & nums);

    // 1822. Sign of the Product of an Array
    int arraySign( std::vector<int> & nums);

    // 1448. Count Good Nodes in Binary Tree
    int goodNodes(TreeNode* root);

    // OA 2019 Min Moves to Make String Without 3 Identical Consecutive Letters
    std::string filterString(std::string &s);

    // OA 2019 Maximum possible value by inserting '5' digit
    int maxPossible(int num, int digit);

    // OA 2019 Minimum characters required to be removed to make frequency of each character unique
    int minCntCharDeletionfrequency(std::string & str, int N);

    // 450 Delete Node in a BST
    TreeNode * deleteNode(TreeNode* root, int key);

    // OA 2020 Number of Fractions that Sum to 1
    int sumFraction( std::vector< std::vector<int> > & fracrion);

    /* ========== BFS ============ */
    // 317. Shortest Distance from All Buildings
    int shortestDistance( std::vector< std::vector<int> > & grid );

    

};

} /* namespace leetcode */

#endif /* SOLUTION_H */
