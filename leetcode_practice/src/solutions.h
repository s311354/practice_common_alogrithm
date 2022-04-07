#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <ctype.h>

// STL Containers
#include <set>
#include <unordered_set>
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <queue>
#include <stack>
#include <numeric>
#include <regex>

#include <ctype.h>

namespace leetcode {

static const std::regex INT_TYPE("[+-]?[0-9]+");
static const std::regex UNSIGNED_INT_TYPE("[+]?[0-9]+");
static const std::regex DOUBLE_TYPE("[+-]?[0-9]+[.]?[0-9]+");
static const std::regex UNSIGNED_DOUBLE_TYPE("[+]?[0-9]+[.]?[0-9]+");

#define ROW 4
#define COLUMN 4



struct TreeNode
{
    int val;
    TreeNode * left;
    TreeNode * right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode * left, TreeNode * right) : val(0), left(left), right(right) {};

};

struct LinkedListNode {
    /* data */
    int val;
    LinkedListNode * next;
    LinkedListNode() : val(0), next(nullptr) {}
    LinkedListNode(int x) : val(x), next(nullptr) {}
    LinkedListNode(int x, LinkedListNode *next) : val(x), next(next) {}
};

class Solutions
{
private:
    bool isPalindrome(std::string s);
    bool isValidChar(char c);
    bool isValidString(std::string s);
    bool isUniqieString( const std::string s);
    void checkLen( const std::vector<std::string> & arr, std::string str, int index, int& count);
    void bfs(int column, int row, std::vector< std::vector<int> > &grid, std::vector< std::vector<int> > &distance, std::vector< std::vector<int> >  &visit);
    void countGoodNode(TreeNode* node, int value, int& count);

    void PrintInorder(TreeNode * node);

    int getRandom(int low, int high, int badNum);
    int gcd (int a, int b);


    std::vector<int> parseInts(const std::string & str);

    TreeNode* getNewNode(int value);

    TreeNode* getMinNode(TreeNode* node);

    LinkedListNode* getNewHead(int value);

public:
    Solutions(){};
    Solutions(std::istream& s){};
    virtual ~Solutions(){};

    std::vector<int> PrintBFS(TreeNode* node);
    TreeNode* insertBTNode(TreeNode* node, int value, int index);
    std::vector<int> PrintLinkedlist(LinkedListNode* node);
    LinkedListNode* insertLinkedlistNode(LinkedListNode* node, int value);
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

    // 1578. Minmum Time to Make Rope Colorful
    int minCost( std::string colors, std::vector<int> & neededTime );

    // 14. Longest Common Prefix
    std::string longestPrefix( std::vector< std::string > & strs);

    // OA Largest K such that both K and -K exist in array
    int getLargestK( std::vector<int> & nums);

    // Codility Test
    int smallestInt( std::vector<int> &A);

    // Length of its longest binary gap
    int lengthBin(int N);

    /* ========== BFS ============ */
    // 317. Shortest Distance from All Buildings
    int shortestDistance( std::vector< std::vector<int> > & grid );

    // The Monty Hall Problem
    float montyHall(int guess);

    // Lowercase letters
    int lowercaseLetters( std::string &S);

    // Balanced Stone Heaps
    int balancedStone( std::vector<int> &A);

    // Heap 
    // Course Schedule III
    int scheduleCourse( std::vector< std::vector<int> > & courses );

    int uniqueString( std::string &S);

    // 252 Meeting rooms (Greedy Algorithms)
    int storeMeetingrooms( std::vector< std::vector<int> > & rooms);

    // 452. Minimum Number of Arrows to Brust Balloons
   int findMinArrowShots( std::vector< std::vector<int> > &points);

    int maxFullRound( std::string &A, std::string &B);

    int solutions2( std::vector<int> &A);

    int maximumSum( int N, std::vector<int> &A, std::vector<int > &B);

    // 217. Contains Duplicate
    bool containDup ( std::vector<int> & nums);

