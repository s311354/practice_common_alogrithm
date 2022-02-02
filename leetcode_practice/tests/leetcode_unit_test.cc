#include "gtest/gtest.h"
#include "src/solutions.h"
#include <iostream>
#include <fstream>


namespace googletest {

class SolutionsTest : public testing::Test {};

TEST_F(SolutionsTest, minDeletionsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::string input = "aaabbccdddtt";
    int expected_value = 6;
    EXPECT_EQ(expected_value, solutions.minDeletions(input));

    input = "ceabaacb";
    expected_value = 2;

    EXPECT_EQ(expected_value, solutions.minDeletions(input));


}

TEST_F(SolutionsTest, MinSwapTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::string input = "mamad";

    EXPECT_EQ(3, solutions.minSwaps(input));
}

TEST_F(SolutionsTest, TwoSumTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {2, 7, 11, 15};
    int target = 9;
    std::vector<int> output = {0, 1};

    for (int i = 0; i < solutions.twoSum(nums, target).capacity(); ++i) {
        EXPECT_EQ(output[i], solutions.twoSum(nums, target)[i]);
    }
}

TEST_F(SolutionsTest, ShortestDistanceTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<int> > grid = {{1, 0, 2, 0 ,1}, {0, 0, 0, 0, 0}, {0, 0, 1, 0, 0}};


    EXPECT_EQ( 7, solutions.shortestDistance(grid));
}

TEST_F(SolutionsTest, minStpesTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> piles = {1, 2, 2, 3, 3, 4};
    int minsteps = 9;

    EXPECT_EQ(minsteps, solutions.minStpes(piles));
}


TEST_F(SolutionsTest, largestKTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> array = {-41,3,2,5,41 };
    int expected_value = 41, result_value = solutions.largestK(array);

    EXPECT_EQ(expected_value,result_value);
}


TEST_F(SolutionsTest, maxLengthTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::string> arr {"un", "iq", "ue"};
    int expected_value = 4;

    EXPECT_EQ(expected_value, solutions.maxLength(arr));
}


TEST_F(SolutionsTest, sumZero) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> expected_value = {1,-1,2,-2,0};

    for (int i = 0; i < expected_value.capacity(); ++i) {
        EXPECT_EQ(expected_value[i], solutions.sumZero(5)[i]);
    }
}

TEST_F(SolutionsTest, nextPermutationTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    
    std::vector<int> v = {1, 3, 5, 4, 2};
    std::vector<int> expected_value = {1, 3, 5, 4, 2};

    solutions.nextPermutation(v);
    std::next_permutation(expected_value.begin(), expected_value.end());

    for (int i = 0; i < expected_value.size(); ++i) {
        EXPECT_EQ(expected_value[i], v[i]); 
    }



}

TEST_F(SolutionsTest, arraySignTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> nums = {-1,-2,-3,-4,3,2,1};
    int expected_value = 1;

    EXPECT_EQ(expected_value, solutions.arraySign(nums));
}

TEST_F(SolutionsTest, goodNodesTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> v = {3,3,-1,4,2};
    leetcode::TreeNode * root = nullptr;

    int expected_value = 3;
    for (int i = 0; i < v.size(); ++i) {
        root = solutions.insertBTNode(root, v[i], i);
    }

    EXPECT_EQ(expected_value, solutions.goodNodes(root));
}

TEST_F(SolutionsTest, filterStringTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::string input = "uuuuxaaaaxum";
    std::string expected_value = "uuxaaxum";

    EXPECT_EQ(expected_value,solutions.filterString(input));
}

TEST_F(SolutionsTest, maxPossibleTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    int input = 7643;
    int expected_value = 76543;

    EXPECT_EQ(expected_value,solutions.maxPossible(input, 5));


    /* Declare the Unit Test object */
    input = -661;
    expected_value =  -5661;

    EXPECT_EQ(expected_value,solutions.maxPossible(input, 5));
}


TEST_F(SolutionsTest, deleteNodeTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> v = {5,3,6,2,4,-1,7};
    int key = 3;
    leetcode::TreeNode * root = nullptr;

    for (int i = 0; i < v.size(); ++i) {
        root = solutions.insertBTNode(root, v[i], i);
    }

    leetcode::TreeNode * new_node = solutions.deleteNode(root, key);

    std::vector<int> actual_value = solutions.PrintBFS(new_node);

    std::vector<int> expected_value = {5,2,6,4,7}; // {5,2,6,null,4,null,7}


    for (int i = 0; i < expected_value.size(); i++) {
        EXPECT_EQ(expected_value[i], actual_value[i]);
    }
}

