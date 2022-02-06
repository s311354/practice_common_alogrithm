#include "./solutions.h"
#include <numeric>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <queue>
#include <boost/lexical_cast.hpp>

namespace leetcode {

bool Solutions::isPalindrome(std::string s)
{
    int start = 0, end = s.length() - 1;

    while (start < end / 2) {
        if (isValidChar(s[start]) && isValidChar(s[end])) {
            if (s[start] == s[end - start]) {
                start ++;
            } else {
                return false;
            }
        }
    }

    return true;
}

bool Solutions::isValidChar(char c)
{
    return ((c - 'a' >= 0 && c - 'z' <= 0) || (c - 'A' >= 0 && c - 'Z' <= 0));
}

bool Solutions::isValidString(std::string s)
{
    for (auto elem : s) {
        if ((elem - 'a' >= 0 && elem - 'z' <= 0 ) || (elem - 'A' >= 0 && elem - 'Z' <= 0)){
            continue;
        }
        else return false;
    }

    return true;
}

/*! \brief Brief function description here
 *
 *  Detailed description
 *
 * \return Return parameter description
 */
bool Solutions::isUniqieString(std::string s)
{
    std::set<char> unique;

    for (auto elem : s) {
        if (unique.count(elem)) return false;

        unique.insert(elem);
    }

    return true;
}

/*! \brief Minimum Deletions to Make Character Frequencies Unique
 *
 *  A string s is called good if there are no two different characters in s that have the same frequency.
 *  
 *  Given a string s, return the minimum number of characters you need to delete to make s good.
 *  
 *  The frequency of a character in a string is the number of times it appears in the string. 
 * 
 *  For example, in the string "aab", the frequency of 'a' is 2, while the freqnency of 'b' is 1.
 * \return the minmum number of characters you need tp delete to make s good
 */
int Solutions::minDeletions(std::string s)
{
    std::vector<int> v(26, 0);
    for (auto it : s) v[it - 'a'] ++;

    // Count the frequencies of elements
    std::map<int, int> mp;
    for (int i = 0; i < 26; ++i) mp[v[i]] ++;

    int ans = 0;

    // Traverse map from backwards (find the minimum number of character need to delete)
    for (auto it = mp.rbegin();  it!=mp.rend() ; ++it) {
        int key = it->first;
        int val = it->second;

        // not frequencies of elements
        if (key == 0 || val == 1) {
            continue;
        }

        // increase the freqnency count after delete characters
        int new_val = val - 1;
        mp[key -1] += new_val;
        ans += new_val;
    }

    return ans;
}

/*! \brief Minimum Adjacent Swaps to Make Palindrome
 *
 *  Given a string, what is the minimum number of adjacent swaps required to convert a string into a palindrome. If not possibl, return -1.
 *
 * \return the minimum number of adjust required
 */
int Solutions::minSwaps(std::string s)
{
    int start = 0, end = s.length() - 1, ans = 0;

    if (isValidString(s)) {
        while (start < s.length()/2) {

            // Palindrome
            if (s[start] == s[end - start]){
                ++ start;
                continue;
            }

            //  Core begins
            //  track of the left and right points and compare
            int left_index, right_index;
            for (left_index = start; left_index <= end - start && s[left_index] != s[end - start]; ++left_index);
            for (right_index = end - start - 1; right_index >= start && s[right_index] != s[start]; --right_index);

            // choose minimum distance between left side or right side
            if (left_index - start < end - start - right_index) {
                for (int p = left_index; p > start; --p) {
                    std::swap(s[p], s[p-1]);
                } 
                ans += left_index - start;
            } else {
                for (int p = right_index; p < end - start; ++p) {
                     std::swap(s[p], s[p+1]);
                }
                ans += end - start - right_index;
            }

            ++start;

        }

        if (!isPalindrome(s)) return -1;

    } else {
        return -1;
    }

    return ans;
}

/*! \brief Two Sum
 *
 *  Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 *
 * \return indices of the two numbers such that they add up to target
 */
std::vector<int> Solutions::twoSum(std::vector<int>& num, int target)
{
    std::vector<int> indices_two_sum;
    indices_two_sum.clear();

    // O(n^2)
    /*
    for (int i = 0; i < num.capacity(); ++i) {
        for (int j = i + 1; j < num.capacity(); ++j) {
            if( (num[i] + num[j]) == target) {
                indices_two_sum.push_back(i);
                indices_two_sum.push_back(j);
            }
        }
    }
    */

    // O(n)
    std::map<int, int> hashmap;
    hashmap.clear();

    for (int i = 0; i < num.capacity() ; i++)
    {
        const int diff = target - num[i];

        if ( hashmap.count(diff)) {
            indices_two_sum.push_back(hashmap[diff]);
            indices_two_sum.push_back(i);
            return indices_two_sum;
        }

        hashmap.insert( { num[i], i } );
    }

    return indices_two_sum;
}

/*! \brief Shortest Distance from All Buildings
 *
 *  You want to build a house on an empty land which reaches all buildings in the shortest amount of distance.
 *  You can only move up, down, left, and right. You are given a 2D grid of values 0, 1, or 2, where:
 *  Each 0 marks an empty land which you can pass by freely.
 *  Each 1 markd a building which you cannot pass through.
 *  Each 2 marks an obstacle which you cannot pass through.
 *
 * \return the shortest distance
 */
int Solutions::shortestDistance( std::vector< std::vector<int> > & grid )
{
    int row = grid.size(), column = grid[0].size();

    std::vector< std::vector<int> > distance(row, std::vector<int>(column, 0));
    std::vector< std::vector<int> > visit(row, std::vector<int>(column, 0));

    int num_building = 0, ans = INT_MAX;

    // do BFS
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; ++j) {
            // parent node (building)
            if (grid[i].at(j) == 1) {
                num_building ++;
                auto tmp_grid = grid;
                bfs(i, j, tmp_grid, distance, visit);
            }
        }
    }

    // find the shortest distance
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < column; j++) {
            if (visit[i].at(j) == num_building)
                ans = std::min(ans, distance[i].at(j));
        }
    }

    return ans == INT_MAX ? -1: ans;
}

