#include <chrono>
#include <iostream>

#include "Core.hpp"
#include "Config.hpp"

long double VenusTestLib::Core::cyclesPerNSec = calibrateCPUTicks();

VenusTestLib::Core &VenusTestLib::Core::getInstance() {
    static Core instance;
    return instance;
}

VenusTestLib::Core::Core() : testsCollector() {
}

VenusTestLib::Core::~Core() {
    // ToDo: should I delete[] p_cacheResults ?
}

uint64_t VenusTestLib::Core::getCurrentCPUCycles() {
    uint32_t eax, edx;
    __asm__ __volatile__(" rdtsc\n" : "=a" (eax), "=d" (edx));
    return ((uint64_t) eax) | (((uint64_t) edx) << 32);
}

long double VenusTestLib::Core::getCurrentCPUNSec() {
    return (getCurrentCPUCycles() / cyclesPerNSec);
}

uint64_t VenusTestLib::Core::getCurrentChronoNSec() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    return (uint64_t) nanos;
}

long double VenusTestLib::Core::calibrateCPUTicks() {
    auto start_t = getCurrentChronoNSec();
    auto start_c = getCurrentCPUCycles();
    for (int i = 0; i < CALIBRATION_ITERATIONS_COUNT; i++)
        for (int j = 0; j < CALIBRATION_ITERATIONS_COUNT; j++);
    auto end_c = getCurrentCPUCycles();
    auto end_t = getCurrentChronoNSec();
    return (end_c - start_c) / (end_t - start_t);
}

/*long double VenusTestLib::Core::getCyclesPerNsecCoeff() {
    return cyclesPerNSec;
}*/