    // 136. Single Number 
    int singleNumber( std::vector<int> & nums);

    // 349. Intersection of Two Arrays
    std::vector<int> intersection( std::vector<int> & nums1, std::vector<int> & nums2);

    // 202. Happy Number
    bool isHappy(int n);

    void dictionaries();

    // 18. 4Sum
    std::vector< std::vector<int> >  fourSum( std::vector<int> & nums, int target);

    // 100 Same Tree
    bool isSameTree(TreeNode* p, TreeNode* q);

    // 648. Replace Words
    std::string replaceWords( std::vector< std::string > & dictionary, std::string  sentence);

    // Google interview
    int uncovered_interval(std::vector< std::pair<int, int> > unserviceinterval, int thirdservice);

    // 2134. Minimum Swaps to Group All's Together II
    int minSwapsnums(std::vector<int> & nums);

    int minDistance( std::vector< std::vector<int> > & edges, int n, int x);

    std::vector< std::string > commonSubstring( std::vector<std::string> a, std::vector<std::string> b);

    int countDuplicates( std::vector<int> number);

    std::vector<float> plusMinus( std::vector<int> arr);

    // Codility Test
    int minChange(std::string &S, int k);

    // Codility Test
    int minDeleteCost( std::string &S, std::vector<int> &C);

    // Get Number of K
    int getNumberofK( std::vector<int>& data, int K);

    // Find Numbers with Sum
    std::vector<int> findNumberswithSum( std::vector<int> &nums, int sum);

    // median
    int getMedian(int x, int y, int z);

    // Almost Sorted
    bool almostSorted( std::vector<int> & nums);

    // 657. Robot Return to Origin
    bool judgeCircle( std::string moves);

    // 1192. Critical Connections in a Network
    std::vector< std::vector<int> > criticalConnections(int n, std::vector< std::vector<int> > & connections);

    // 162. Find Peak Element
    int findPeakElement( std::vector<int> & nums);

    // 2. Add Two Numbers
    LinkedListNode* addTwoNumbers(LinkedListNode* l1, LinkedListNode* l2);

    // 83. Remove Duplicate from Sorted List
    LinkedListNode* deleteDuplicates(LinkedListNode * head);

    // Interview Question
    int balancedSum( std::vector<int> arr);

    // Interview Question
    bool addExpression( std::string& S);

    // 565 Array Nesting
    int arrayNexting( std::vector<int>& nums);

    // 282. Expression Add Operations
    std::vector< std::string> addOperators( std::string num, int target);

    // 110 Balanced Binary Tree
    bool isBalanced(TreeNode* root);

    // 108 Convert Sorted Array to Binary Search Tree
    TreeNode* sortedArrayToBST( std::vector<int> &nums);

    // 130. Surrounded Regions
    std::vector< std::vector<char> > surroundedRegions( std::vector< std::vector<char> > & board );

    // 338. Counting Bits
    std::vector<int> countBits(int n);

    // 191. Number of 1 Bits
    int hammingWeight(uint32_t n);

    // 336. Palindrome Pairs
    int palindromePairsSum( std::vector< std::string> & input_array);

    // 1927. Sum Game
    bool sumGame( std::string num);

    // 877. Stone Game
    bool stoneGame( std::vector<int> piles);

    // 51. N-Queens
    std::vector< std::vector< std::string> > solveNQueens(int n);

    // 1307.Verbal Arithmetic Puzzle
    bool isSolvable( std::vector< std::string > & words, std::string result);

    // 743. Network Delay Time
    int networkDelayTime( std::vector< std::vector<int> >  & time, int n, int k);

    // 785. Is Graph Bipartite
    bool isBipartite( std::vector< std::vector<int> > & graph );

    // 1820. Maximum Number of Accepted Invitations
    int maximumInvitations( std::vector< std::vector<int> > & grid);

    std::vector< std::vector<int> > isPairWithSum(int mat[ROW][COLUMN], int sum);

};


} /* namespace leetcode */

#endif /* SOLUTION_H */