/*! \brief BFS for Shortest Distance from All Buildings
 *
 *  traversing 2-D grid
 *
 * \return None
 */
void Solutions::bfs(int column, int row, std::vector< std::vector<int> > &grid, std::vector< std::vector<int> > &distance, std::vector< std::vector<int> >  &visit)
{
    // assigns starting point into parent node
    std::queue< std::pair<int, int> > to_visit; // BFS
    to_visit.push( std::pair<int, int>(column, row));

    int step = 0;

    // traversing from source (parent node)
//     std::cout << "Boundary " << grid.size() << " "  << grid[0].size() << std::endl;
    while (!to_visit.empty()) {

        // exploring 2D grid
        int curDepth = to_visit.size();
        for (int i = 0; i < curDepth; ++i) {

            int xx = to_visit.front().first;
            int yy = to_visit.front().second;

            to_visit.pop();

            // meet the boundary
            if (xx == grid.size() || xx < 0 || yy == grid[0].size() || yy <0) continue;

//             std::cout <<  "X " << xx << " Y " << yy << " Depth " << curDepth << std::endl;
            if (xx == grid.size()) std::cout << "Boundary" << std::endl;

            // Only empty land which you can pass by freely
            if (step != 0 && grid[xx].at(yy) != 0) continue;

            // Update Status
            visit[xx].at(yy)++; //how many visitor have visited here
            distance[xx].at(yy) += step;
            grid[xx].at(yy) = -1; // visited

            to_visit.push(std::pair<int, int>(xx+1, yy)); // Up
            to_visit.push(std::pair<int, int>(xx-1, yy)); // Down
            to_visit.push(std::pair<int, int>(xx, yy+1)); // Right
            to_visit.push(std::pair<int, int>(xx, yy-1)); // Left
        }

        step ++;
    }
}

/*! \brief Min Steps to Make Pilles Equal Height
 *
 *  Alex is given n piles of equal or unequal heights. In one step, Alex can remove any number of boxes from the pile which has the maximum height and try to make it equal to the one which is just lower than the maximum height of the stack. Determine the minmum number of steps required to make all of the piles equal in height.
 *
 * \return Min Steps
 */
int Solutions::minStpes( std::vector<int>& num)
{
    int steps = 0;
    std::sort(num.begin(), num.end(), std::greater<int> ());

    int i = 1;
    while ( i < num.capacity()) {
        if (num[i] != num[i-1]) {
            steps += i;
        }
        i += 1;
    }

    return steps;
}

/*! \brief Largest K such that both K and -K exist in array
 *
 *  Detailed Write a function that, given an array A of N integers, returns the lagest integer K > 0 such that values K and -K exist in array A. If there is no such integer, the function should return 0
 *
 * \return lagest integer K
 */
int Solutions::largestK( std::vector<int> & nums)
{
    std::set<int> largestval;
    int ans = 0, tmp = 0;

    for (int num : nums) {
        if (largestval.count(-num)) {
            if (num > tmp) tmp = num;
            if (num < tmp) tmp = -num;

            ans = std::max(tmp, ans);
        } else {
            largestval.insert(num);
        }
    }

    return ans;
}

/*! \brief Maximum Length of a Concatenated String with Unique
 *
 *  You are given an array of strings arr. A string s is formed by the concatenation of a subsequence of arr that has unique characters.
 *
 * \return the maximum possible length of s
 */
int Solutions::maxLength( std::vector< std::string> & arr)
{
    static int len = 0;

    if (arr.size() < 0) return 0;

    if (arr.size() == 1) return arr[0].size();

    checkLen( arr, "", 0, len);

    return len;
}

void Solutions::checkLen( std::vector<std::string> & arr, std::string str, int index, int& count )
{
    if (isUniqieString(str))
        count = str.size() > count ? str.size(): count;

    // recursive
    for (int i = index; i < arr.size(); ++i) {
        checkLen(arr, str+arr[i], i+1, count);
    }
}


/*! \brief Find N Unique Integers Sum up to Zero
 *
 *  Given an integer n, return any array containing n unique integers such that they add up to 0
 *
 * \return Array containing n unique integers such that they add up to 0
 */
