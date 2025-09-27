#include <iostream>

using namespace std;

// 定义类X
// 待补足/修改
class X {
public:
// 成员函数
    X();
    X(int a_, int b_, int c_);
    X(const X &t);

    ~X();

    void set(int a_, int b_, int c_);
    int sum() const;
    int product() const;
private:
// 成员数据
    int a, b, c;
};

X::X(int a_, int b_, int c_):a{a_},b{b_},c{c_}
{
    cout<<"1\n";        
};

X::X()
{
    cout<<"hrere\n";
};

X::X(const X &t):a{t.a},b{t.b},c{t.c}
{
    cout<<"copy\n";
}

X::~X()
{
    cout<<"destroy\n";
}

void X::set(int a_, int b_, int c_) { a = a_; b = b_; c = c_; }
int X::sum() const { return a+b+c; }
int X::product() const { return a*b*c; }

// void test1() {
//     X x1;
//     x1.set(1, 2, 5);
//     cout << x1.sum() << endl;
//     cout << x1.product() << endl;
// }


// void test2() {
//     X x2{1, 2, 3};
//     cout << x2.sum() << endl;
// }



void test3() {
    X x1;
    X x2{1, 2, 3};
    X x3{x2};
    cout<<x3.sum()<<endl;
}


/*
void test4() {
    X x1;
    x1.set(10, 20, 30);
    cout << x1.sum() << endl;

    X x2{1, 2, 3};
    cout << x2.sum() << endl;

    X x3{x2};
    cout << x3.sum() << endl;
}
*/

int main() {
    test3();
}