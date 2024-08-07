#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>
#include <algorithm>

class Rational {
public:
  Rational() : numerator(0), denominator(1) {}
  Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
    simplify();
  }

  Rational operator+(const Rational& other) const {
    return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
  }

  Rational operator*(const Rational& other) const {
    return Rational(numerator * other.numerator, denominator * other.denominator);
  }

  bool operator<(const Rational& other) const {
    return numerator * other.denominator < other.numerator * denominator;
  }

  std::string read() const {
    return std::to_string(numerator) + "/" + std::to_string(denominator);
  }

  void write(int numerator, int denominator) {
    this->numerator = numerator;
    this->denominator = denominator;
    simplify();
  }

  Rational reciprocal() const {
    return Rational(denominator, numerator);
  }

  void simplify() {
    int gcd = std::gcd(numerator, denominator);
    numerator /= gcd;
    denominator /= gcd;
  }

private:
  int numerator;
  int denominator;
};

#endif