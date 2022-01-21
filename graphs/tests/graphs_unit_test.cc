#include "gtest/gtest.h"
#include "./src/graph.h"

namespace googletest {
class ConverterTest : public testing::Test {};

TEST_F(ConverterTest, str2numTest) 
{
    /* Declare the Unit Test object */
    common::Convert convert;

    std::string name = "louis";

    long expected_value = 1114200818;

    EXPECT_EQ(expected_value,convert.str2num(name));
}

TEST_F(ConverterTest, isValidCharTest) 
{
    /* Declare the Unit Test object */
    common::Convert convert;

    std::string name = "l$ouis";

    long expected_value = 1114200818;

    EXPECT_EQ(expected_value, convert.str2num(name));
}




TEST_F(ConverterTest, num2strTest) 
{
    /* Declare the Unit Test object */
    common::Convert convert;
    long id = 1114200818;

    std::string expected_value = "louis";

    EXPECT_EQ(expected_value,convert.num2str(id));
}


} /* namespace googletest */
