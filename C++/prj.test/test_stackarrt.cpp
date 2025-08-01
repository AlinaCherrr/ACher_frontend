#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <stackarrt/stackarrt.hpp>
#include "unittest.hpp"
#include <cstdint>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("stackarrt", T, stackarrt)
{
    std::vector<T> data;
    FillData(4, data);

    StackArrT<T> s1;
    CHECK_EQ(1, s1.IsEmpty());

    T c1 = data[0];
    T c2 = data[1];
    T c3 = data[2];
    T c4 = data[3];

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

    StackArrT<T> s2;
    s2.Push(c4);
    s2.Push(c3);

    s1 = s2;
    CHECK_EQ(c3, s1.Top());
    s2.Clear();

    StackArrT<T> s1_copy(s1);
    CHECK_EQ(c3, s1_copy.Top());

    CHECK_THROWS(s2.Top());


    
}

TEST_CASE_TEMPLATE_INVOKE(stackarrt, TYPES);