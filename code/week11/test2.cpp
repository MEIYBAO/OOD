#include <iostream>
#include <vector>
#include<algorithm>

template<typename T>
void output(const T &v) {
    for(auto i: v)
        std::cout << i << ' ';
    std::cout << '\n';
}

void test1() {
    std::vector<int> v1;
    std::vector<int> v2(5);
    std::vector<int> v3{1, 22, 3};

    v3.push_back(9);

    std::cout << v1.size() << '\n';
    std::cout << v2.size() << '\n';
    std::cout << v3.size() << '\n';

    output(v3);
}

class Y:public std::vector<int>{
public:
    using std::vector<int>::vector;
    void sort(bool flag = true)
    {
        if(flag)
            std::sort(this->begin(),this->end());
        else
            std::sort(this->begin(),this->end(),std::greater<int>());
    }
};

void test2() {
    Y y1;
    Y y2(5);
    Y y3{1, 22, 3};

    y3.push_back(9);

    std::cout << y1.size() << '\n';
    std::cout << y2.size() << '\n';
    std::cout << y3.size() << '\n';


    y3.sort();
    output(y3);
    
    y3.sort(false);
    output(y3);
}

int main() {
    test2();
}