#include <stdio.h>

/* ToDo: to the Singleton */
#define ITERATIONS_COUNT 10
unsigned long int _ip, _sp, _bp;
int i;

/* ToDo: CONTEXT SAVE'N'STORE
         For saving (Linux): RBP, RBX, RSP, R12, R13, R14, and R15 */

//
#define START()                                       \
    i = ITERATIONS_COUNT;                             \
    __asm__("mov %0, rsp;\n\t" : "=r"(_sp) );         \
    __asm__("mov %0, rbp;\n\t" : "=r"(_bp) );         \
    /* 0x7 is size of lea instruction, so, it will ref to exactly the line below */ \
    __asm__("lea %0, [rip - 0x7];\n\t" : "=r"(_ip) ); \
    __asm__("mov rsp, %0;\n\t" : : "r"(_sp) );        \
    __asm__("mov rbp, %0;\n\t" : : "r"(_bp) );        \

#define END()                                         \
    if (i != 0)                                       \
    {                                                 \
        i--;                                          \
        __asm__("jmp %0;\n\t" : : "r"(_ip));          \
    }                                                 \

#define SAMPLE() \
    END()        \
    START()

void foo()
{
    printf("k!\n");
    int k = 0;
    SAMPLE()
    printf("%d\n", k);
    SAMPLE()
    printf("Op! in %d\n", i);
    SAMPLE()
    printf("Op! out %d\n", i);

    return;
}

int main()
{
    START()
    foo();
    END()

    return 0;
}