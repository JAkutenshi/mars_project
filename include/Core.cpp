#include "Core.hpp"

VenusTest::Core &VenusTest::Core::getInstance() {
    static Core instance;
    return instance;
}

VenusTest::Core::Core() {
    calibrateCPUTicks();
}

VenusTest::Core::~Core() {

}

uint64_t VenusTest::Core::getCurrentCPUCycles() {
    uint32_t eax, edx;
    __asm__ __volatile__(" rdtsc\n" : "=a" (eax), "=d" (edx));
    return ((uint64_t) eax) | (((uint64_t) edx) << 32);
}

uint64_t VenusTest::Core::getCurrentNanoseconds() {
    auto now = std::chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto nanos = std::chrono::duration_cast<std::chrono::nanoseconds>(duration).count();
    return nanos;
}

void VenusTest::Core::calibrateCPUTicks() {
    auto start_t = getCurrentNanoseconds();
    auto start_c = getCurrentCPUCycles();
    for (int i = 0; i < calibration_iterations_count i++)
        for (int j = 0; j < calibration_iterations_count; j++);
    auto end_c = getCurrentCPUCycles();
    auto end_t = getCurrentNanoseconds();
    cycles_per_nsec = (end_c - start_c) / (end_t - start_t);
}
