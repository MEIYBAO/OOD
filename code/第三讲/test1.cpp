#include <stdio.h>
#include <math.h>

void func() {
    printf("func test 1\n");
}


void func(int n) {
    printf("func test 2\n");
}

void func(double n) {
    printf("func test 3\n");
}

int main() {
    func(42);

    return 0;
}