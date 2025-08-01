#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include "unittest.hpp"
#include <queuearrt/queuearrt.hpp>
#include <cstdint>
#include <string>
#include <vector>

#define TYPES int,double, std::string
int con = 0;

TEST_CASE_TEMPLATE_DEFINE("queuearrt", T, queuearrt) {

    std::vector<T> data;
    FillData(4, data);
    T c1 = data[0];
    T c2 = data[1];
    T c3 = data[2];
    T c4 = data[3];

    QueueArrT<T> q1;
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

    QueueArrT<T> q11 = q1;
    QueueArrT<T> q12(q1);

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

TEST_CASE_TEMPLATE_INVOKE(queuearrt, TYPES);