std::vector<int> Solutions::sumZero(int n)
{
    std::vector<int> v;

    for (int i = 1; i <= n/2; ++i) {
        v.push_back(i);
        v.push_back(-i);
    }

    if (n%2 != 0) v.push_back(0);

    return v;
}

/*! \brief Next Permutation
 *
 *  Implement next permutation, which rearrange numbers into the lexicographically next greater permutation of numbers
 *
 *  If such an arrangement is impossible, it must rearrange it to the lowest possible order (i.e., sorted in ascending order).
 *
 *  The replacement must be in place and use only constant extra memory
 *
 *  - 
 * \return None
 */
void Solutions::nextPermutation( std::vector<int>& nums)
{
    int i = nums.size() - 2;

    while (i >= 0 && nums[i+1] <= nums [i]) {
        i--;
    }

    if (i >= 0) {
        int j = nums.size() - 1;
            while (nums[j] <= nums[i]) {
                j--;
            }
            std::swap(nums[i], nums[j]);
    }

    std::reverse(nums.begin()+i+1, nums.end());
}

/*! \brief Sign of the Product of an Array
 *
 *  Detailed There is a function signFunc(x) that returns: 
 *  - 1  of x is positive
 *  - -1 of x is negative
 *  - 0  of x is equal to 0
 *
 *  You are given an integer array nums. Let products be the product of all values in the array nums
 *
 * \return signFunc(product)
 */
int Solutions::arraySign( std::vector<int> & nums)
{
    int sign = 1;

    for (auto elem : nums) {
        if (elem < 0) sign = sign*-1;
        if (elem == 0) {
            sign = 0;
            return sign;
        }
    }

    return sign;
}

/*! \brief Count Good Nodes in Binary Tree
 *
 *  Given a binary tree root, a node X in the tree is named good if in the path from root to X there are no nodes with a value greater than X.
 *
 *
 * \return the number of good nodes in the binary tree
 */
int Solutions::goodNodes(TreeNode * root)
{
    int count = 0;

//     PrintBFS(root);
    countGoodNode(root, 0, count);

    return count;
}

void Solutions::countGoodNode(TreeNode * node, int value, int & count)
{

    /* Proposal 1. Partial Pass
    std::stack< TreeNode *> stack_node; // LIFO
    stack_node.push(node);

    TreeNode * current = nullptr;


    while (!stack_node.empty()) {

        current = stack_node.top();
        stack_node.pop();

        if (current != nullptr) {

            if ( current->val >= value) {
                count ++;
                value = current->val;
            }

            if (current->left != nullptr) stack_node.push(current->left);
            if (current->right != nullptr) stack_node.push(current->right);
        }

    }
    */

    /* Proposal 2 */ 
    if (node == nullptr) return;

    if (node->val >= value) {
        count ++;
        value = node->val;
    }

    countGoodNode(node->left, value, count);
    countGoodNode(node->right, value, count);

}

TreeNode* Solutions::insertBTNode(TreeNode* node, int value, int index)
{
    if (node == nullptr) {
        if (value != -1) node = getNewNode(value);
        return node;
    }

    if ( index % 2) {
        node->left = insertBTNode(node->left, value, index);
    } else {
        node->right = insertBTNode(node->right, value, index);
    }

    return node;
}

TreeNode* Solutions::getNewNode(int value)
{
    TreeNode * node = new TreeNode;
    node->val = value;
    node->left = nullptr;
    node->right = nullptr;

    return node;
}


std::vector<int> Solutions::PrintBFS(TreeNode * node)
{
    TreeNode* current;
    std::vector<int> bfsvector;

    std::queue<TreeNode*> node_queue;
    node_queue.push(node);

    while (! node_queue.empty()) {
        current = node_queue.front();
        node_queue.pop();

        if ( current != nullptr ) {
//             std::cout << current->val << std::endl;
            bfsvector.push_back(current->val);
            if(current->left != nullptr) node_queue.push(current->left);
            if(current->right != nullptr) node_queue.push(current->right);
        }
    }

    return bfsvector;
}

/*! \brief String Without 3 Identical Consecutive Letters
 *
 * Given a string s having lowercase English letters, returns a string with no instances of three identical consecutive letters, obtained from s by deleting the minimum possible number of letters.
 *
 * \return a string with no instance of three identical consecutive letters
 */
std::string Solutions::filterString(std::string &s)
{
    std::string letter(s.begin(), s.begin()+2);

    for (int i = 2; i < s.length(); ++i) {
        if (s[i] != s[i-1] or s[i] != s[i-2])
            letter.push_back(s[i]);
    }

    return letter;
}

/*! \brief Maximum possible value by insert 5 digit
 *
 *  Write a function that returns the maximum possible value obtained by inserting 5 digit inside the decimal representation of integer N.
 *
 * \return Maximim possivle value
 */
