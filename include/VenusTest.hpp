#ifndef VENUS_PROJECT_VENUSTEST_HPP
#define VENUS_PROJECT_VENUSTEST_HPP

#include "Core.hpp"

namespace VenusTestLib {
    namespace MacrosOnly {
        Core &directInstance = Core::getInstance();
    }
}

/* MACROS THERE */
#define STORE_STATE()                                                                                        \
    __asm__ __volatile__("mov %0, rsp;\n\t" : "=m"(VenusTestLib::MacrosOnly::directInstance._rsp));          \
    __asm__ __volatile__("mov %0, rbp;\n\t" : "=m"(VenusTestLib::MacrosOnly::directInstance._rbp));          \
    __asm__ __volatile__("mov %0, rbx;\n\t" : "=m"(VenusTestLib::MacrosOnly::directInstance._rbx));          \
    __asm__ __volatile__("mov %0, r12;\n\t" : "=m"(VenusTestLib::MacrosOnly::directInstance._r12));          \
    __asm__ __volatile__("mov %0, r13;\n\t" : "=m"(VenusTestLib::MacrosOnly::directInstance._r13));          \
    __asm__ __volatile__("mov %0, r14;\n\t" : "=m"(VenusTestLib::MacrosOnly::directInstance._r14));          \
    __asm__ __volatile__("mov %0, r15;\n\t" : "=m"(VenusTestLib::MacrosOnly::directInstance._r15));          \
    __asm__ __volatile__("lea %0, [rip - 0x7];\n\t" : "=r"(VenusTestLib::MacrosOnly::directInstance._rip));  \
    __asm__ __volatile__("mov r12, %0;\n\t" : : "m"(VenusTestLib::MacrosOnly::directInstance._r12));         \
    __asm__ __volatile__("mov r13, %0;\n\t" : : "m"(VenusTestLib::MacrosOnly::directInstance._r13));         \
    __asm__ __volatile__("mov r14, %0;\n\t" : : "m"(VenusTestLib::MacrosOnly::directInstance._r14));         \
    __asm__ __volatile__("mov r15, %0;\n\t" : : "m"(VenusTestLib::MacrosOnly::directInstance._r15));         \
    __asm__ __volatile__("mov rbx, %0;\n\t" : : "m"(VenusTestLib::MacrosOnly::directInstance._rbx));         \
    __asm__ __volatile__("mov rsp, %0;\n\t" : : "m"(VenusTestLib::MacrosOnly::directInstance._rsp));         \
    __asm__ __volatile__("mov rbp, %0;\n\t" : : "m"(VenusTestLib::MacrosOnly::directInstance._rbp));         \

#define RESTORE_STATE()                                                                         \
    __asm__ __volatile__("jmp %0;\n\t" : : "m"(VenusTestLib::MacrosOnly::directInstance._rip)); \

#define START_SAMPLE(name) \



#define SAMPLE() \
    END()        \
    START()      \

#endif //VENUS_PROJECT_VENUSTEST_HPP
