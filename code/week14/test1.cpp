// ±¸ÓÃ´úÂë1

#include <iostream>
#include <string>
#include <fstream>

void test1() {
    int n = 42;
    std::string s{"cosmos"};
    

    std::ofstream fout;
    fout.open("1.txt");

    fout<<n<<" "<<s;

    fout.close();
}

void test2()
{
    std::ifstream fin;
    fin.open("1.txt");
    int n;
    std::string s;

    fin>>n>>s;
    std::cout<<n<<" "<<s<<"\n";
    fin.close();
}

int main() {
    test1();
    test2();
}