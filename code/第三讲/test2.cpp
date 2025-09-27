#include <iostream>
#include <string>

using namespace std;

void test1() {
    string s{"0123456789abcdef"};
    cout << s << endl;
    cout << s.replace(1, 3, "###") << endl;
    cout << s.replace(1, 5, 3, '*') << endl;
}

void test2() {
    string s{"0123456789abcdef"};
    cout << s << endl;

    s.insert(3, "$");
    cout << s << endl;

    s.insert(s.end()-1, 3, '#');
    cout << s << endl;
}

int main() {
    cout << "²âÊÔ1: " << endl;
    test1();

    cout << "²âÊÔ2: " << endl;
    test2();
}
