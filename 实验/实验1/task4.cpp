#include <iostream>
#include <string>
#include <algorithm>

bool is_palindrome(const std::string &s);
bool is_palindrome_ignore_case(const std::string &s);

int main() {
   using namespace std;
    string s;

    // 多组输入，直到按下Ctrl+Z结束测试
    while(cin >> s) {
        cout << boolalpha 
             << "区分大小写: " << is_palindrome(s) << "\n"
             << "不区分大小写: " << is_palindrome_ignore_case(s) << "\n\n";
    }     
}


// 函数is_palindrome定义
bool is_palindrome(const std::string &s)
{
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin());
}


// 函数is_palindrome_ignore_case定义
bool is_palindrome_ignore_case(const std::string &s)
{
    return std::equal(s.begin(), s.begin() + s.size()/2, s.rbegin(),
                      [](char a, char b){
                          return std::tolower(a) == std::tolower(b);
                      });
}