int Solutions::maxPossible(int num, int digit)
{
    std::vector<int> nums;

    bool isPos = true; 

    if (num < 0) {
        isPos = false;
        num = num * -1;
    }

    if (num == 0) nums.push_back(0);

    while (num > 0) {
        nums.push_back(num%10);
        num = num/10;
    }

    if (isPos) {
        for (auto it = nums.rbegin() ;  it != nums.rend(); it++) {
                if (*it < digit) {
                    //std::cout << *it << std::endl;
                    nums.insert(it.base(), digit);
                    break;
                }
        }
    } else {
        for (auto it = nums.rbegin() ;  it != nums.rend(); it++) {
            if (*it > digit) {
               //std::cout << *it << std::endl;
                nums.insert(it.base(), digit);
                break;
            };
        }
    }

    int ans = 0;
    for (auto it = nums.rbegin();  it!=nums.rend() ; it++) {
        ans = *it + ans*10;
    }

    return (isPos ? ans : -1*ans);
}

/*! \brief Delete Node in a BST
 *
 *  Given a root node reference of a BST and a key, delete the node with the given key in the BST.
 *
 * \return the root node reference (possibly updated) of the BST
 */
TreeNode* Solutions::deleteNode(TreeNode* node, int key)
{
    if (node == nullptr ) return nullptr;

    if ( key == node->val) {
        if( node->left == nullptr and node->right == nullptr) {
            delete node;
        } else if (node->left == nullptr) {
            TreeNode* tmp = node;
            node = tmp->right;
            delete tmp;
        } else if (node->right == nullptr) {
            TreeNode* tmp = node;
            node = tmp->left;
            delete tmp;
        } else {
            // Get Min from right side
            TreeNode * new_node = getMinNode(node->right);

            node->val = new_node->val;
            node->right = deleteNode(node->right, node->val); // reconstruct tree
        }
    }

    if ( key < node->val) {
        node->left = deleteNode(node->left, key);
    } else if (key > node->val) {
        node->right = deleteNode(node->right, key);
    }

    return node;
}

TreeNode* Solutions::getMinNode (TreeNode* node) {
    if (node == nullptr) return nullptr;

    if (node->left == nullptr) return node;

    return getMinNode(node->left);
}

/*! \brief Number of Fractions that Sum to 1
 *
 *  You are given a list of lists fractions where each list contains [numerator, denominator] which represents the number number/denominator
 *
 * \return the number of pairs of fractions there are that sums to 1
 */
int Solutions::sumFraction( std::vector< std::vector<int> > & fracrion)
{
    std::map < std::pair<int, int>, int > dict;
    int ans = 0;

    for (auto& elem : fracrion) {
        int g = gcd(elem[0], elem[1]);
        dict[{elem[0]/g, elem[1]/g}]++;
    }

    for (auto it = dict.begin(); it != dict.end() ; it++) {
        std::pair<int, int> key = it->first;
        int count = it->second;

        if (key.first * 2 > key.second) continue;
        if (key.first * 2 == key.second) {
            ans += count * (count - 1) /2;
        } else {
            auto it_match = dict.find({key.second - key.first, key.second});
            if ( it_match!= dict.end()) ans += count * it_match->second;  
        }
    }
    return ans;
}

int Solutions::gcd(int a, int b) {
        while (b > 0) {
        int r = a % b;
            a = b;
            b = r;
        }
        return a;
}


 /*! \brief Minimum Time to Make Rope Colorful
 *
 * Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith ballon.
 *
 * Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. 
 * You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob nees to remove the ith balloon from the rope.
 * 
 * \return Return the minimum time Bob need to make the rope colorful
 */
int Solutions::minCost( std::string colors, std::vector<int> & neededTime)
{
    int ans = 0;
    int index = 0;

    for (int i = 1; i < colors.size(); i++)
    {
        if (colors[index] == colors[i]) {
            if (neededTime[index] < neededTime[i]) {
                ans += neededTime[index];
                index = i;
            } else {
                ans += neededTime[i];
            }
        } else {
            index = i;
        }
    }
    return  ans;
}

 /*! \brief Longest Common Prefix
 *
 * Write a function to find the longest common prefix string amongst an array of strings
 * 
 * If there is no common prefix, return an empty string ""
 * 
 * \return Longest common prefix
 */
std::string Solutions::longestPrefix(std::vector< std::string > & strs)
{
    std::string ans = "";
    sort(begin(strs), end(strs));
    int last_index = strs.size() - 1;
    for (int i = 0; i < strs[0].size(); i++)
    {
        if( strs.at(0)[i] == strs.at(last_index)[i]) ans += strs.at(0)[i];
        else break;
    }

    return ans;
}

 /*! \brief Lagest K such that both K and -K exist in array
 *
 * Write a function that, given an array A of N integers, returns the lagest integer K > 0 such that both values K and -K exist in array A. 
 * If there is no such integer, the function should return 0
 *
 * \return latgest K
 */
int Solutions::getLargestK( std::vector<int> & nums){

    // initial a hash set
    std::unordered_set<int> set;
    int max = 0;

    // insert a new key
    for(auto var : nums)
    {
        set.insert(var);
    }

    // check if the key is in the hash set
    for(auto var : nums)
    {
        // Iterator to an element with key equivalent to key. If no such element is found, past-the-end (see end()) iterator is returned.
        if (set.find(-var) != set.end() and var > max)
        {
            max = var;
        }
    }
    return max;
}

