#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <queuelst/queuelst.hpp>

TEST_CASE("queuelst ctor") {
    QueueLst q;
    CHECK_EQ(1, q.IsEmpty());

    Complex c1{ 1, 1 };
    Complex c2{ 1, 2 };
    Complex c3{ 1, 3 };
    Complex c4{ 1, 4 };

    q.Push(c1);
    CHECK_EQ(c1, q.Top());
    CHECK_EQ(0, q.IsEmpty());
    q.Push(c2);
    CHECK_EQ(c1, q.Top());
    q.Push(c3);
    CHECK_EQ(c1, q.Top());

    QueueLst q_copy(q);
    CHECK_EQ(0, q_copy.IsEmpty());
    CHECK_EQ(c1, q_copy.Top());

    q_copy.Clear();
    CHECK_EQ(1, q_copy.IsEmpty());
    CHECK_THROWS(c1, q_copy.Top());

    q.Pop();
    CHECK_EQ(c2, q.Top());
    q.Pop();
    CHECK_EQ(c3, q.Top());
    q.Pop();
    CHECK_THROWS(q.Top());
    CHECK_EQ(1, q.IsEmpty());
    q.Pop();
    CHECK_THROWS(q.Top());
    CHECK_EQ(1, q.IsEmpty());

    q_copy.Push(c3);
    q_copy.Push(c3);
    q_copy.Push(c3);

    q = q_copy;
    CHECK_EQ(0, q.IsEmpty());
    CHECK_EQ(c3, q.Top());

    q_copy.Clear();
    q_copy.Push(c1);
    q_copy.Push(c2);
    q_copy.Push(c1);
    q_copy.Push(c2);
    q_copy.Push(c1);

    q_copy = q;
    CHECK_EQ(0, q.IsEmpty());
    CHECK_EQ(c3, q_copy.Top());

    q_copy.Clear();
    q = q_copy;
    CHECK_EQ(1, q.IsEmpty());

}

