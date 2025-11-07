#include <iostream>
#include <string>
using namespace std;

class Fraction
{
private:
    int up,down;
public:
	static const std::string doc;
	    
    Fraction(int u = 0, int d = 1);
    Fraction(const Fraction& f);

    int get_up() const;
    int get_down() const;
    Fraction negative() const;

    friend void output(const Fraction& f);
    friend Fraction add(const Fraction& f1, const Fraction& f2);
    friend Fraction sub(const Fraction& f1, const Fraction& f2);
    friend Fraction mul(const Fraction& f1, const Fraction& f2);
    friend Fraction div(const Fraction& f1, const Fraction& f2);

    ~Fraction();
};


