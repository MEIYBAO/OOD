#include <iostream>

using namespace std;

int a,b;

int main()
{
    while(cin>>a>>b){
        for(auto i = a;i <= b;i ++)
            cout<<char(i);
        cout<<endl;
    }
    return 0;
}