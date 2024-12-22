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
 public:
  Rational(const int& number = 0);  // NOLINT
  Rational(const int& numerator, const int& denominator);
  const int& GetNumerator() const;
  const int& GetDenominator() const;
  void SetNumerator(const int& numerator);
  void SetDenominator(const int& denominator);

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

 private:
  void Reduce();
  int numerator_;
  int denominator_;
};
#endif  // RATIONAL_H