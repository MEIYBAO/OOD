#include "Fraction.h"
#include <bits/stdc++.h>

const std::string Fraction::doc = "Fraction类 v 0.01版. \n目前仅支持分数对象的构造、输出、加/减/乘/除运算.";

Fraction::Fraction(int u, int d) : up(u), down(d) {
}

Fraction::Fraction(const Fraction& f) : up(f.up), down(f.down) {}

int Fraction::get_up() const {
    return up;
}

int Fraction::get_down() const {
    return down;
}

Fraction Fraction::negative() const {
    return Fraction(-up, down);
}

void output(const Fraction& f) {
	
	int up = f.get_up(),down = f.get_down();
	

	if(down == 0) {
        cout << "分母不能为0!";
    }else
    {

		if (down < 0)
		{
			up = -up;
			down = -down;
		}
	
		int x = __gcd(abs(up), abs(down));
		up /= x;
		down /= x;
	    
	    if(up == 0) cout<<"0";
	    else if(down == 1) cout<<up; 
	    else cout << up << "/" << down;
	}
	
		
}

Fraction add(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.get_up() * f2.get_down() + f2.get_up() * f1.get_down(),
                    f1.get_down() * f2.get_down());
}

Fraction sub(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.get_up() * f2.get_down() - f2.get_up() * f1.get_down(),
                    f1.get_down() * f2.get_down());
}

Fraction mul(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.get_up() * f2.get_up(), f1.get_down() * f2.get_down());
}

Fraction div(const Fraction& f1, const Fraction& f2) {
    return Fraction(f1.get_up() * f2.get_down(), f1.get_down() * f2.get_up());
}

Fraction::~Fraction() {}
