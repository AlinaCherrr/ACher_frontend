#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <queuelstt/queuelstt.hpp>
#include "unittest.hpp"
#include <cstdint>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("queuelstt", T, queuelstt) {

    QueueLstT<T> q;
    CHECK_EQ(1, q.IsEmpty());

    std::vector<T> data;
    FillData(4, data);

    T c1 = data[0];
    T c2 = data[1];
    T c3 = data[2];
    T c4 = data[3];

    q.Push(c1);
    CHECK_EQ(c1, q.Top());
    CHECK_EQ(0, q.IsEmpty());
    q.Push(c2);
    CHECK_EQ(c1, q.Top());
    q.Push(c3);
    CHECK_EQ(c1, q.Top());

    QueueLstT<T> q_copy(q);
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


TEST_CASE_TEMPLATE_INVOKE(queuelstt, TYPES);
