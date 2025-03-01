/*    ____        __      __   ____________  __       __    __      __    ________     __
     /    \       \  \   /  /  |____  ____|  \  \    /  /  |  |    |  |  |   ____ |   |  |
    /  /\  \       \   \/  /       |  |       \  \  /  /   |  |____|  |  |  |         |  |
   /  /__\  \       \     /        |  |        \  \/  /    |   ____   |  |  |         |  |
  /  _____   \      /  /\  \       |  |         \    /     |  |    |  |  |  |         |__|
 /  /      \  \    /  /   \  \     |  |          |  /      |  |    |  |  |  |          __
/__/        \__\  /__/     \__\    |__|         /__/       |__|    |__|  |__|         |__|

ЗА ЭТО РЕШЕНИЕ ВЫСТАВЛЕН НЕПОЛНЫЙ БАЛЛ!!!
*/

#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <stdexcept>

class RationalDivisionByZero : public std::runtime_error {
public:
 RationalDivisionByZero() : std::runtime_error("RationalDivisionByZero") {
 }
};

class Rational {
 private:
  void Reduce();
  int32_t numerator_;
  int32_t denominator_;
 public:
  Rational(const int32_t& number = 0);  // NOLINT
  Rational(const int32_t& numerator, const int32_t& denominator);
  const int32_t& GetNumerator() const;
  const int32_t& GetDenominator() const;
  void SetNumerator(const int32_t& numerator);
  void SetDenominator(const int32_t& denominator);

  Rational& operator+=(const Rational& that);
  Rational& operator-=(const Rational& that);
  Rational& operator/=(const Rational& that);
  Rational& operator*=(const Rational& that);

  Rational& operator++();
  Rational operator++(int);
  Rational& operator--();
  Rational operator--(int);

  Rational Inverted() const;

  friend Rational operator+(const Rational& lhs, const Rational& rhs);
  friend Rational operator-(const Rational& lhs, const Rational& rhs);
  friend Rational operator/(const Rational& lhs, const Rational& rhs);
  friend Rational operator*(const Rational& lhs, const Rational& rhs);

  Rational operator-() const;
  Rational operator+() const;

  friend bool operator<(const Rational& lhs, const Rational& rhs);
  friend bool operator>(const Rational& lhs, const Rational& rhs);
  friend bool operator<=(const Rational& lhs, const Rational& rhs);
  friend bool operator>=(const Rational& lhs, const Rational& rhs);
  friend bool operator==(const Rational& lhs, const Rational& rhs);
  friend bool operator!=(const Rational& lhs, const Rational& rhs);

  friend std::ostream& operator<<(std::ostream& os, const Rational& val);
  friend std::istream& operator>>(std::istream& is, Rational& val);
};

#endif  // RATIONAL_H
