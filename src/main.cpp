#include <stdio.h>
#include <iostream>

#include "VenusTest.hpp"

#define ITERATIONS_COUNT 10
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
    printf("3\n");
    SAMPLE()
    boo();

    return;
}

void comp(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++);
}

int main() {
    using namespace std;


    /*START()
    foo();//printf("1\n");
    END()*/

    return 0;
}