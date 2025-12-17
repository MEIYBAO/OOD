#include "vectorInt.hpp"

int main() {
    vectorInt vi(5, 10);
    for(auto i = 0; i < vi.size(); ++i)
        std::cout << vi[i] << " ";
    return 0;
}