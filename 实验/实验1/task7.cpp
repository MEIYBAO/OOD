#include <bits/stdc++.h>
using namespace std;

string op[] = {"+","-", "*", "/"};

int main()
{
    srand(time(0));
    int n = 10,sum = 0;
    while(n--)
    {
        int opration = rand() % 4;
        switch(opration)
        {
            case 0:
            {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                cout << a << " + " << b << " = ";
                int res = a+b,c;
                cin>>c;
                sum += (c == res) ? 1 : 0;
                break;
            }
            case 1:
            {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                while(b > a) b = rand() % 10 + 1;
                cout << a << " - " << b << " = ";
                int res = a-b,c;
                cin>>c;
                sum += (c == res) ? 1 : 0;
                break;
            }
            case 2:
            {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                cout << a << " * " << b << " = " ;
                int res = a*b,c;
                cin>>c;
                sum += (c == res) ? 1 : 0;
                break;
            }
            case 3:
            {
                int a = rand() % 10 + 1;
                int b = rand() % 10 + 1;
                while(a % b != 0) b = rand() % 10 + 1;
                cout << a << " / " << b << " = " ;
                int res = a/b,c;
                cin>>c;
                sum += (c == res) ? 1 : 0;
                break;
            }
        }
    }

    double percent = sum/10.0 * 100;
    cout << "×¼È·ÂÊ£º" << fixed << setprecision(2) << percent << "%" << endl;
    return 0;
}