#include <iostream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    string a;
    for(int  i = 0;i < 26;++i) {
        a += ('a' + i);
    }

    for(int i = 0;i <= 26;++i) {
        if(i == 0) cout<<setw(2)<<" ";
        else cout<<setw(2)<<right<<i;
        string t;
        if(i > 0){
            for(auto x : a) 
                t+=toupper(x);
        }
        else t = a;
        rotate(t.begin(), t.begin()+i, t.end());
        for(auto x : t) 
            cout<<setw(2)<<right<<x;
        cout<<endl;
    }

    return 0;
}