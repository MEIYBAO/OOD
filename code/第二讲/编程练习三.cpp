#include <bits/stdc++.h>

using namespace std;

vector<string> s{"red","yellow","blue","white","black"},result(3);

set<vector<string>> res;
vector<vector<string> > res1;

int vit[6] = {0};

void print1()
{
    int ans = 0;
    cout<<"There are "<<res1.size()<<" options to take balls out.\n";
    cout<<endl;
    for(auto x : res1)
    {
        cout<<setw(8)<<++ans;
        for(auto i : x)
        {
            cout<<setw(8)<<i;
        }
        cout<<endl;
    }
    res1.clear();
}


void print2()
{
    int ans = 0;
    cout<<"There are "<<res.size()<<" options to take balls out.\n";
    cout<<endl;
    for(auto x : res)
    {
        cout<<setw(8)<<++ans;
        for(auto i : x)
        {
            cout<<setw(8)<<i;
        }
        cout<<endl;
    }
    res.clear();
}

void solve1(int k)
{   
    if(k >= 3)
    {
        res1.push_back(result);
        k = 0;
        return;
    }

    for(int i = 0;i < 5;i++)
    {
        if(!vit[i])
        {
            vit[i] = 1;
            result[k] = s[i];
            solve1(k+1);
            vit[i] = 0;
        }
    }
}

void solve2(int k)
{
    if(k >= 3)
    {
        vector<string> tmp = result;
        sort(tmp.begin(), tmp.end());
        res.insert(tmp);
        return;
    }

    for(int i = 0;i < 5;i++)
    {
        if(!vit[i])
        {
            vit[i] = 1;
            result[k] = s[i];
            solve2(k+1);
            vit[i] = 0;
        }
    }
}

int main()
{
    solve1(0);
    print1();
    cout<<"-----------------------------\n";
    solve2(0);
    print2();
    return 0;
}