TEST_F(SolutionsTest, sumFractionTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;;
    std::vector< std::vector<int> > fractions = {{1,4}, {2,5}, {3,4}, {3,5}, {5, 10}, {1,2}, {1,2}};

    int result_value = solutions.sumFraction(fractions);

    int expected_value = 5;

    EXPECT_EQ(expected_value,result_value);
}

TEST_F(SolutionsTest, minCostTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> neededTime = {3,5,10,7,5,3,5,5,4,8,1};
    std::string colors = "aaabbbabbbb";
    int expected_value = 26;

    EXPECT_EQ(expected_value, solutions.minCost(colors, neededTime));
}

TEST_F(SolutionsTest, longestPrefixTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::string> prefix = {"dog","racecar","car"};
    std::string expected_value = "";

    EXPECT_EQ(expected_value, solutions.longestPrefix(prefix));
}

TEST_F(SolutionsTest, getLargestLTest)
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> input {3,2,-2,5,-3};
    int expected_value = 3;

    EXPECT_EQ(expected_value, solutions.getLargestK(input));
}

std::vector<int> parseInts(const std::string & str)
{
    std::vector<int> v;

    std::stringstream ss(str);

    std::string temp;

    while (ss >> temp) {
        std::stringstream st(temp);
        while (st) {
            int i;

            if (st >> i) {
                v.push_back(i);
            } else {
                st.clear();
                st.get();
            }
        }
    }
    return  v;
}

TEST_F(SolutionsTest, balancedStoneTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::ifstream ifs;

    char buffer[256] = {0};

    ifs.open("./balancedstone.txt");

    std::vector<int> expected_value = {7, 1, 1, 3};
    int index = 0;

    std::string line;
    while (std::getline(ifs, line)) {
        std::istringstream iss(line);
        std::vector<int> v = parseInts(line);

        if (v.size() > 1) {
            EXPECT_EQ(expected_value.at(index), solutions.balancedStone(v));
            index ++; 
        }
    }
}

TEST_F(SolutionsTest, smallestIntTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector<int> input = {1, 3, 6, 4, 1, 2};
    int expected_value = 5;
    EXPECT_EQ(expected_value, solutions.smallestInt(input));


    input = {1, 2, 3};
    expected_value = 4;
    EXPECT_EQ(expected_value, solutions.smallestInt(input));

    input = {-1, -1, -2};
    expected_value = 1;
    EXPECT_EQ(expected_value, solutions.smallestInt(input));
}


TEST_F(SolutionsTest, lengthBinTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int input = 9;
    int expected_value = 2;

    EXPECT_EQ(expected_value, solutions.lengthBin(input));

    input = 15;
    expected_value = 0;
    EXPECT_EQ(expected_value, solutions.lengthBin(input));

    input = 1041;
    expected_value = 5;
    EXPECT_EQ(expected_value, solutions.lengthBin(input));

}

TEST_F(SolutionsTest, montyHallTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
}

TEST_F(SolutionsTest, lowercaseLettersTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    int expected_value = 1;

    std::string input = "abccac";

    EXPECT_EQ(expected_value,solutions.lowercaseLetters(input));


    expected_value = 2;

    input = "abcdabcdabcd";

    EXPECT_EQ(expected_value,solutions.lowercaseLetters(input));


    expected_value = 0;
    input = "axaabyab";

    EXPECT_EQ(expected_value,solutions.lowercaseLetters(input));


}



TEST_F(SolutionsTest, scheduleCourseTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<int> > courses =  {{100,200},{200,1300},{1000,1250},{2000,3200}};
    \

    int expected_value = 3;
    EXPECT_EQ(expected_value, solutions.scheduleCourse(courses));

    courses = {{3,2}, {4,3}};

    expected_value = 0;
}


TEST_F(SolutionsTest, uniqueStringTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::string input = "abbbcccd";
    int expected_value = 2;

    EXPECT_EQ(expected_value, solutions.uniqueString( input));
}

TEST_F(SolutionsTest, storeMeetingroomsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;

    std::vector< std::vector< int> > room = { {0, 30}, {5, 10}, {15, 20} };
    int expected_value = 2;

    EXPECT_EQ(expected_value,solutions.storeMeetingrooms(room));

    room = {{1, 18}, {18, 23}, {15, 29}, {4, 15}, {2, 11}, {5, 13}};
    expected_value = 4;
    EXPECT_EQ(expected_value,solutions.storeMeetingrooms(room));
}

TEST_F(SolutionsTest, findMinArrowShotsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::vector< std::vector<int> >  points = {{10, 16}, {2, 8}, {1, 6}, {7, 12}};
    int expected_value = 2;

    EXPECT_EQ(expected_value, solutions.findMinArrowShots(points));

    points = {{1,2}, {2,3}, {3,4}, {4,5}};
    expected_value = 2;
    EXPECT_EQ(expected_value, solutions.findMinArrowShots(points));
}

} /* namespace googletest */
