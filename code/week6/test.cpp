// 练习用代码

#include <iostream>
#include <string>

// Circle类
// ...

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