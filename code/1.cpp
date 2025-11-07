#include <bits/stdc++.h>
using namespace std;

class A
{
    private:
        int a,b;
    public:
        static int count;
        A(int a,int b) : a(a),b(b)
        {
            cout<<"A\n";
            count++;
        }
};

class B
{
    private:
        A x;
        int a,b;
    public:
        B(A x,int c,int d) : x(x),a(c),b(d){
            cout<<"B\n";
        }
};

int A::count = 0;

int main()
{
    A x(1,2);
    B y(x,3,4);
    cout<<A::count<<endl;
}