/*! \brief Smallest Positive Integer
 *
 *  Write a function that, given an array A of N integers, returns the smallest positive integer (greater than 0) that does not occur in A.
 *
 *  For example, given A = [1, 3, 6, 4, 1, 2], the function should return 5.
 *  Given A = [1, 2, 3], the function should return 4.
 *  Given A = [-1, -3], the function should return 1.
 *
 *
 * \return  smallest positive integer
 */
int Solutions::smallestInt( std::vector<int> &A )
{
    int ans = 0;

    std::vector<int> v(A.size(), 0);
    for (auto elem : A) {
        if (elem > 0) v[elem] ++;
    }

    int i;
    for (i = 1 ; i < v.size(); i ++) {
        if (v[i] == 0) return i;
    }

    return i + 1;

}


/*! \brief Maximum sequence of consecutive zeros
 *
 *  A binary gap within a positive integer N is any maximum sequence of consecutive zeros that is surrounded by ones at both ends in the binary representation of N. For example, number 9 has binary representation 1001 and contains a binary gap of length 2
 *
 * \return maximum sequence of consecutive zeros
 */
int Solutions::lengthBin(int N)
{
    std::bitset<16> binary(N) ;

    std::string bit = binary.to_string();

    int ans = INT_MIN, max = 0;
    for (auto elem : bit) {
        if( elem == '0') {
            max ++;
        } else {
            if (max > ans and max != 0 and max < 6) ans = max;
            max  = 0;
        }
    }

    return (ans == INT_MIN) ? 0: ans;
}

/*! \brief The Monty Hall Problem
 *
 *  The Monty Hall problem is a famous conundrum in probability which takes the form of a hypothetical game show. The contestant is presented with three doors; behind one is a car and behind each of the other two is a goat. The contestant picks a door and then the gameshow host opens a different door to reveal a goat. The host knows which door conceals the car. The contestant is then invited to switch to the other closed door or stick with their initial choice.
 *
 * \return probability
 */
float Solutions::montyHall(int guess)
{
    int winningNum = 0;
    int switchedNum = 0;
    int switchedCount = 0;
    int elimNum = 0;

    for (int i = 0; i < 1000; ++i) {
        winningNum = getRandom(1, 3, 0);
        elimNum = getRandom(1, 3, winningNum);
        switchedNum = getRandom(1, 3, elimNum);

        while (switchedNum == guess ) {
            switchedNum = getRandom(1, 3, winningNum);
        }

        if (switchedNum == winningNum) switchedCount ++;

    }

    return 100 - (switchedCount / 10);
}

int Solutions::getRandom(int low, int high, int badNum)
{
    int random = rand() % high + low;

    while ( random == badNum ) {
        random = rand() % high + low;
    }

    return random;
}


/*! \brief Minimum number of letters
 *
 *  You are given a string S consisting of N lowercase letters. In one move you can remove any substring from S, which starts and ends with the same letter and is at least two letters long. What is the minimum number of letters that may remain in S after any number of such moves?
 *
 * \return minimum number of letters
 */
int Solutions::lowercaseLetters( std::string &S)
{
    int ans = 0;
    int startnumber = 0;

    if (S.size() == 0 or S.size() == 1) return S.size();

    for (auto it = S.begin() + 1;  it!=S.end() ; it++) {
        if (*it == *S.begin()) {
            startnumber ++;
            if (*(it++) == *(it)) {
                startnumber ++;
            }
            break;
        } else {
            startnumber ++;
        }
    }


    if (startnumber + 1 == S.size()) S.erase(0, startnumber );

    else S.erase(0, startnumber +1 );


    int endnumber = S.size();

    if (S.size() != 1) {
        for (auto it = S.rbegin() + 1;  it!=S.rend() ; it++) {
            if (*it == *S.rbegin()) {
                endnumber --;
                break;
            } else {
                endnumber --;
            }
        }

        S.erase(endnumber - 1, S.size());
    }

    return S.size();
}


/*! \brief Balanced Stone Heaps
 *
 *  There are n heaps of stone. The i-th heap has hi stones. You want to change the number of stones in the heap by performing the following process once:
 *
 *  - You go through the heaps from the 3-rd heap to the n-th heap, in this order.
 *  - Let i be the number of the current heap
 *  - You can choose a number d, move d stones from the i-th heap to the (i-1)th heap, and 2*d stones from the i-th heap to the (i-2)th heap.
 *  - So after that hi is decreased by 3*d, hi-1 is increased by d, and hi-2 is increased by 2*d.
 *  - You can choose different or same d for different operations. Some heaps may become empty, but they still count as heaps.
 *
 * \return the maximum number of stones in the smallest heap after the process.
 */
int Solutions::balancedStone( std::vector<int> &A)
{

    for (int i = 2, p; i < A.size(); ++i) {

        p = A[i]/3;

        if (p == 0){
            return 1;
            break;
        }

        A[i] -= p *3;
        A[i - 1] += p;
        A[i - 2] += p*2;
    }

    return A[0];
}


