// 备用代码1
// -fno-elide-constructors
// explicit

#include <iostream>

using namespace std;

// 定义类T
class T {
public:
    T();
    T(int x);
    T(const T &obj);
    T(T &&obj) noexcept;
    ~T() = default;

    void show() const;

private:
    int data;
};

T::T():data{0} {
    cout << "default constructor called.\n";
}

T::T(int x): data{x} {
    cout << "general constructor called.\n";
}

T::T(const T &obj): data{obj.data} {
    cout << "copy constructor called.\n";
}

T::T(T &&obj) noexcept: data{obj.data} {
    cout << "move constructor calle.\n";
}

inline void T::show() const {
    cout << data << endl;
}

// T类对象作为函数参数
void func1(T t) {
    t.show();
}

// T类对象作为函数返回值
T func2() {
    return T(999);
}

// 测试代码
void test1() {
    T t1(42);
    T t2{t1};
    T t3 = t1;

    func1(t1);
}

void test2() {
    func2().show();
}

int main() {
    test2();
}