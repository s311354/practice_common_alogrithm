#include <iostream>
#include "gtest/gtest.h"
#include "src/queue_linked_list.h"

namespace googletest {

class EnqueueTest : public testing::Test {};

TEST_F(EnqueueTest, Enqueue) 
{
    /* Declare the Unit Test object */
    common::QueueLinkedList<int> queue_lists;

    queue_lists.Enqueue(10);
    queue_lists.Enqueue(20);

    EXPECT_EQ(10,queue_lists.Dequeue());
    EXPECT_EQ(20,queue_lists.Dequeue());
}

class EmptyTest : public testing::Test {};

TEST_F(EmptyTest,Empty) 
{
    /* Declare the Unit Test object */
    common::QueueLinkedList<int> queue_lists;

    EXPECT_TRUE(queue_lists.Empty());
}




} /* namespace googletest */