/*! \brief Course Schedule III
 *
 *  There are n different online courses numbered from 1 to n, You are given an array courses where courses[i] = [duration, lastDayi] indicate that the ith course should be taken continuously for duration days and must be finished before or on lastDayi.
 *
 *  You will start on the 1st day and you cannot take two or more courses simultaneously.
 *
 * \return the maximum number of courses that you can take
 */
int Solutions::scheduleCourse( std::vector< std::vector<int> > & courses)
{
    int totalcourse = 0;
    int time = 0;
    std::priority_queue<int> duration;

    for (int i = 0; i < courses.size(); ++i) {
        if (time + courses.at(i)[0] <= courses.at(i)[1]) {
            time += courses.at(i)[0];
            duration.push(courses.at(i)[0]);
        } else if (!duration.empty() && duration.top() > courses.at(i)[0]) {
            time = (duration.top() - courses.at(i)[0]);
            duration.pop();
            duration.push(courses.at(i)[0]);
        }
    }

    return duration.size();
}

/*! \brief Minimum characters required to be removed to make frequency of each character unique
 *
 *  Given string str, the task is to find the minimum count of characters that need to be deleted from the string such that the frequency of each character of the string is unique
 *
 * \return minimum removals required
 */
int Solutions::uniqueString( std::string &S)
{
    std::vector<int> asciicode(26);

    for (auto elem : S) {
        asciicode[elem - 'a'] ++;
    }

    std::map<int, int> frequencychar;
    for (int i = 0; i < 26; ++i) {
        frequencychar[asciicode[i]] ++;
    }

    int ans = 0;

    for (auto it = frequencychar.rbegin();  it != frequencychar.rend() ; ++it) {
        int ascii = it->first;
        int count = it->second;

        if (ascii == 0 or count == 1) continue; // 

        int new_count = count - 1;
        frequencychar[ascii - 1] = new_count;
        ans += new_count;
    }

    return ans;
}


/*! \brief Meeting rooms
 *
 *  Given an 2D integer array A of size N x 2 denoting time intervals of different meetings.
 *  Where:
 *  A[i][0] = start time of the ith meeting.
 *  A[i][1] = end time of the ith meeting.
 *
 *  Find the minimum number of conference rooms required so that all meetings can be done.
 *
 * \return minimum meetings rooms
 */
int Solutions::storeMeetingrooms( std::vector< std::vector<int> > & rooms)
{
    int room = INT_MIN;

    std::vector< std::pair<int, int> > meeting;

    for (int i = 0; i < rooms.size(); ++i) {
        int start = rooms.at(i)[0];
        int end = rooms.at(i)[1];

        meeting.push_back( {start, 0});
        meeting.push_back( {end, 1});
    }

    sort(meeting.begin(), meeting.end());
    int count = 0;
    for (int i = 0; i < meeting.size() - 1; ++i) {

        if (meeting.at(i).second == 0) {
            count ++;
        } else {
            count --;
        }
        if (meeting.at(i).first != meeting.at(i+1).first) room = std::max(room, count);
    }

    return room;
}

/*! \brief Minimum Number of Arrows to Burst Balloons
 *
 *  There are some spherical balloons taped onto a flat wall that represents the XY-plane. The balloons are represented as a 2D integer array points where points[i] = [xstart, xend] denotes a balloon whose horizontal diameter stretches between xstart and xend. You do not know the exact y-coordinates of the balloons.
 *
 *  Arrows can be shot up directly vertically (in the positive y-direction) from different points along the x-axis. A balloon with xstart and xend is burst by an arrow shot at x if xstart <= x <= xend. There is no limit to the number of arrows that can be shot. A shot arrow keeps traveling up infinitely, bursting any balloons in its path.
 *  Given the array points, return the minimum number of arrows that must be shot to burst all balloons.
 *
 * \return minimum number of arrows that must be shot to burst all balloons
 */
bool cmp ( std::vector<int> &a, std::vector<int> &b) { return a.at(1) < b.at(1); }

int Solutions::findMinArrowShots( std::vector< std::vector<int> > & points)
{
    int ans = 0, arrow = 0;

    std::sort(points.begin(), points.end(), cmp);
    for (int i = 0; i < points.size(); ++i) {
        if( ans == 0 or points.at(i)[0] > arrow) {
            ans ++;
            arrow = points.at(i)[1];
        }
    }
    return ans;
}

/*! \brief The Maximum Number of Full Rounds
 *
 * John has recently discovered an online game. In the game, a 15-minute round starts in each quarter-hour period, starting at times notated in the format HH: 00, HH: 15, HH: 30 Or HH: 45, where HH is a number from de to 23. John uses a 24 hour clock, so the earliest time is 00:00 and the latest is 23:59. John starts playing at time A and ends at time B. If B is earlier than A, John has played overnight (from time A to midnight and from midnight to time B). What is the maximum number of full rounds that can be played by John? Write a function: that, given two strings A and B (in HH: MM format), representing the start time and end time, returns an integer denoting the maximum number of full rounds that John can play within the given period of time.
 *
 * Examples:
 * 1. Given A = "12:01" and B = "12:44", the function should return 1. John can play only one round (from 12:15 to 12:30). He starts too late to play the round from 12:00 to 12:15 and he will not be able to finish the 12:30-12:45 round.
 *
 * 2. Given A = "20:00" and B = "06:00", the function should return 40. John can play 16 game rounds from 20:00 to 0:00 and 24 game rounds from 00: 00 to 06:00.
 *
 * 3. Given A = "00:00" and B = "23:59", the function should return 95. John can play four rounds every hour except for the last hour, in which he can play only three rounds (23:00-23:15, 23:15-23:30,23:30-23:45). The next round would be 23:45-00:00 but John has to end 1 minute sooner, so he cannot take part in it.
 *
 * 4. Given A = "12:03" and B = "12:03", the function should return 0. John cannot play any round
during an empty period of time.
 *
 *
 * \return Maximum number of Full Rounds
 */
