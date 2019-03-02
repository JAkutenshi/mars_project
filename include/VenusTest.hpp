//
// Created by jakutenshi on 3/2/19.
//

#ifndef VENUS_PROJECT_VENUSTEST_HPP
#define VENUS_PROJECT_VENUSTEST_HPP

#include "Core.hpp"

namespace VenusTest {
    namespace MacrosOnly {
        Core &tmpInstance = Core::getInstance();
    }
}

/* MACROS THERE */
#define START()                                                        \
        i = ITERATIONS_COUNT;                                          \
        __asm__("mov %0, rsp;\n\t" : "=m"(VenusTest::MacrosOnly::tmpInstance._rsp));          \
        __asm__("mov %0, rbp;\n\t" : "=m"(VenusTest::MacrosOnly::tmpInstance._rbp));          \
        __asm__("lea %0, [rip - 0x7];\n\t" : "=r"(VenusTest::MacrosOnly::tmpInstance._rip));  \
        __asm__("mov rsp, %0;\n\t" : : "m"(VenusTest::MacrosOnly::tmpInstance._rsp));         \
        __asm__("mov rbp, %0;\n\t" : : "m"(VenusTest::MacrosOnly::tmpInstance._rbp));         \


#define END()                                                          \
        if (i != 0)                                                    \
        {                                                              \
            i--;                                                       \
            __asm__("jmp %0;\n\t" : : "m"(VenusTest::MacrosOnly::tmpInstance._rip));          \
        }                                                              \


#define SAMPLE() \
    END()        \
    START()      \

#endif //VENUS_PROJECT_VENUSTEST_HPP
