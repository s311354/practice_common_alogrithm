#include "./jvector_test.h"
#include "./jvector.h"
#include <iostream>

namespace common {

// Unit test
void JvectorTest::RunTests() const {
    TestSize();
    TestCapacity();
    TestIsEmpty();
    TestGetValueAt();
    TestPop();
    TestInsert();
    TestPrepend();
    TestDelete();
    TestRemove();
    TestFind();
}

void JvectorTest::TestSize() const {

    // instantiation
    common::Jvector tester(3);
    assert(tester.GetSize() == 0);

    int items_to_add = 5 ;
    for (int i = 0; i < items_to_add; ++i) {
        tester.Push(i+1);
    }

    assert(tester.GetSize() == items_to_add);
}

void JvectorTest::TestCapacity() const{
    common::Jvector tester(3);

    // test increasing size
    assert(tester.GetCapacity() == common::kMincapacity);
    for (int i = 0; i < 17; ++i) {
        tester.Push(i+1);
    }


    assert(tester.GetCapacity() == common::kMincapacity * 2);
    for (int i = 0; i < 20; ++i) {
        tester.Push(i+1);
    }

    // test decreasing size
    for (int i = 0; i < 30; i++) {
        tester.Pop();
    }

    assert(tester.GetCapacity() == common::kMincapacity *2);

    for (int i = 0; i < 7; i++) {
        tester.Pop();
    }

    assert(tester.GetCapacity() == common::kMincapacity);
}

void JvectorTest::TestIsEmpty() const {
    common::Jvector tester(3);
    assert(tester.IsEmpty());
}

void JvectorTest::TestGetValueAt() const {
    common::Jvector tester(3);
    tester.Push(4);
    tester.Push(9);
    tester.Push(12);

    assert(tester.GetValueAt(0) == 4);
    assert(tester.GetValueAt(1) == 9);
    assert(tester.GetValueAt(2) == 12);
}

void JvectorTest::TestPop() const{
    common::Jvector tester(3);
    tester.Push(3);

    int popped = tester.Pop();
    assert(popped == 3);
}

void JvectorTest::TestInsert() const{
    common::Jvector tester(3);
    tester.Push(5);
    tester.Push(7);
    tester.Push(9);
    tester.Insert(0, 4);

    assert(tester.GetValueAt(0) == 4);
    assert(tester.GetValueAt(1) == 5);
    assert(tester.GetValueAt(2) == 7);
    assert(tester.GetValueAt(3) == 9);

    tester.Insert(3, 8);

    assert(tester.GetValueAt(3) == 8);
    assert(tester.GetValueAt(4) == 9);
}

void JvectorTest::TestPrepend() const{
    common::Jvector tester(3);
    tester.Push(9);
    tester.Push(8);
    tester.Push(7);
    tester.Prepends(6);

    assert(tester.GetSize() == 4);
    assert(tester.GetValueAt(0) == 6);
    assert(tester.GetValueAt(1) == 9);
    assert(tester.GetValueAt(3) == 7);
}

void JvectorTest::TestDelete() const{
    common::Jvector tester(3);

    tester.Push(5);
    tester.Deletes(0);
    assert(tester.GetSize() == 0);
}

void JvectorTest::TestRemove() const{
    common::Jvector tester(5);
    tester.Push(50);
    tester.Push(2);
    tester.Push(50);
    tester.Remove(50);

    assert(tester.GetValueAt(0) == 2);
}

void JvectorTest::TestFind() const{
    common::Jvector tester(3);

    tester.Push(4);
    tester.Push(7);
    tester.Push(11);

    assert(tester.Find(4) == 0);
    assert(tester.Find(5) == -1);
}


} /* namespace common */