int Solutions::maxFullRound( std::string &A, std::string &B)
{
    float min_a = boost::lexical_cast<float>( A.substr(3, 2).c_str());
    float hr_a = boost::lexical_cast<float>( A.substr(0, 2).c_str());
    float min_b = boost::lexical_cast<float>( B.substr(3, 2).c_str());
    float hr_b = boost::lexical_cast<float>( B.substr(0, 2).c_str());

    int time = 0;

    if ( hr_a - 12 > 0 and hr_b - 12 > 0) {
        // Count A
        if (min_a == 0) {
            time += (24 - hr_a) * 4;
        }else {
            time += (24 - hr_a - 1) * 4;
            while (min_a < 60) {
                min_a = std::ceil(min_a/15)*15 + 15;
                time ++;
            }
        }

        // Count B
        if (min_b == 0) {
            time += (24 - hr_b) * 4;
        }else {
            time += (24 - hr_b - 1) * 4;
            time += (std::floor(min_b / 15));
        }
    } else if (hr_a - 12 > 0 and hr_b - 12 <= 0) {
        // Count A
        if (min_a == 0) {
            time += (24 - hr_a) * 4;
        }else {
            time += (24 - hr_a - 1) * 4;
            while (min_a < 60) {
                min_a = std::ceil(min_a/15)*15 + 15;
                time ++;
            }
        }

        // Count B
        if (min_b == 0) {
            time += (hr_b) * 4;
        }else {
            time += (24 - hr_b - 1) * 4;
            time += (std::floor(min_b / 15));
        }

    } else if (hr_a - 12 <= 0 and hr_b - 12 > 0) {
        // Count A
        if (min_a == 0) {
            time += (hr_b - hr_a) * 4;
        } else {
            time += (hr_b - hr_a - 1) * 4;
            while (min_a < 60) {
                min_a = std::ceil(min_a/15)*15 + 15;
                time ++;
            }
        }

        // Count B
        if (min_b == 0) {
            time += (24 - hr_b) * 4;
        }else {
            time += (24 - hr_b - 1) * 4;
            time += (std::floor(min_b / 15));
        }


    } else {
        while (min_a < 60) {
            min_a = std::ceil(min_a/15)*15 + 15;
            if (min_a < min_b) time ++;
            else break;
        }

    }

    return time;
}

int Solutions::solutions2( std::vector<int>  &A)
{
    int ans = 0;
    int index = 0;

    for (auto it = A.begin();  it!=A.end() ; it++) {
        ans += *it;

        if (ans < 0) {
            it = A.erase(it);
            index ++;
        }
    }

    return index;
}

/*! \brief Maximum Possible Sum of Values of the Edges' Endpoints
 *
 *  You are given an undirected graph consisting of N vertices, numbered from 1 to N, and M edges. The graph is described by two arrays, A and B, both of length M. A pair (A[K], B[K]), for K from 0 to M-1, describes an edge between vertex A[K] and vertex B[K].
 *
 *  Your task is to assign all values from the range [1..N] to the vertices of the graph, giving one number to each of the vertices. Do it in such a way that the sum over all edges of the values at the edges' endpoints is maximal.
 *
 *  For example, given N = 5, A = [2, 2, 1, 2], B = [1, 3, 4, 4], the graph has four edges: (2, 1), (2, 3), (1, 4), (2, 4). In order to obtain the maximum sum of weights, you can assign the following values to the vertices: 3, 5, 2, 4, 1 (to vertices 1, 2, 3, 4, 5 respectively).
 *
 *  Picture illustrates the first example test
 *
 *  This way we obtain the sum of values at all edges' endpoints equal to 7 + 8 + 7 + 9 = 31:
 *
 *  edge (2, 3): 7 = 5 (vertex 2) + 2 (vertex 3)
 *  edge (2, 1): 8 = 5 (vertex 2) + 3 (vertex 1)
 *  edge (1, 4): 7 = 3 (vertex 1) + 4 (vertex 4)
 *  edge (2, 4): 9 = 5 (vertex 2) + 4 (vertex 4)
 *  Notice that the value assigned to vertex 5 did not have any effect on the final result as it is not an endpoint of any edge.

 * Write a function: function solution($N, $A, $B); that, given a positive integer N and two arrays A, B of M positive integers, returns the maximum possible sum of values of the edges' endpoints.
 *
 *
 * \return maximum possible sum of values of the edges' endpoints
 */
