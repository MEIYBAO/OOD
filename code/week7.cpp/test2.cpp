#include <iostream>
#include <vector>
#include <string>

void output1(const std::vector<std::string> &v) {
    for(std::string &s: v)  
        std::cout << s << ' ';
    std::cout << '\n';
}

void output2(const std::vector<std::string> &v) {
    for(auto &s: v)
        std::cout << s << " ";
    std::cout << '\n';
}

void test() {
    std::vector<std::string> x{"OOP", "C++", "Java", "C#", "Go", "Rust", "Python"};
    output1(x);
    output2(x);
}

int main() {
    test();
}