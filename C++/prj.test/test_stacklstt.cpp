#include <stacklstt/stacklstt.hpp>

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "unittest.hpp"
#include <cstdint>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("stacklstt", T, stacklstt) {
    
    std::vector<T> data;
    FillData(4, data);
    T c1 = data[0];
    T c2 = data[1];
    T c3 = data[2];
    T c4 = data[3];
    
    StackLstT<T> s1;
    StackLstT<T> s3;
    StackLstT<T> s4;
    CHECK_EQ(1, s1.IsEmpty());

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

    StackLstT<T> s2;
    s2.Push(c4);
    s2.Push(c3);

    s1 = s2;
    CHECK_EQ(c3, s1.Top());

    StackLstT<T> s2_copy(s2);
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


TEST_CASE_TEMPLATE_INVOKE(stacklstt, TYPES);
