#include <string>
#include "gtest/gtest.h"
#include "src/linked_list.h"

namespace googletest {
class SizeTest : public testing::Test {};

TEST_F(SizeTest, SizeEmpty) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;

    EXPECT_EQ(0,lists.Size());
}

TEST_F(SizeTest, Size) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;

    lists.PushFront(3);
    lists.PushFront(2);
    EXPECT_EQ(2,lists.Size());
}

class FrontTest : public testing::Test {};

TEST_F(FrontTest, Front) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;
    int golden_value = 100;

    lists.PushFront(golden_value);
    EXPECT_EQ(golden_value, lists.Front());
}

class BackTest : public testing::Test {};

TEST_F(BackTest, Back) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;
    int golden_value = 100;

    lists.PushBack(golden_value);
    EXPECT_EQ(golden_value,lists.Back());
}

class PopFrontTest : public testing::Test {};

TEST_F(PopFrontTest, PopFront) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;
    int golden_value = 100;

    lists.PushFront(golden_value);

    EXPECT_EQ(golden_value,lists.PopFront());
}

class PopBackTest : public testing::Test {};

TEST_F(PopBackTest, PopBack) {
    /* Declare the Unit Test object */
     common::LinkedList<int> lists;
     int golden_value = 100;

     lists.PushFront(golden_value);
     EXPECT_EQ(golden_value,lists.PopBack());
}

class ValueAtTest : public testing::Test {};

TEST_F(ValueAtTest, ValueAt) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;
    lists.PushFront(100);
    lists.PushFront(200);
    lists.Insert(2, 300);

//     lists.PrintDebug();

    EXPECT_EQ(200,lists.ValueAt(0));
    EXPECT_EQ(300,lists.ValueAt(2));
}

class EraseTest : public testing::Test {};

TEST_F(EraseTest, Erase) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;

    lists.PushFront(10);
    lists.Erase(0);
    EXPECT_EQ(0,lists.Size());
}

class RemoveValueTest : public testing::Test {};

TEST_F(RemoveValueTest, RemoveValue) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;

    lists.PushFront(6);
    lists.RemoveValue(6);

    EXPECT_EQ(0,lists.Size());
}

class ReverseTest : public testing::Test {};

TEST_F(ReverseTest, Reverse) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;

    lists.PushFront(10);
    lists.PushFront(11);
    lists.PushFront(12);

//     lists.PrintDebug();
    lists.Reverse();
//     lists.PrintDebug();

    EXPECT_EQ(10,lists.PopFront());
    EXPECT_EQ(11,lists.PopFront());
    EXPECT_EQ(12,lists.PopFront());
}

class ValueNFromEndTest : public testing::Test {};

TEST_F(ValueNFromEndTest, ValueNFromEnd) {
    /* Declare the Unit Test object */
    common::LinkedList<int> lists;

    lists.PushBack(1);
    lists.PushBack(2);
    lists.PushBack(3);

    lists.PrintDebug();
    EXPECT_EQ(3,lists.ValueNFromEnd(1));
    EXPECT_EQ(2,lists.ValueNFromEnd(2));
    EXPECT_EQ(1,lists.ValueNFromEnd(3));
}


} /* namespace unit */
