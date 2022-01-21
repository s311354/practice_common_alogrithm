#include "gtest/gtest.h"
#include "src/solutions.h"

namespace googletest {

class SolutionsTest : public testing::Test {};

TEST_F(SolutionsTest, minDeletionsTest) 
{
    /* Declare the Unit Test object */
    leetcode::Solutions solutions;
    std::string input = "aaabbccdddtt";
    EXPECT_EQ(6, solutions.minDeletions(input));
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



} /* namespace googletest */