bool cmpmap( std::pair<int, int> &a, std::pair<int, int> &b) {
    return a.second > b.second;
}
int Solutions::maximumSum(int N, std::vector<int> &A, std::vector<int> &B)
{
    /* Solution 1
    int sum = 0;
    std::vector<int> vertexcount (N, 0);

    for (auto elem : A) {
        vertexcount[elem] ++;
    }

    for (auto elem : B) {
        vertexcount[elem] ++;
    }

    std::vector<int> vertex(N, 0);
    for (int i = 0; i < vertexcount.size(); ++i) {
        vertex[i] = vertexcount[i];
    }

    std::vector<int> wightvertex(N, 0);
    while (!vertexcount.empty()) {
        auto maxcount = std::max_element(vertexcount.begin(), vertexcount.end());

        for (int i = 0; i < vertex.size(); ++i) {
            if (vertex[i] == *maxcount and wightvertex[i] == 0) {
                wightvertex[i] = N;
                N--;
            }
        }
        vertexcount.erase(maxcount);
    }

    for (int i = 0; i < A.size(); ++i) {
        sum += wightvertex[A[i]] + wightvertex[B[i]];
    }

    return sum;
    */

    int sum = 0;
    std::map<int, int> vertexcount;

    for (auto elem : A) {
        vertexcount[elem] ++;
    }

    for (auto elem : B) {
        vertexcount[elem] ++;
    }

    std::vector< std::pair<int, int> > vertex;

    for (auto &it : vertexcount) {
        vertex.push_back(it);
    }

    std::sort(vertex.begin(), vertex.end(), cmpmap);

    std::vector<int> wightvertex(N+1,0);
    for (auto it = vertex.begin(); it != vertex.end(); it++) {
        wightvertex.at(it->first) = N;
        N --;
    }

    for (int i = 0; i < A.size(); ++i) {
        sum += wightvertex[A[i]] + wightvertex[B[i]];
    }

    return sum;
}


/*! \brief Contains Duplicate
 *
 *  Given an integer array nums, retuen true if any value appears at least twice in the array, and return false if every elements is distinct.
 *
 * \return if every elements is distinct return false. Otherwise, return true
 */
bool Solutions::containDup( std::vector<int> & nums)
{
    std::unordered_set<int> set;

    bool isDuplicate = false;
    // Inserts element(s) into the container, if the container doesn't already contain an element with an equivalent key.
    for (auto elem : nums) {
        auto it = set.insert(elem);
        if (!it.second) isDuplicate = true;
    }

    return isDuplicate;
}


/*! \brief Single Number
 *
 *  Given a non-empty array of integers nums, every element appears twice expect for one. Find that single one. You must implement a solution with a linear runtime complexity and use only constant extra space.
 *
 * \return Single Number
 */
int Solutions::singleNumber( std::vector<int> & nums)
{
    /*
    std::unordered_set<int> set;
    int singlenum = -1;
    for (auto elem : nums) {
        if(set.count(elem)) set.erase(elem);
        else set.insert(elem);
    }

    return *set.begin();
    */

    int num = 0;

    for (auto elem : nums) {
        num ^= elem;
    }

    return num;

}

/*! \brief Intersection of Two Arrays
 *
 * Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
 *
 * \return intersection array
 */
bool binarySearch( std::vector<int> & nums, int target)
{
    int left = 0, right = nums.size();
    while (left < right) {
        int mid = left + (right - left)/2;
        if(nums.at(mid) == target) return true;
        else if (nums.at(mid) < target) left = mid + 1;
        else right = mid;
    }
    return false;
}

std::vector<int> Solutions::intersection( std::vector<int> & nums1, std::vector<int> & nums2)
{
    /*
    std::unordered_set<int> set(nums1.begin(), nums1.end()), intersection; // Complexity: Constant.

    for (auto elem : nums2) {
        // Time Complexity: Time Complexity for unordered_set::count() method is O(1) in average cases, but in worst case, time complexity can be O(N) 
        if (set.count(elem)) intersection.insert(elem);
    }

    return std::vector<int>(intersection.begin(), intersection.end()); // The complexity is linear in the number of elements inserted plus the distance to the end of the vector.
    */

    std::unordered_set<int> intersection;
    std::sort(nums2.begin(), nums2.end());

    for (auto elem : nums1) {
        if (binarySearch(nums2, elem)) intersection.insert(elem);
    }

    return std::vector<int>(intersection.begin(), intersection.end()) ;
}



/*! \brief Happy Number
 *
 *  Write an algorithm to determine if a number n is happy.
 *
 *  Starting with any positive integer, replace the number by the sum of the squares of its digits.
 *  Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
 *  Those numbers for which this process ends in 1 are happy.
 *
 * \return true if n is a happy number, and false if not
 */
bool Solutions::isHappy(int n)
{   
    
    while ( n != 1 and n != 4 ) {
        int sum = 0, digit = 0;
        while (n > 0) {
            digit = n%10;
            sum += digit*digit;
            n = n/10;
        }
        n = sum;
    }

    return n == 1 ? true: false;
}





} /* namespace leetcode */
