#include <iostream>
#include <string>
using namespace std;


class Complex
{
private:
    double real;
    double imag; 
public:
	static const string doc;
    Complex (double r = 0.0, double i = 0.0);
    Complex (const Complex &c);
    double get_real() const;
    double get_imag() const;
    void add (const Complex &c);
    friend double output (const Complex &c);
    friend double abs (const Complex &c);
    friend bool is_equal (const Complex &c1, const Complex &c2);
    friend Complex add (const Complex &c1, const Complex &c2);
    friend bool is_not_equal (const Complex &c1, const Complex &c2);
    ~Complex();
};


