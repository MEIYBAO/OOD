// 备用代码1

#include <iostream>

// 类Complex声明
class Complex {
public:
    Complex(double real_ = 0, double imag_ = 0);
    Complex& operator += (const Complex &c);

    // 友元函数声明
    friend Complex operator + (const Complex &c1, const Complex &c2);
    friend std::ostream& operator << (std::ostream &out, const Complex &c);
    friend std::istream& operator >> (std::istream &in, Complex &c);
    
private:
    double real, imag;
};

// 成员函数实现
Complex::Complex(double real_, double imag_): real{real_}, imag{imag_} {
}

Complex&  Complex::operator += (const Complex &c) {
    real += c.real;
    imag += c.imag;

    return *this;
}

// 友元函数实现
Complex operator + (const Complex &c1, const Complex &c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

std::ostream& operator << (std::ostream &out, const Complex &c) {
    if(c.imag >= 0)
        out << c.real << " + " << c.imag << "i";
    else
        out << c.real << " - " << -c.imag << "i";
    return out;
}

std::istream& operator >> (std::istream &in, Complex &c)
{
    in >> c.real >> c.imag;
    return in;
}

// void test1() {
//     Complex c1(3, 4), c2(1, 1), c3;
//     c3 = c1 + c2;
//     c1+=c2;
//     // std::cout << "c1 = "; output(c1); std::cout << std::endl;
//     std::cout << "c3 = "; std::cout<<c3; std::cout << std::endl;
// }


void test2() {
    Complex c1;
    std::cin >> c1;
    std::cout << c1 << std::endl;
}
int main() {
    test2();
}