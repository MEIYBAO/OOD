#include <iostream>
#include <string>

class Circle {
public:
    Circle(int r, std::string c);
    ~Circle();
    void info() const;
    
    static void show_cnt();

private:
    int radius;
    std::string fillcolor;
    
    static const int MAX_CNT;
    static int cnt;
};

const int Circle::MAX_CNT = 10;
int Circle::cnt = 0;

Circle::Circle(int r,  std::string c):radius{r}, fillcolor{c} {
    ++cnt;
}

Circle::~Circle() {
    --cnt;
}

void Circle::info() const {
    std::cout << "circle " << cnt << ": "
              << radius << ", "
              << fillcolor << '\n';
}

void Circle::show_cnt() {
    std::cout << "current cirlces number: " << cnt << "\n";
}

void test() {
    Circle::show_cnt();
    
    Circle c1(5, "red");  c1.info();
    Circle c2(3, "blue");  c2.info();

    Circle::show_cnt();
}

int main() {
    test();
    Circle::show_cnt();
}
