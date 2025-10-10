#include <iostream>
#include <string>
#include <utility>

using namespace std;

void test() {
    string s1;
    string s2{"nice"};
    string s3{s2};

    cout << "s1 = " << s1 << endl;
    cout << "s2 = " << s2 << endl;
    cout << "s3 = " << s3 << endl;
    string s4{move(s2)};
    cout << "s2 = " << s2 << endl;
    cout << "s4 = " << s4 << endl;
}

int main() {
    test();
}
