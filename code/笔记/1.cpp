#include <iostream>
using namespace std;

void fun(int *x,int *y)
{
    int * z = x;
    x = y;
    y = z;
    cout<<*x<<" "<<*y<<endl;
}

int main() {
    int x = 5,y = 10;
    fun(&x,&y);
    cout<<x<<" "<<y<<endl;
    //输出结果为“5 10”
    return 0;
}


