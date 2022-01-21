#include "./solutions.h"

namespace leetcode {

bool Solutions::isPalindrome(std::string s)
{
    int start = 0, end = s.length() - 1;

    while (start < end) {
        if (isValidChar(s[start]) && isValidChar(s[end])) {
            if (s[start] == s[end]) {
                start ++;
                end --;
            } else {
                return false;
            }
        } else if (isValidChar(s[start])) {
            ++start;
            continue;
        } else if (isValidChar(s[end])) {
            ++end;
            continue;
        } else {
            continue;
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

        std::cout << "va" << std::endl;
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

    // Traverse map from backwards
    for (auto it = mp.rbegin();  it!=mp.rend() ; ++it) {
        int key = it->first;
        int val = it->second;

//         std::cout &lt;&lt; "key: " &lt;&lt; key  &lt;&lt; " value: " &lt;&lt; val &lt;&lt; std::endl;
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
            for (left_index = start + 1; left_index <= end - start && s[left_index] != s[end - start]; ++left_index);
            for (right_index = end - start - 1; right_index >= start && s[right_index] != s[start]; --right_index);

            // choose minimum distance between left side or right side
            ans += std::min(left_index - start, end - start - right_index);
            if (left_index - start < end - start - right_index) {
                for (int p = left_index; p > start; --p) {
                    std::swap(s[p], s[p-1]);
                } 
            } else {
                for (int p = right_index; p < end - start; ++p) {
                     std::swap(s[p], s[p+1]);
                }
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
        node = getNewNode(value);
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


void Solutions::PrintBFS(TreeNode * node)
{
    TreeNode* current;

    std::queue<TreeNode*> node_queue;
    node_queue.push(node);

    while (! node_queue.empty()) {
        current = node_queue.front();
        node_queue.pop();

        if ( current != nullptr ) {
            std::cout << current->val << std::endl;
            if(current->left != nullptr) node_queue.push(current->left);
            if(current->right != nullptr) node_queue.push(current->right);
        }
    }

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

/*! \brief Maximum possible value by inserting '5'
 *
 *  
 *
 * \return Maximum possible value
 */
int Solutions::maxPossible(int num, int digit)
{
    std::vector<int> nums;

    bool isPos = num > 0 ? true: false;

    if (num == 0) nums.push_back(0);

    while (num > 0) {
        nums.push_back(num%10);
        num = num/10;
    }

    if (isPos) {
        for (auto it = nums.begin() ;  it != nums.end() ; it++) {
            if (*it <= digit) nums.insert(it, digit);
        }

    } else {
        for (auto it = nums.begin() ;  it != nums.end() ;) {
            if (*it > digit) it = nums.insert(it, digit);
        }
    }

    int ans = 0;
    for (auto it = nums.end();  it!=nums.begin() ; it--) {
        ans = *it + ans*10;
    }

    return isPos ? ans : -1*ans;
}

} /* namespace leetcode */
