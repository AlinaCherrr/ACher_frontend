#pragma once
#ifndef RATIONAL_HPP
#define RATIONAL_HPP

#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <stdexcept>
#include <string>
#include <cstdint>
#include <iosfwd>

class Rational {
public:
    Rational() = default;
    ~Rational() = default;
    Rational(std::int64_t num, std::int64_t den);
    explicit Rational(std::int64_t num) { num_ = num; den_ = 1; };
    Rational(const Rational&) = default;
    Rational(Rational&&) = default;

    Rational& operator=(const Rational&) = default;
    Rational& operator=(Rational&&) = default;

    Rational& operator+=(const Rational& rhs);
    Rational& operator+=(const std::int64_t rhs) { return operator+=(Rational(rhs)); };

    Rational& operator-=(const Rational& rhs);
    Rational& operator-=(const std::int64_t rhs) { return operator-=(Rational(rhs)); };

    Rational& operator*=(const Rational& rhs);
    Rational& operator*=(const std::int64_t rhs) { return operator*=(Rational(rhs)); };

    Rational& operator/=(const Rational& rhs);
    Rational& operator/=(const std::int64_t rhs) { return operator/=(Rational(rhs)); };

    bool operator==(const Rational& rhs) const noexcept;
    bool operator==(const std::int64_t rhs) const noexcept { return operator==(Rational(rhs)); }
    bool operator!=(const Rational& rhs) const noexcept { return !operator==(rhs); }
    bool operator!=(const std::int64_t rhs) const noexcept { return operator!=(Rational(rhs)); }

    Rational& operator-();
    std::int64_t num() const { return num_; };
    std::int64_t den() const { return den_; };
    Rational abs();
    Rational& round();

    std::ostream& writeTo(std::ostream& ostrm) const;
    std::istream& readFrom(std::istream& istrm);

    std::int64_t evkl(const std::int64_t lhs, const std::int64_t rhs) noexcept;
    std::int64_t evkl(const Rational& rhs) noexcept { return evkl(rhs.num_, rhs.den_); }

    static const char sl{ '/' };


private:
    std::int64_t num_ = 0;
    std::int64_t den_ = 1;

};

Rational operator+(const Rational& lhs, const Rational& rhs);
Rational operator+(const Rational& lhs, const std::int64_t rhs);
Rational operator+(const std::int64_t lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);
Rational operator-(const Rational& lhs, const std::int64_t rhs);
Rational operator-(const std::int64_t lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);
Rational operator*(const Rational& lhs, const std::int64_t rhs);
Rational operator*(const std::int64_t lhs, const Rational& rhs);

Rational operator/(const Rational& lhs, const Rational& rhs);
Rational operator/(const Rational& lhs, const std::int64_t rhs);
Rational operator/(const std::int64_t lhs, const Rational& rhs);

bool operator>(const Rational& lhs, const Rational& rhs);
bool operator>(const Rational& lhs, const std::int64_t rhs);
bool operator>(const std::int64_t lhs, const Rational& rhs);

bool operator<(const Rational& lhs, const Rational& rhs);
bool operator<(const Rational& lhs, const std::int64_t rhs);
bool operator<(const std::int64_t lhs, const Rational& rhs);

bool operator<=(const Rational& lhs, const Rational& rhs);
bool operator<=(const Rational& lhs, const std::int64_t rhs);
bool operator<=(const std::int64_t lhs, const Rational& rhs);

bool operator>=(const Rational& lhs, const Rational& rhs);
bool operator>=(const Rational& lhs, const std::int64_t rhs);
bool operator>=(const std::int64_t lhs, const Rational& rhs);

//bool operator==(const Rational& lhs, const Rational& rhs);
//bool operator==(const Rational& lhs, const std::int64_t rhs);
bool operator==(const std::int64_t lhs, const Rational& rhs);

//bool operator!=(const Rational& lhs, const Rational& rhs);
//bool operator!=(const Rational& lhs, const std::int64_t rhs);
bool operator!=(const std::int64_t lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs)
{
    return rhs.writeTo(ostrm);
}

inline std::istream& operator>>(std::istream& istrm, Rational& rhs)
{
    return rhs.readFrom(istrm);
}

#endif