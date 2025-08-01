#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <rational/rational.hpp>

TEST_CASE("rational ctor") {
    Rational r_def;
    CHECK(0 == r_def.num());
    CHECK(1 == r_def.den());

    Rational r_int(3);
    CHECK(3 == r_int.num());
    CHECK(1 == r_int.den());

    Rational two_int(3, 5);
    CHECK(3 == two_int.num());
    CHECK(5 == two_int.den());

    Rational sokrat(4, 8);
    CHECK(1 == sokrat.num());
    CHECK(2 == sokrat.den());

    Rational r1 = { 4,8 };
    Rational r2 = { 5,7 };
    Rational r3;
    int i = 10;

    r3 = r1;
    CHECK(r1.num() == r3.num());
    CHECK(r1.den() == r3.den());
    CHECK(1 == r3.num());
    CHECK(2 == r3.den());

    r1 += r2;
    CHECK(17 == r1.num());
    CHECK(14 == r1.den());

    r1 -= r2;
    CHECK(1 == r1.num());
    CHECK(2 == r1.den());

    r1 += i;
    CHECK(21 == r1.num());
    CHECK(2 == r1.den());

    r1 -= i;
    CHECK(1 == r1.num());
    CHECK(2 == r1.den());

    r1 *= r2;
    CHECK(5 == r1.num());
    CHECK(14 == r1.den());

    r1 /= r2;
    CHECK(1 == r1.num());
    CHECK(2 == r1.den());

    r1 *= i;
    CHECK(5 == r1.num());
    CHECK(1 == r1.den());

    r1 /= i;
    CHECK(1 == r1.num());
    CHECK(2 == r1.den());

    Rational r11;

    r11 = r1 + r2;;
    CHECK(17 == r11.num());
    CHECK(14 == r11.den());

    r11 = { 0,1 };
    r11 = r2 - r1;
    CHECK(3 == r11.num());
    CHECK(14 == r11.den());

    r11 = { 0,1 };
    r11 = r1 + i;
    CHECK(21 == r11.num());
    CHECK(2 == r11.den());

    r11 = { 0,1 };
    r11 = i + r1;
    CHECK(21 == r11.num());
    CHECK(2 == r11.den());

    r11 = { -65,7 };
    r11 = r2 - i;
    CHECK(-65 == r11.num());
    CHECK(7 == r11.den());

    r11 = { 0,1 };
    r11 = i - r2;
    CHECK(65 == r11.num());
    CHECK(7 == r11.den());

    r11 = { 0,1 };
    r11 = r2 * r1;
    CHECK(5 == r11.num());
    CHECK(14 == r11.den());

    r11 = { 0,1 };
    r11 = r1 * i;
    CHECK(5 == r11.num());
    CHECK(1 == r11.den());

    r11 = { 0,1 };
    r11 = i * r1;
    CHECK(5 == r11.num());
    CHECK(1 == r11.den());

    r11 = { 0,1 };
    r11 = r1 / r2;
    CHECK(7 == r11.num());
    CHECK(10 == r11.den());

    r11 = { 0,1 };
    r11 = r1 / i;
    CHECK(1 == r11.num());
    CHECK(20 == r11.den());

    r11 = { 0,1 };
    r11 = i / r1;
    CHECK(20 == r11.num());
    CHECK(1 == r11.den());

    Rational rabs;
    Rational ro = { -7,9 };
    rabs = ro.abs();
    CHECK(7 == rabs.num());
    CHECK(9 == rabs.den());

    CHECK(false == (r1 > r2));
    CHECK(true == (r1 < r2));
    CHECK(false == (r1 >= r2));
    CHECK(true == (r1 <= r2));
    CHECK(false == (r1 == r2));
    CHECK(true == (r1 != r2));

    CHECK(false == (r1 > i));
    CHECK(true == (r1 < i));
    CHECK(false == (r1 >= i));
    CHECK(true == (r1 <= i));
    CHECK(false == (r1 == i));
    CHECK(true == (r1 != i));

    CHECK(true == (i > r1));
    CHECK(false == (i < r1));
    CHECK(true == (i >= r1));
    CHECK(false == (i <= r1));
    CHECK(false == (i == r1));
    CHECK(true == (i != r1));

    Rational um = -r1;
    CHECK(-1 == um.num());
    CHECK(2 == um.den());

    Rational otr1(3, -2);
    Rational otr2(-5, 2);
    Rational otr3(-2, -3);
    CHECK(-3 == otr1.num());
    CHECK(2 == otr1.den());
    CHECK(-5 == otr2.num());
    CHECK(2 == otr2.den());
    CHECK(2 == otr3.num());
    CHECK(3 == otr3.den());
    CHECK(true == (otr1 > otr2));

    Rational r0(0);
    CHECK_THROWS(void(Rational(1, 0)));
    CHECK_THROWS(r1 / r0);
    CHECK_THROWS(r1 / 0);
  

    SUBCASE("Correct inputs") {

        Rational r;
        std::stringstream sstrm;

        SUBCASE("Simple") {
            sstrm.str("2/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(2, 3));
        }
    
        sstrm.clear();

        SUBCASE("Input with reducing") {
            sstrm.str("36/48");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(3, 4));
        }

        sstrm.clear();

        SUBCASE("Negative input") {
            sstrm.str("-8/7");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-8, 7));
        }

        SUBCASE("Extra spaces on begin") {
            sstrm.str(" 1/3");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(1, 3));
        }

        sstrm.clear();

        SUBCASE("Extra extra spaces on begin") {
            sstrm.str("   -3/4");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::eofbit);
            CHECK(r == Rational(-3, 4));
        }

        sstrm.clear();

        SUBCASE("Extra spaces on both ends") {
            sstrm.str(" 5/9  ");
            sstrm >> r;
            CHECK(sstrm.rdstate() == std::ios_base::goodbit);
            CHECK(r == Rational(5, 9));
        }
        sstrm.clear();
    }
}


