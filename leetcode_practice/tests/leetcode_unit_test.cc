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





} /* namespace googletest */
