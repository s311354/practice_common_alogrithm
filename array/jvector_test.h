#ifndef JVECTOR_TEST_H
#define JVECTOR_TEST_H

namespace common {

class JvectorTest
{
private:
    

public:
    JvectorTest();
    virtual ~JvectorTest();

    void RunTests() const;
    void TestSize() const;
    void TestCapacity() const;
    void TestIsEmpty() const;
    void TestGetValueAt() const;
    void TestPop() const;
    void TestInsert() const;
    void TestPrepend() const;
    void TestDelete() const;
    void TestRemove() const;
    void TestFind() const;
};

} /* namespace common */

#endif /* JVECTOR_TEST_H */
