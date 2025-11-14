#include <iostream>

class X {
public:
    void func1() { std::cout << "do something 1\n";}
    void func2() { std::cout << "do something 2\n";}

private:
    int data;

protected:
    int data2;

};

class Y : public X {
public:
    void func1(){ data2 = 3;std::cout<<data2<<std::endl;}
    void func3() {std::cout<<"do something new\n";}

};

void test1() {
    Y obj;
    obj.func1();
    obj.func2();
    obj.func3();
}

int main() {
    test1();
}