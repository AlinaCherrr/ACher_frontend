#include "rational/rational.hpp"

std::int64_t Rational::evkl(const std::int64_t lhs, const std::int64_t rhs) noexcept {
    std::int64_t mx;
    std::int64_t mn;
    std::int64_t v;
    mx = std::max(std::abs(lhs), std::abs(rhs));
    mn = std::min(std::abs(lhs), std::abs(rhs));
    if (mn == 0) {
        return mx;
    }
    while (mx != mn) {
        mx = mx - mn;
        v = mx;
        mx = std::max(mx, mn);
        mn = std::min(v, mn);
    }
    return mx;
}

Rational::Rational(const std::int64_t num, const std::int64_t den) {
    if (den == 0) {
        throw std::invalid_argument("Zero denominator in Rational ctor\n");
    }
    else {
        std::int64_t nod = evkl(num, den);
        num_ = num / nod;
        den_ = den / nod;
        this->round();
    }
}

Rational& Rational::operator+=(const Rational& rhs) {
    std::int64_t r1;
    std::int64_t r2;
    r1 = num_ * rhs.den_;
    r2 = den_ * rhs.num_;
    r1 += r2;
    r2 = den_ * rhs.den_;
    std::int64_t nod = evkl(r1, r2);
    num_ = r1 / nod;
    den_ = r2 / nod;
    this->round();
    return *this;
}


Rational& Rational::operator-=(const Rational& rhs) {
    std::int64_t r1;
    std::int64_t r2;
    r1 = num_ * rhs.den_;
    r2 = den_ * rhs.num_;
    r1 -= r2;
    r2 = den_ * rhs.den_;
    std::int64_t nod = evkl(r1, r2);
    num_ = r1 / nod;
    den_ = r2 / nod;
    this->round();
    return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    std::int64_t nod = evkl(num_, den_);
    num_ /= nod;
    den_ /= nod;
    this->round();
    return *this;
}


Rational& Rational::operator/=(const Rational& rhs) {
    if (rhs.num_ == 0) {
        throw std::invalid_argument("Zero denominator!");
    }
    else {
        num_ *= rhs.den_;
        den_ *= rhs.num_;
        std::int64_t nod = evkl(num_, den_);
        num_ /= nod;
        den_ /= nod;
        this->round();
        return *this;
    }
}


Rational& Rational::operator-() {
    num_ = -num_;
    return *this;
}

Rational Rational::abs() {
    num_ = std::abs(num_);
    den_ = std::abs(den_);
    return *this;
}

Rational& Rational::round() {
    if (den_ < 0) {
        den_ = -den_;
        num_ = -num_;
    }
    return *this;
}


Rational operator+(const Rational& lhs, const Rational& rhs) {
    Rational rez = lhs;
    rez += rhs;
    return rez;
}

Rational operator+(const Rational& lhs, const std::int64_t rhs) { return operator+(lhs, Rational(rhs)); }
Rational operator+(const std::int64_t lhs, const Rational& rhs) { return operator+(Rational(lhs), rhs); }


Rational operator-(const Rational& lhs, const Rational& rhs) {
    Rational rez = lhs;
    rez -= rhs;
    return rez;
}

Rational operator-(const Rational& lhs, const std::int64_t rhs) { return operator-(lhs, Rational(rhs)); }
Rational operator-(const std::int64_t lhs, const Rational& rhs) { return operator-(Rational(lhs), rhs); }


Rational operator*(const Rational& lhs, const Rational& rhs) {
    Rational rez = lhs;
    rez *= rhs;
    return rez;
}

Rational operator*(const Rational& lhs, const std::int64_t rhs) { return operator*(lhs, Rational(rhs)); }
Rational operator*(const std::int64_t lhs, const Rational& rhs) { return operator*(Rational(lhs), rhs); }


Rational operator/(const Rational& lhs, const Rational& rhs) {
    Rational rez = lhs;
    rez /= rhs;
    return rez;
}
Rational operator/(const Rational& lhs, const std::int64_t rhs) { return operator/(lhs, Rational(rhs)); }
Rational operator/(const std::int64_t lhs, const Rational& rhs) { return operator/(Rational(lhs), rhs); }


