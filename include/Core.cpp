#include <chrono>
#include <iostream>

#include "Core.hpp"
#include "Config.hpp"

long double VenusTestLib::Core::cycles_per_nsec = calibrateCPUTicks();

VenusTestLib::Core &VenusTestLib::Core::getInstance() {
    static Core instance;
    return instance;
}

VenusTestLib::Core::Core() : testsCollector() {
}

VenusTestLib::Core::~Core() {
    // ToDo: should I delete[] p_CacheResults ?
}

uint64_t VenusTestLib::Core::getCurrentCPUCycles() {
    uint32_t eax, edx;
    __asm__ __volatile__(" rdtsc\n" : "=a" (eax), "=d" (edx));
    return ((uint64_t) eax) | (((uint64_t) edx) << 32);
}

long double VenusTestLib::Core::getCurrentCPUNsec() {
    return (getCurrentCPUCycles() / cycles_per_nsec);
}

uint64_t VenusTestLib::Core::getCurrentChronoNsec() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    return (uint64_t) nanos;
}

long double VenusTestLib::Core::calibrateCPUTicks() {
    auto start_t = getCurrentChronoNsec();
    auto start_c = getCurrentCPUCycles();
    for (int i = 0; i < calibration_iterations_count; i++)
        for (int j = 0; j < calibration_iterations_count; j++);
    auto end_c = getCurrentCPUCycles();
    auto end_t = getCurrentChronoNsec();
    return (end_c - start_c) / (end_t - start_t);
}

/*long double VenusTestLib::Core::getCyclesPerNsecCoeff() {
    return cycles_per_nsec;
}*/
