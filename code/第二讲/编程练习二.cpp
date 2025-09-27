#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

vector<int> a{0,1,2,3,4,5,6,7,8,9};

template<typename T>
void print(const T& value) {
    cout << setw(4) << value;
}

int main()
{
    for(const auto i : a){
        for(int j : a)
            {
                if(i == 0 && j == 0) print("");
                else
                {
                    auto result = i*j;
                    if(result == 0)  print(((i==0) ? j : i));
                    else print(result);
                }
            }
        cout<<endl;
    }
    return 0;
}