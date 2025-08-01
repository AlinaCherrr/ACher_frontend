#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"
#include <bitset/bitset.hpp>

TEST_CASE("bitset") {
    BitSet a;
    CHECK_EQ(0, a.Size());

    BitSet b(8);
    CHECK_EQ(8, b.Size());
    CHECK_EQ(0, b.Get(0));
    CHECK_EQ(0, b.Get(7));

    b.Set(4, 1);
    CHECK_EQ(1, b.Get(4));

    a = b;
    CHECK_EQ(8, a.Size());
    CHECK_EQ(1, a.Get(4));
    CHECK_EQ(0, a.Get(0));
    CHECK_EQ(0, a.Get(6));

   
    b.Fill(1);
    CHECK_EQ(1, b.Get(0));
    CHECK_EQ(1, b.Get(7));
    CHECK_EQ(1, b.Get(4));

    BitSet c(b);
    CHECK_EQ(8, c.Size());
    CHECK_EQ(1, c.Get(7));
    
    c.Set(3, 0);
    CHECK_EQ(0, c.Get(3));

    c.Resize(4);
    CHECK_EQ(4, c.Size());
    CHECK_EQ(0, c.Get(3));

    CHECK_EQ(0, c==a);
    CHECK_EQ(1, c != a);
    CHECK_EQ(0, b == a);

    a.Fill(1);
    CHECK_EQ(1, b == a);

    a.Resize(2);
    b = ~c;
    CHECK_EQ(1, b.Get(3));
    CHECK_EQ(0, b.Get(2));

    c = a | b;
    CHECK_EQ(4, c.Size());
    CHECK_EQ(0, c.Get(0));
    CHECK_EQ(0, c.Get(1));
    CHECK_EQ(1, c.Get(2));
    CHECK_EQ(1, c.Get(3));

    c = a & b;
    CHECK_EQ(4, c.Size());
    CHECK_EQ(0, c.Get(0));
    CHECK_EQ(0, c.Get(1));
    CHECK_EQ(0, c.Get(2));
    CHECK_EQ(1, c.Get(3));

    c = a ^ b;
    CHECK_EQ(4, c.Size());
    CHECK_EQ(0, c.Get(0));
    CHECK_EQ(0, c.Get(1));
    CHECK_EQ(1, c.Get(2));
    CHECK_EQ(0, c.Get(3));


}
//#include <iostream>
//#include "bitset/bitset.hpp"
//
//int main() {
//    std::int32_t a = 0;
//    std::cin >> a;
//    BitSet temp(a);
//    temp.Fill(1);
//    std::cout << temp << std::endl;
//    BitSet temp2;
//    try
//    {
//        std::cin >> temp2;
//        std::cout << temp2 << std::endl;
//    }
//    catch (const std::exception& e)
//    {
//        std::cerr << e.what();
//    }
//    
//    
//
//}
