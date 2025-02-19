#include "rational.h"
#include <numeric>
#include <exception>

Rational::Rational(const int& number) : Rational(number, 1) {
}

Rational::Rational(const int& numerator, const int& denominator) : numerator_(numerator), denominator_(denominator) {
  Reduce();
}

const int& Rational::GetNumerator() const {
  return numerator_;
}

const int& Rational::GetDenominator() const {
  return denominator_;
}

void Rational::SetNumerator(const int& numerator) {
  numerator_ = numerator;
  Reduce();
}

void Rational::SetDenominator(const int& denominator) {
  if (!denominator) {
    throw RationalDivisionByZero{};
  }
  denominator_ = denominator;
  Reduce();
}

Rational& Rational::operator-=(const Rational& that) {
  SetNumerator(GetNumerator() * that.GetDenominator() - that.GetNumerator() * GetDenominator());
  SetDenominator(GetDenominator() * that.GetDenominator());
  Reduce();
  return *this;
}

Rational& Rational::operator/=(const Rational& that) {
  return *this *= that.Inverted();
}

Rational& Rational::operator*=(const Rational& that) {
  SetNumerator(GetNumerator() * that.GetNumerator());
  SetDenominator(GetDenominator() * that.GetDenominator());
  Reduce();
  return *this;
}

Rational& Rational::operator++() {
  SetNumerator(GetNumerator() + GetDenominator());  // GD()
  Reduce();
  return *this;
}

Rational Rational::operator++(int) {
  Rational temp = *this;
  ++(*this);
  return temp;
}

Rational Rational::Inverted() const {
  // intODO: comment
  if (*this == 0) {
    throw RationalDivisionByZero{};
  }
  return Rational(GetDenominator(), GetNumerator()); // NOLINT
}

Rational& Rational::operator+=(const Rational& that) {
  // *this += that
  /*
  a/b + c/d = (ad + bc) / bd
  */
  SetNumerator(GetNumerator() * that.GetDenominator() + that.GetNumerator() * GetDenominator());
  SetDenominator(GetDenominator() * that.GetDenominator());
  Reduce();
  return *this;
}

void Rational::Reduce() {
  if (GetNumerator() * GetDenominator() < 0) {
    numerator_ = -std::abs(GetNumerator());
    denominator_ = std::abs(GetDenominator());
  }
  int gcd = std::gcd(std::abs(GetNumerator()), GetDenominator());
  numerator_ = GetNumerator() / gcd;
  denominator_ = GetDenominator() / gcd;
}

Rational Rational::operator-() const {
  Rational copy = *this;
  copy.SetNumerator(-copy.GetNumerator());
  return copy;
}

Rational Rational::operator+() const {
  return *this;
}

// friends

Rational operator+(const Rational& lhs, const Rational& rhs) {
  Rational res = lhs;
  res += rhs;
  return res;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
  Rational result = lhs;
  result -= rhs;
  return result;
}

Rational operator/(const Rational& lhs, const Rational& rhs) {
  Rational result = lhs;
  result /= rhs;
  return result;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
  Rational result = lhs;
  result *= rhs;
  return result;
}

bool operator<(const Rational& lhs, const Rational& rhs) {
  return lhs.GetNumerator() * rhs.GetDenominator() < rhs.GetNumerator() * lhs.GetDenominator();
}

bool operator>(const Rational& lhs, const Rational& rhs) {
  return rhs < lhs;
}

bool operator<=(const Rational& lhs, const Rational& rhs) {
  return !(rhs < lhs);
}

bool operator>=(const Rational& lhs, const Rational& rhs) {
  return !(lhs < rhs);
}

bool operator==(const Rational& lhs, const Rational& rhs) {
  return !(lhs != rhs);
}

bool operator!=(const Rational& lhs, const Rational& rhs) {
  return lhs < rhs || lhs > rhs;
}

std::ostream& operator<<(std::ostream& os, const Rational& val) {
  os << val.GetNumerator() << '/' << val.GetDenominator();
  return os;
}

std::istream& operator>>(std::istream& is, Rational& val) {
  is >> val.numerator_ >> val.denominator_;
  return is;
}

Rational& Rational::operator--() {
  SetNumerator(GetNumerator() - GetDenominator());  // GD()
  Reduce();
  return *this;
}

Rational Rational::operator--(int) {
  Rational temp = *this;
  --(*this);
  return temp;
}

