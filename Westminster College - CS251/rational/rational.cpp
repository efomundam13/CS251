#include "rational.h"

#include <algorithm>

Rational::Rational() : numerator(0), denominator(1) {}

Rational::Rational(int numerator, int denominator) : numerator(numerator), denominator(denominator) {
  simplify();
}

Rational Rational::operator+(const Rational& other) const {
  return Rational(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
}

Rational Rational::operator*(const Rational& other) const {
  return Rational(numerator * other.numerator, denominator * other.denominator);
}

bool Rational::operator<(const Rational& other) const {
  return numerator * other.denominator < other.numerator * denominator;
}

std::string Rational::read() const {
  return std::to_string(numerator) + "/" + std::to_string(denominator);
}

void Rational::write(int numerator, int denominator) {
  this->numerator = numerator;
  this->denominator = denominator;
  simplify();
}

Rational Rational::reciprocal() const {
  return Rational(denominator, numerator);
}

void Rational::simplify() {
  int gcd = std::gcd(numerator, denominator);
  numerator /= gcd;
  denominator /= gcd;
}

int main() {
  Rational a(1, 2);
  Rational b(3, 4);

  std::cout << a + b << std::endl; // 7/8
  std::cout << a * b << std::endl; // 3/8
  std::cout << a < b << std::endl; // true

  a.write(4, 5);
  std::cout << a.read() << std::endl; // 4/5

  std::cout << a.reciprocal().read() << std::endl; // 5/4

  return 0;
}

