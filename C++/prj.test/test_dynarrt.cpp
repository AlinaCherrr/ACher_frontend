#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <dynarrt/dynarrt.hpp>


#include "unittest.hpp"
#include <cstdint>

#define TYPES int, double, std::string

TEST_CASE_TEMPLATE_DEFINE("dynarrt", T, dynarrt) {
    std::vector<T> data;
    FillData(9, data);

    T a1 = data[0];
    T a2 = data[1];
    T a3 = data[2];
    T a4 = data[3];
    T a5 = data[4];
    T a6 = data[5];

    DynArrT<T> d1;
    CHECK_EQ(0, d1.Size());

    DynArrT<T> d2(4);
    CHECK_EQ(4, d2.Size());


    d2[0] = a1;
    d2[1] = a2;
    d2[2] = a3;
    d2[3] = a4;
    CHECK_EQ(a1, d2[0]);
    CHECK_EQ(a2, d2[1]);
    CHECK_EQ(a3, d2[2]);
    CHECK_EQ(a4, d2[3]);

    DynArrT<T> d3(d2);
    CHECK_EQ(4, d3.Size());
    CHECK_EQ(a1, d3[0]);
    CHECK_EQ(a2, d3[1]);
    CHECK_EQ(a3, d3[2]);
    CHECK_EQ(a4, d3[3]);
    d3[0] = a5;
    CHECK_EQ(a5, d3[0]);
    CHECK_EQ(a1, d2[0]);
    d3[0] = a1;

    d3.Resize(8);
    d3[5] = a6;
    CHECK_EQ(8, d3.Size());
    CHECK_EQ(a1, d3[0]);
    CHECK_EQ(a2, d3[1]);
    CHECK_EQ(a3, d3[2]);
    CHECK_EQ(a4, d3[3]);
    CHECK_EQ(a6, d3[5]);
    CHECK_THROWS(d3[8]);

    d3.Resize(4);
    CHECK_EQ(4, d3.Size());
    CHECK_EQ(a1, d3[0]);
    CHECK_EQ(a2, d3[1]);
    CHECK_EQ(a3, d3[2]);
    CHECK_EQ(a4, d3[3]);
    CHECK_THROWS(d3[4]);

    d3.Resize(6);
    CHECK_EQ(6, d3.Size());
    CHECK_EQ(a1, d3[0]);
    CHECK_EQ(a2, d3[1]);
    CHECK_EQ(a3, d3[2]);
    CHECK_EQ(a4, d3[3]);;
    CHECK_THROWS(d3[6]);

    d1 = d3;
    CHECK_EQ(6, d1.Size());
    CHECK_EQ(a1, d1[0]);
    CHECK_EQ(a2, d1[1]);
    CHECK_EQ(a3, d1[2]);
    CHECK_EQ(a4, d1[3]);


    d1 = d2;
    CHECK_EQ(4, d1.Size());
    CHECK_EQ(a1, d1[0]);
    CHECK_EQ(a2, d1[1]);
    CHECK_EQ(a3, d1[2]);
    CHECK_EQ(a4, d1[3]);

    CHECK_THROWS(DynArrT<T>(-5));
    CHECK_THROWS(d1.Resize(-2));
    CHECK_THROWS(DynArrT<T>(0));
    CHECK_THROWS(d1.Resize(0));
    CHECK_THROWS(d1[-10]);
    CHECK_THROWS(d1[80]);
}

TEST_CASE_TEMPLATE_INVOKE(dynarrt, TYPES);