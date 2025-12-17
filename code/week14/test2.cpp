// ±¸ÓÃ´úÂë2

#include <iostream>
#include <string>

void test1() {
    using namespace std;

    string s1;
    cout << "Enter s1:  \n";
    while(getline(cin >> ws, s1))
        cout << s1 << endl;
    
    cin.clear();

    string s2;
    cout << "Enter s2: \n";
    cin >> s2;
    cout << s2;
}

void test2() {
    using namespace std;

    int n;
    cin >> n;
    cout << "n = " << n << '\n';
    
    string cmd;
    getline(cin, cmd);
    cout << "cmd = " << cmd << '\n';
}

int main() {
    test1();
}