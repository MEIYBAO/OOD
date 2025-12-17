#include <iostream>

template <typename T>
class Complex {
private:
    T real;
    T imag;
public:
    Complex(T r = 0, T i = 0);
    Complex(const Complex& other) : real(other.real), imag(other.imag) {}

    T get_real() const { return real; }
    T get_imag() const { return imag; }

    Complex operator+(const Complex& other) const;

    Complex& operator+=(const Complex& other);

    bool operator==(const Complex& other) const;

    template <typename U>
    friend std::ostream& operator<< (std::ostream& os, const Complex<U>& c);

    template <typename U>
    friend std::istream& operator>> (std::istream& is, Complex<U>& c);
};

template <typename T>
Complex<T>::Complex(T r, T i) : real(r), imag(i) {}

template <typename T>
Complex<T> Complex<T>::operator+(const Complex& other) const {
    return Complex(real + other.real, imag + other.imag);
}   

template <typename T>
Complex<T>& Complex<T>::operator+=(const Complex& other) {
    real += other.real;
    imag += other.imag;
    return *this;
}

template <typename T>
bool Complex<T>::operator==(const Complex& other) const {
    return (real == other.real) && (imag == other.imag);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Complex<T>& c) {
    if (c.imag < 0) {
        os << c.real << " - " << -c.imag << "i";
    } else {
        os << c.real << " + " << c.imag << "i";
    }
    return os;
}

template <typename T>
std::istream& operator>>(std::istream& is, Complex<T>& c) {
    is >> c.real  >> c.imag ;
    return is;
}


