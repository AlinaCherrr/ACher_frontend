#pragma once
#ifndef BITSET_HPP
#define BITSET_HPP

#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iosfwd>
#include <iostream>


class BitSet {
public:
    class BiA;
public:
    BitSet() = default;
    BitSet(const BitSet& rhs);
    BitSet(BitSet&& rhs) noexcept;
    explicit BitSet(const std::int32_t size) : size_(size), bits_(size) {}
    BitSet& operator=(const BitSet& rhs);
    BitSet& operator=(BitSet&& rhs) noexcept;
    ~BitSet() = default;

    [[nodiscard]] bool operator==(const BitSet& rhs) const noexcept;
    [[nodiscard]] bool operator!=(const BitSet& rhs) const noexcept;
    std::int32_t Size() const noexcept { return size_; }
    void Resize(const std::int32_t size);
    [[nodiscard]] bool Get(const int32_t idx) const;
    void Set(const int32_t idx, const bool val);
    void Fill(const bool val) noexcept;

    BiA operator[](const int32_t idx) { return { *this, idx }; }

    std::ostream& WriteTxt(std::ostream& ostrm) const;
    //std::ostream& WriteBinary(std::ostream&);
    std::istream& ReadTxt(std::istream& istrm);
    //std::istream& ReadBinary(std::istream&);

    [[nodiscard]] BitSet operator~();
    [[nodiscard]] BitSet& operator|=(const BitSet& rhs);
    [[nodiscard]] BitSet& operator&=(const BitSet& rhs);
    [[nodiscard]] BitSet& operator^=(const BitSet& rhs);
    std::vector<uint32_t> SameSize(const BitSet& lhs, const BitSet& rhs);

public:
    class BiA {
    public:
        BiA() = default;
        BiA(const std::int32_t i, BitSet& b) : i_(i), b_{ b } {}
        BiA(BitSet& b, const std::int32_t i) : b_{ b }, i_(i) {}
        BiA(const BiA&) = default;
        BiA(BiA&&) noexcept = default;
        ~BiA() = default;

        
        bool operator=(const bool v) { b_.Set(i_, v); return *this; }
        BiA& operator=(const BiA& bia);
        BiA& operator=(BiA&&) noexcept = default;

        const bool operator= (const bool v) const { b_.Set(i_, v); return *this; }
        const BiA& operator= (const BiA& bia) const;

        bool operator==(const BiA& bia);
        bool operator==(const bool value);
        bool operator!=(const BiA& bia);
        bool operator!=(const bool value);
        [[nodiscard]] operator bool() const { return b_.Get(i_); }

    private:
        BitSet& b_;
        std::int32_t i_;
    };

private:
    std::int32_t size_ = 0;
    std::vector<std::uint32_t> bits_;

    
};

inline std::ostream& operator<<(std::ostream& ostrm, const BitSet& rhs) {
    return rhs.WriteTxt(ostrm);
 }

inline std::istream& operator>>(std::istream& istrm, BitSet& rhs) {
    return rhs.ReadTxt(istrm);
}

[[nodiscard]] BitSet operator&(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator|(const BitSet& lhs, const BitSet& rhs);

[[nodiscard]] BitSet operator^(const BitSet& lhs, const BitSet& rhs);

#endif