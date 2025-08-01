#ifndef COMPLEX_HPP
#define COMPLEX_HPP

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <iosfwd>
#include <stdexcept>
#include <limits>

struct Complex {
	Complex() = default;
	~Complex() = default;
	explicit Complex(const double real) : re(real) { }
	Complex(const double real, const double imaginary) : re(real), im(imaginary) {}
	Complex(const Complex&) = default;
	Complex(Complex&&) = default;
	Complex& operator=(const Complex&) = default;
	Complex& operator=(Complex&&) = default;
	[[nodiscard]] Complex operator-() const noexcept;
	
	[[nodiscard]] std::ostream& WriteTo(std::ostream& ostrm) const noexcept;
	[[nodiscard]] std::istream& ReadFrom(std::istream& istrm) noexcept;

	Complex& operator+=(const Complex& rhs) noexcept;
	Complex& operator+=(const double rhs) noexcept { return operator+=(Complex(rhs)); }

	Complex& operator-=(const Complex& rhs) noexcept;
	Complex& operator-=(const double rhs) noexcept { return operator-=(Complex(rhs)); }

	Complex& operator*=(const Complex& rhs) noexcept;
	Complex& operator*=(const double rhs) noexcept { return operator*=(Complex(rhs)); }

	Complex& operator/=(const Complex& rhs);
	Complex& operator/=(const double rhs) { return operator/=(Complex(rhs)); }

	[[nodiscard]] bool operator==(const Complex& rhs) const noexcept;
	[[nodiscard]] bool operator==(const double rhs) const noexcept { return operator==(Complex(rhs)); }

	[[nodiscard]] bool operator!=(const Complex& rhs) const noexcept { return !operator==(rhs); };
	[[nodiscard]] bool operator!=(const double rhs) const noexcept { return !operator==(Complex(rhs)); };

	double re{ 0.0 };
	double im{ 0.0 };

	static const char leftBrace{ '{' };
	static const char rightBrace{ '}' };
	static const char separator{ ',' };
};


//bool operator==(const Complex& lhs, const Complex& rhs);
//inline bool operator==(const Complex& lhs, const double rhs) { return operator==(lhs, Complex(rhs)); }
//
//inline bool operator!=(const Complex& lhs, const Complex& rhs) { return !operator==(lhs, rhs); }
//inline bool operator!=(const Complex& lhs, const double rhs) { return !operator==(lhs, Complex(rhs)); }

[[nodiscard]] bool operator==(const double lhs, const Complex& rhs) noexcept;
inline [[nodiscard]] bool operator!=(const double lhs, const Complex& rhs) noexcept { return !operator==(lhs, rhs); }



[[nodiscard]] Complex operator+ (const Complex& lhs, const Complex& rhs) noexcept;
inline [[nodiscard]] Complex operator+ (const Complex& lhs, const double& rhs) noexcept { return operator+(lhs, Complex(rhs)); };
inline [[nodiscard]] Complex operator+ (const double& lhs, const Complex& rhs) noexcept { return operator+(Complex(lhs), rhs); };

[[nodiscard]] Complex operator- (const Complex& lhs, const Complex& rhs) noexcept;
inline [[nodiscard]] Complex operator- (const Complex& lhs, const double& rhs) noexcept { return operator-(lhs, Complex(rhs)); };
inline [[nodiscard]] Complex operator- (const double& lhs, const Complex& rhs) noexcept { return operator-(Complex(lhs), rhs); };

[[nodiscard]] Complex operator* (const Complex& lhs, const Complex& rhs) noexcept;
inline [[nodiscard]] Complex operator* (const Complex& lhs, const double& rhs) noexcept { return operator*(lhs, Complex(rhs)); };
inline [[nodiscard]] Complex operator* (const double& lhs, const Complex& rhs) noexcept { return operator*(Complex(lhs), rhs); };

[[nodiscard]] Complex operator/ (const Complex& lhs, const Complex& rhs);
inline [[nodiscard]] Complex operator/ (const Complex& lhs, const double& rhs) { return operator/(lhs, Complex(rhs)); };
inline [[nodiscard]] Complex operator/ (const double& lhs, const Complex& rhs) { return operator/(Complex(lhs), rhs); };

[[nodiscard]] Complex operator! (const Complex& rhs) noexcept;
//[[nodiscard]] double& abs(const Complex& lhs) noexcept;

inline std::ostream& operator<<(std::ostream& ostrm, const Complex& rhs) noexcept {
	return rhs.WriteTo(ostrm);
}
inline std::istream& operator>>(std::istream& istrm, Complex& rhs) noexcept {
	return rhs.ReadFrom(istrm);
}

#endif