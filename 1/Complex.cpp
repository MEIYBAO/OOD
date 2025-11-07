#include "Complex.h"
#include <cmath>

const string Complex::doc = " a simplified complex class";

Complex::Complex(double r, double i) : real(r), imag(i) {}

Complex::Complex(const Complex &c) : real(c.real), imag(c.imag) {}

double Complex::get_real() const {
    return real;
}
double Complex::get_imag() const {
    return imag;
}
void Complex::add(const Complex &c) {
    real += c.real;
    imag += c.imag;
}
double output(const Complex &c) {
    if (c.imag >= 0)
        std::cout << c.real << " + " << c.imag << "i";
    else
        std::cout << c.real << " - " << -c.imag << "i";
    return 0.0;
}
double abs(const Complex &c) {
    return std::sqrt(c.real * c.real + c.imag * c.imag);
}
bool is_equal(const Complex &c1, const Complex &c2) {
    return (c1.real == c2.real) && (c1.imag == c2.imag);
}
Complex add(const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}
bool is_not_equal(const Complex &c1, const Complex &c2) {
    return !is_equal(c1, c2);
}
Complex::~Complex() {}
