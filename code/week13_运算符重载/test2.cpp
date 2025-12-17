// 备用代码2

#include <iostream>
#include <iomanip>

class Clock{
    static constexpr int HOURS_PER_DAY = 24;
public:
    Clock(int h = 0, int m = 0, int s = 0);

    Clock& operator ++();  // 加1秒, 形如++t
    Clock operator ++(int notuse);   // 加1秒，形如t++
    
    // 友元声明
    friend void output(const Clock &t);

private:
    int hour, minute, second;
};

// 成员函数实现
Clock::Clock(int h, int m, int s): hour{h}, minute{m}, second{s} {
}

// 加1秒, 形如++t
Clock& Clock::operator++() {
    second++;
    minute += second/60;
    second %= 60;

    hour += minute/60;
    minute %= 60;

    hour %= HOURS_PER_DAY;

    return *this;
}
 // 加1秒，形如t++
Clock Clock::operator++(int notuse) {
    Clock t = *this;
    ++t;
    return t;
}

// 友元函数实现
void output(const Clock &t) {
    std::cout << std::setfill('0')
              << std::setw(2) << t.hour << ":"
              << std::setw(2) << t.minute << ":"
              << std::setw(2) << t.second
              << std::setfill(' ');
}

void test1() {
    Clock t(23, 59, 59);
    
    std::cout << "t = "; output(t); std::cout << std::endl;
    std::cout << "++++t = "; output(++++t); std::cout << std::endl;
    std::cout << "t = "; output(t); std::cout << std::endl;
}

void test2() {
    Clock t(23, 59, 59);
    
    std::cout << "t = "; output(t); std::cout << std::endl;
    std::cout << "t++ = "; output(t++); std::cout << std::endl;
    std::cout << "t = "; output(t); std::cout << std::endl;
}

int main() {
    std::cout << "测试1: ++t\n";
    test1();

    std::cout << "\n测试2: t++\n";
    test2();
}