bool operator>(const Rational& lhs, const Rational& rhs) {
    std::int64_t a = lhs.num() * rhs.den();
    std::int64_t b = rhs.num() * lhs.den();
    if (a > b) {
        return 1;
    }
    else {
        return 0;
    }
}

bool operator>(const Rational& lhs, const std::int64_t rhs) { return operator>(lhs, Rational(rhs)); }
bool operator>(const std::int64_t lhs, const Rational& rhs) { return operator>(Rational(lhs), rhs); }


bool operator<(const Rational& lhs, const Rational& rhs) {
    std::int64_t a = lhs.num() * rhs.den();
    std::int64_t b = rhs.num() * lhs.den();
    if (a < b) {
        return 1;
    }
    else {
        return 0;
    }
}

bool operator<(const Rational& lhs, const std::int64_t rhs) { return operator<(lhs, Rational(rhs)); }
bool operator<(const std::int64_t lhs, const Rational& rhs) { return operator<(Rational(lhs), rhs); }


bool operator<=(const Rational& lhs, const Rational& rhs) {
    std::int64_t a = lhs.num() * rhs.den();
    std::int64_t b = rhs.num() * lhs.den();
    if (a <= b) {
        return 1;
    }
    else {
        return 0;
    }
}

bool operator<=(const Rational& lhs, const std::int64_t rhs) { return operator<=(lhs, Rational(rhs)); }
bool operator<=(const std::int64_t lhs, const Rational& rhs) { return operator<=(Rational(lhs), rhs); }


bool operator>=(const Rational& lhs, const Rational& rhs) {
    std::int64_t a = lhs.num() * rhs.den();
    std::int64_t b = rhs.num() * lhs.den();
    if (a >= b) {
        return 1;
    }
    else {
        return 0;
    }
}

bool operator>=(const Rational& lhs, const std::int64_t rhs) { return operator>=(lhs, Rational(rhs)); }
bool operator>=(const std::int64_t lhs, const Rational& rhs) { return operator>=(Rational(lhs), rhs); }


//bool operator==(const Rational& lhs, const Rational& rhs) {
//    std::int64_t a = lhs.num() * rhs.den();
//    std::int64_t b = rhs.num() * lhs.den();
//    if (a == b) {
//        return 1;
//    }
//    else {
//        return 0;
//    }
//}
//
//bool operator==(const Rational& lhs, const std::int64_t rhs) { return operator==(lhs, Rational(rhs)); }
//bool operator==(const std::int64_t lhs, const Rational& rhs) { return operator==(Rational(lhs), rhs); }
//
//
//bool operator!=(const Rational& lhs, const Rational& rhs) { return !operator==(lhs, rhs); }
//bool operator!=(const Rational& lhs, const std::int64_t rhs) { return !operator==(lhs, Rational(rhs)); }
//bool operator!=(const std::int64_t lhs, const Rational& rhs) { return !operator==(Rational(lhs), rhs); }

bool Rational::operator==(const Rational& rhs) const noexcept
{
    std::int64_t a = num_ * rhs.den();
    std::int64_t b = rhs.num() * den_;
    return a == b;
}

bool operator==(const std::int64_t lhs, const Rational& rhs) {
    Rational lhs_r = Rational(lhs);
    std::int64_t a = lhs_r.num() * rhs.den();
    std::int64_t b = rhs.num() * lhs_r.den();
    return a == b;
}

bool operator!=(const std::int64_t lhs, const Rational& rhs) { return !operator==(lhs, rhs); }


std::ostream& Rational::writeTo(std::ostream& ostrm) const
{
    ostrm << num_ << sl << den_;
    return ostrm;
}


std::istream& Rational::readFrom(std::istream& istrm)
{
    int num(0);
    char sl(0);
    int den(1);
    istrm >> num;
    istrm.get(sl);
    int trash = istrm.peek();
    istrm >> den;
    if (!istrm || trash > '9' || trash < '0') {
        istrm.setstate(std::ios_base::failbit);
        return istrm;
    }
    if (istrm.good() || istrm.eof()) {
        if (Rational::sl == sl && den > 0) {
            *this = Rational(num, den);
        }
        else {
            istrm.setstate(std::ios_base::failbit);
        }
    }
    return istrm;
}