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

namespace leetcode {

class Solutions
{
private:
    bool isPalindrome(std::string s);
    bool isValidChar(char c);
    bool isValidString(std::string s);

    void bfs(int column, int row, std::vector< std::vector<int>> & grid, std::vector< std::vector<int>>& dist, std::vector< std::vector<int>>& reached);

public:
    Solutions(){};
    virtual ~Solutions(){};

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

    /* ========== BFS ============ */
    // 317. Shortest Distance from All Buildings
    int shortestDistance( std::vector< std::vector<int> > & grid );


};

} /* namespace leetcode */

#endif /* SOLUTION_H */
