#include <iostream>
#include <string>

const int N = 5;

template<typename T> 

// ´ı²¹×ã
// Ä£°åº¯Êıbubble_sortÉùÃ÷
void bubble_sort(T x[],const int n,bool flag = true)
{
    for(int i = 1; i < n;i ++ )
    {
        for(int j = 0;j < i;j++)
        {
            if((x[i] > x[j]) ^ flag)
            {
                std::swap(x[i],x[j]);
            }
        }
    }
}

template<typename T>   
// ´ı²¹×ã
// Ä£°åº¯ÊıoutputÉùÃ÷
void output(const T x[],const int n)
{
    if(!n) return;
    for(int i = 0;i < n;i++)
        std::cout<<x[i]<<" ";
    std::cout<<std::endl;
}



// ²âÊÔ´úÂë
int main() {
    using namespace std;

    cout << "²âÊÔ1: " << endl;
    int x1[N] = {1, 9, 0, 5, 2};
    bubble_sort(x1, N);
    output(x1, N);

    cout << "\n²âÊÔ2: " << endl;
    string x2[N] = {"nice", "good", "yep", "uh", "hi"};
    bubble_sort(x2, N, false);
    output(x2, N);
}