#include <iostream>
using namespace std;

int main() {
    // float x = 2.0;
    // string y = "x";
    // add(x,y); // 实参是double类型
    int x = 4;
    int &&r = move(x);
    cout<<r<<" "<<x<<endl;
    return 0;
}


