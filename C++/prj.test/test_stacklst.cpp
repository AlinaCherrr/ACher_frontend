#include <stacklst/stacklst.hpp>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

TEST_CASE("stacklst ctor") {
    StackLst s1;
    StackLst s3;
    StackLst s4;
    CHECK_EQ(1, s1.IsEmpty());

    Complex c1{ 1, 1 };
    Complex c2{ 1, 2 };
    Complex c3{ 1, 3 };
    Complex c4{ 1, 4 };

    s1.Push(c1);
    CHECK_EQ(0, s1.IsEmpty());
    CHECK_EQ(c1, s1.Top());

    s1.Push(c2);
    s1.Push(c3);
    s1.Push(c4);
    CHECK_EQ(c4, s1.Top());

    s1.Pop();
    CHECK_EQ(c3, s1.Top());

    s1.Pop();
    CHECK_EQ(c2, s1.Top());

    s1.Clear();
    CHECK_EQ(1, s1.IsEmpty());

    s1.Pop();
    CHECK_EQ(1, s1.IsEmpty());

    s1.Push(c2);
    CHECK_EQ(0, s1.IsEmpty());
    CHECK_EQ(c2, s1.Top());

    StackLst s2;
    s2.Push(c4);
    s2.Push(c3);

    s1 = s2;
    CHECK_EQ(c3, s1.Top());

    StackLst s2_copy(s2);
    CHECK_EQ(c3, s2_copy.Top());

    s2.Clear();
    CHECK_THROWS(s2.Top());

    s3.Push(c3);
    s3.Push(c3);
    s3.Push(c3);

    s4 = s3;
    CHECK_EQ(0, s4.IsEmpty());
    CHECK_EQ(c3, s4.Top());

    s3.Clear();
    s3.Push(c1);
    s3.Push(c2);
    s3.Push(c1);
    s3.Push(c2);
    s3.Push(c1);

    s3 = s4;
    CHECK_EQ(0, s4.IsEmpty());
    CHECK_EQ(c3, s3.Top());

    s3.Clear();
    s4 = s3;
    CHECK_EQ(1, s4.IsEmpty());

}
