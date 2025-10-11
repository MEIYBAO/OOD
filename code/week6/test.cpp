// 练习用代码

#include <iostream>
#include <string>

// Circle类
// ...
class Circle {
public:
    Circle(int r, const std::string &c) : radius(r), color(c) {
        ++cnt;
        std::cout << "Circle constructed: radius=" << radius << " color=" << color << "\n";
    }
    ~Circle() {
        --cnt;
        std::cout << "Circle destructed: radius=" << radius << " color=" << color << "\n";
    }

    void info() const {
        std::cout << "Circle info -> radius: " << radius << ", color: " << color << "\n";
    }

    static void show_cnt() {
        std::cout << "Current Circle count: " << cnt << "\n";
    }

private:
    int radius;
    std::string color;
    static int cnt;
};

// 静态成员定义
int Circle::cnt = 0;

void test() {
    Circle::show_cnt();
    
    Circle c1(5, "red");  c1.info();
    Circle c2(3, "blue"); c2.info();

    Circle::show_cnt();
    
}

int main() {
    test();
    Circle::show_cnt();
}