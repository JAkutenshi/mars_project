#include <stdio.h>
#include "VenusTest.hpp"

#define ITERATIONS_COUNT 10
int i;

void foo()
{
    printf("1\n");
    int k = 0;


    SAMPLE()
    printf("2\n");
    SAMPLE()
    printf("3\n");
    SAMPLE()
    printf("4\n");
    return;
}

int main()
{
    START()
    foo();//printf("1\n");
    END()

    return 0;
}