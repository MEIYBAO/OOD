#include <iostream>
#include <string>
#include <algorithm>

std::string dec2n(int x, int n = 2);

int main() {
    int x;
    while(std::cin >> x) {
        std::cout << "十进制: " << x << '\n'
                  << "二进制: " << dec2n(x) << '\n'
                  << "八进制: " << dec2n(x, 8) << '\n'
                  << "十二进制: " << dec2n(x, 12) << '\n'
                  << "十六进制: " << dec2n(x, 16) << '\n'
                  << "三十二进制: " << dec2n(x, 32) << "\n\n"; 
    }
}

// 函数dec2n定义
std::string dec2n(int x, int n)
{
    if (x == 0) {
        return "0";
    }

    std::string result;

    while (x > 0) {
        int t = x % n;
        result += (t>=10) ? ('A' + (t - 10)) : ('0' + t);
        x /= n;
    }

    std::reverse(result.begin(), result.end());
    return result;
}