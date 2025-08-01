#include <complex/complex.hpp>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }


Complex& Complex::operator+=(const Complex& rhs) noexcept {
	re += rhs.re;
	im += rhs.im;
	return *this;
}


Complex& Complex::operator-=(const Complex& rhs) noexcept {
	re -= rhs.re;
	im -= rhs.im;
	return *this;
}


Complex& Complex::operator*=(const Complex& rhs) noexcept {
	double re1 = re, im1 = im;
	re = re * rhs.re - im * rhs.im;
	im = re1 * rhs.im + rhs.re * im1;
	return *this;
}


Complex& Complex::operator/=(const Complex& rhs) {
	if (rhs.re == 0 && rhs.im == 0) {
		throw std::invalid_argument("Division by zero!");
	}
	else {
		double re1 = re, im1 = im;
		re = (re * rhs.re + im * rhs.im) / (rhs.im * rhs.im + rhs.re * rhs.re);
		im = (-re1 * rhs.im + rhs.re * im1) / (rhs.im * rhs.im + rhs.re * rhs.re);
		return *this;
	}
}

//bool operator==(const Complex& lhs, const Complex& rhs) {
//	double constexpr eps = 2 * std::numeric_limits<double>::epsilon();
//	return (std::abs(lhs.re - rhs.re) < eps && std::abs(lhs.im - rhs.im) < eps);
//}

bool Complex::operator==(const Complex& rhs) const noexcept {
	double constexpr eps = 2 * std::numeric_limits<double>::epsilon();
	return (std::abs(re - rhs.re) < eps && std::abs(im - rhs.im) < eps);
}

bool operator==(const double lhs, const Complex& rhs) noexcept {
	Complex lhs_c = Complex(lhs);
	double constexpr eps = 2 * std::numeric_limits<double>::epsilon();
	return (std::abs(lhs_c.re - rhs.re) < eps && std::abs(lhs_c.im - rhs.im) < eps);
}


//double& abs(const Complex& lhs) noexcept {
//	double res;
//	res = std::sqrt(lhs.re * lhs.re + lhs.im * lhs.im);
//	return res;
//}


Complex operator!(const Complex& rhs) noexcept {
	Complex sopr;
	sopr.re = rhs.re;
	sopr.im = -rhs.im;
	return sopr;
}


Complex operator+(const Complex& lhs, const Complex& rhs) noexcept {
	Complex sum(lhs);
	sum += rhs;
	return sum;
}

Complex operator-(const Complex& lhs, const Complex& rhs) noexcept {
	Complex dif(lhs);
	dif -= rhs;
	return dif;
}

Complex operator*(const Complex& lhs, const Complex& rhs) noexcept {
	Complex prod(lhs);
	prod *= rhs;
	return prod;
}

Complex operator/(const Complex& lhs, const Complex& rhs) {
	if (rhs.re == 0 && rhs.im == 0) {
		throw std::invalid_argument("Division by zero!");
	}
	Complex quot(lhs);
	quot /= rhs;
	return quot;
}

std::ostream& Complex::WriteTo(std::ostream& ostrm) const noexcept
{
	ostrm << leftBrace << re << separator << im << rightBrace;
	return ostrm;
}

std::istream& Complex::ReadFrom(std::istream& istrm) noexcept
{
	char leftBrace(0);
	double real(0.0);
	char comma(0); 
	double imaginary(0.0);
	char rightBrace(0);
	istrm >> leftBrace >> real >> comma >> imaginary >> rightBrace;
	if (istrm.good())
	{
		if ((Complex::leftBrace == leftBrace) && (Complex::separator == comma) && (Complex::rightBrace == rightBrace))
		{
			re = real;
			im = imaginary;
		}
		else
		{
			istrm.setstate(std::ios_base::failbit);
		}
	}
	return istrm;
}
