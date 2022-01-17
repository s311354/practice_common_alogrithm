#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <ctype.h>
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

    // Miniumum Deletions to Make Character Frequencies Unique
    int minDeletions(std::string s);

    // Minimum Adjacent Swaps to Make Palindrome
    int minSwaps(std::string s);

    // Two Sum 
    std::vector<int> twoSum(std::vector<int>& num, int target);

    /* ========== BFS ============ */
    // Shortest Distance from All Buildings
    int shortestDistance( std::vector< std::vector<int> > & grid );

};

} /* namespace leetcode */

#endif /* SOLUTION_H */
