#ifndef SOLUTION_H
#define SOLUTION_H
#include <iostream>
#include <ctype.h>
#include <vector>
#include <map>
#include <string>

namespace leetcode {
    
class Solutions
{
private:
    bool isPalindrome(std::string s);
    bool isValidChar(char c);
    bool isValidString(std::string s);


public:
    Solutions(){};
    virtual ~Solutions(){};

    // Miniumum Deletions to Make Character Frequencies Unique
    int minDeletions(std::string s);

    // Minimum Adjacent Swaps to Make Palindrome
    int minSwaps(std::string s);

    // Two Sum 
    std::vector<int> twoSum(std::vector<int>& num, int target);


};

} /* namespace leetcode */

#endif /* SOLUTION_H */
