#include <stdio.h>
#include "VenusTest.hpp"

#define ITERATIONS_COUNT 10000
int i;

void boo() {
    printf("4\n");
    SAMPLE()
    printf("5\n");
}

void foo() {
    printf("1\n");
    int k = 0;
    SAMPLE()
    printf("2\n");
    SAMPLE()
    printf("3\n");
    SAMPLE()
    boo();

    return;
}

int main() {
    START()
    foo();//printf("1\n");
    END()

    return 0;
}