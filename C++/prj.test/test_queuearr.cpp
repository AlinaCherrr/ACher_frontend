#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <queuearr/queuearr.hpp>

TEST_CASE("queuearr ctor") {
    Complex c1(1, 0);
    Complex c2(2, 0);
    Complex c3(3, 0);
    Complex c4(4, 0);
    QueueArr q1;
    CHECK_EQ(q1.IsEmpty(), 1);
    CHECK_THROWS(q1.Top());
    q1.Pop();

    q1.Push(c1);
    CHECK_EQ(q1.Top(), c1);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c1);
    CHECK_EQ(q1.Top(), c1);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c2);
    CHECK_EQ(q1.Top(), c1);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c3);
    CHECK_EQ(q1.Top(), c1);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Push(c4);
    CHECK_EQ(q1.Top(), c1);
    CHECK_EQ(q1.IsEmpty(), 0);

    QueueArr q11 = q1;
    QueueArr q12(q1);

    q1.Pop();
    CHECK_EQ(q1.Top(), c1);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c2);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c3);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.Top(), c4);
    CHECK_EQ(q1.IsEmpty(), 0);

    q1.Pop();
    CHECK_EQ(q1.IsEmpty(), 1);


    q11.Pop();
    CHECK_EQ(q11.Top(), c1);
    CHECK_EQ(q11.IsEmpty(), 0);

    q11.Pop();
    CHECK_EQ(q11.Top(), c2);
    CHECK_EQ(q11.IsEmpty(), 0);

    q11.Pop();
    CHECK_EQ(q11.Top(), c3);
    CHECK_EQ(q11.IsEmpty(), 0);

    q11.Pop();
    CHECK_EQ(q11.Top(), c4);
    CHECK_EQ(q11.IsEmpty(), 0);

    q11.Pop();
    CHECK_EQ(q11.IsEmpty(), 1);

    q12.Pop();
    CHECK_EQ(q12.Top(), c1);
    CHECK_EQ(q12.IsEmpty(), 0);

    q12.Pop();
    CHECK_EQ(q12.Top(), c2);
    CHECK_EQ(q12.IsEmpty(), 0);

    q12.Pop();
    CHECK_EQ(q12.Top(), c3);
    CHECK_EQ(q12.IsEmpty(), 0);

    q12.Pop();
    CHECK_EQ(q12.Top(), c4);
    CHECK_EQ(q12.IsEmpty(), 0);

    q12.Pop();
    CHECK_EQ(q12.IsEmpty(), 1);

    q12.Push(c1);
    q12.Push(c2);
    q12.Push(c3);
    CHECK_EQ(q12.Top(), c1);
    CHECK_EQ(q12.IsEmpty(), 0);

    q12.Clear();
    CHECK_EQ(q12.IsEmpty(), 1);
}