/*    ____        __      __   ____________  __       __    __      __    ________     __
     /    \       \  \   /  /  |____  ____|  \  \    /  /  |  |    |  |  |   ____ |   |  |
    /  /\  \       \   \/  /       |  |       \  \  /  /   |  |____|  |  |  |         |  |
   /  /__\  \       \     /        |  |        \  \/  /    |   ____   |  |  |         |  |
  /  _____   \      /  /\  \       |  |         \    /     |  |    |  |  |  |         |__|
 /  /      \  \    /  /   \  \     |  |          |  /      |  |    |  |  |  |          __
/__/        \__\  /__/     \__\    |__|         /__/       |__|    |__|  |__|         |__|

ЗА ЭТО РЕШЕНИЕ ВЫСТАВЛЕН НЕПОЛНЫЙ БАЛЛ!!!
*/

#include "rational.h"

#include <numeric>
#include <exception>
#include <iostream>

void GetRational(char smth_arr[24], int32_t& numerator, int32_t& denominator) {
  numerator = 0;
  denominator = 0;
  bool is_positive = true;
  size_t idx = 0;
  if (smth_arr[idx] == '+') {
    ++idx;
  }
  if (smth_arr[idx] == '-') {
    is_positive = false;
    ++idx;
  }
  while (smth_arr[idx] != '/' && smth_arr[idx] != '\0') {
    numerator *= 10;
    numerator += static_cast<int>(smth_arr[idx]) - 48;
    ++idx;
  }
  if (smth_arr[idx] == '\0') {
    denominator = 1;
    if (!is_positive) {
      numerator *= -1;
    }
    return;
  }
  ++idx;
  if (smth_arr[idx] == '-') {
    is_positive = !is_positive;
    ++idx;
  }
  while (smth_arr[idx] != '\0') {
    denominator *= 10;
    denominator += static_cast<int>(smth_arr[idx]) - 48;
    ++idx;
  }
  if (!is_positive) {
    numerator = std::abs(numerator) * -1;
    denominator = std::abs(denominator);
  }
}

Rational::Rational(const int32_t& number) : Rational(number, 1) {} // NOLINT
Rational::Rational(const int32_t& numerator, const int32_t& denominator) : numerator_(numerator), denominator_(denominator) {
  if (!denominator) {
    throw RationalDivisionByZero();
  }
  Reduce();
}

Rational Rational::Inverted() const {
  if (this->numerator_ == 0) {
    throw RationalDivisionByZero{};
  }
  int32_t a = GetDenominator();
  int32_t b = GetNumerator();
  Rational temp(a, b);
  return temp;
}
void Rational::Reduce() {
  int gcd = std::gcd(std::abs(GetNumerator()), std::abs(GetDenominator()));
  numerator_ = GetNumerator() / gcd;
  denominator_ = GetDenominator() / gcd;
  if (denominator_ < 0) {
    numerator_ *= -1;
    denominator_ *= -1;
  }
}

const int32_t& Rational::GetNumerator() const {
  return numerator_;
}
const int32_t& Rational::GetDenominator() const {
  return denominator_;
}
void Rational::SetNumerator(const int32_t& numerator) {
  numerator_ = numerator;
  Reduce();
}
void Rational::SetDenominator(const int32_t& denominator) {
  if (!denominator) {
    throw RationalDivisionByZero{};
  }
  denominator_ = denominator;
  Reduce();
}

Rational& Rational::operator+=(const Rational& that) {
  SetNumerator(GetNumerator() * that.GetDenominator() + that.GetNumerator() * GetDenominator());
  SetDenominator(GetDenominator() * that.GetDenominator());
  Reduce();
  return *this;
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

Rational Rational::operator-() const {
  Rational copy = *this;
  copy.SetNumerator(-copy.GetNumerator());
  return copy;
}
Rational Rational::operator+() const {
  return *this;
}

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
  if (val.GetDenominator() != 1) {
    os << val.GetNumerator() << '/' << val.GetDenominator();
  } else {
    os << val.GetNumerator();
  }
  return os;
}
std::istream& operator>>(std::istream& is, Rational& val) {
  // is >> val.numerator_ >> val.denominator_;
  char smth_input[24];
  is >> smth_input;
  GetRational(smth_input, val.numerator_, val.denominator_);
  if (val.denominator_ == 0) {
    throw RationalDivisionByZero{};
  }
  val.Reduce();
  return is;
}
