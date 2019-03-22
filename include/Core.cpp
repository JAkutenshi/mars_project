#include <chrono>

#include "Core.hpp"
#include "Config.hpp"

using namespace std;
using namespace VenusTestLib;

long double Core::cyclesPerNSec = calibrateCPUTicks();

Core& Core::getInstance() {
    static Core instance;
    return instance;
}

Core::Core() :
    m_testsCollector(),
    m_is_test_started(false) {
}

Core::~Core() {
    // ToDo: should I delete[] p_cacheResults ?
}

uint64_t Core::getCurrentCPUCycles() {
    uint32_t eax, edx;
    __asm__ __volatile__(" rdtsc\n" : "=a" (eax), "=d" (edx));
    return ((uint64_t) eax) | (((uint64_t) edx) << 32);
}

long double Core::getCurrentCPUNSec() {
    return (getCurrentCPUCycles() / cyclesPerNSec);
}

uint64_t Core::getCurrentChronoNSec() {
    auto now = chrono::system_clock::now();
    auto duration = now.time_since_epoch();
    auto nanos = chrono::duration_cast<chrono::nanoseconds> (duration).count();
    return (uint64_t) nanos;
}

bool Core::startTest() {
    if (!m_is_test_started) {
        if (m_pCurrentTest == nullptr) {
            throw -2;
        }
        m_pCurrentTest = new Test();

    } else {
        return false;
    }
}

bool Core::startTest(const std::string&) {

}

void Core::endTest() {

}

long double Core::calibrateCPUTicks() {
    auto start_t = getCurrentChronoNSec();
    auto start_c = getCurrentCPUCycles();
    for (int i = 0; i < CALIBRATION_ITERATIONS_COUNT; i++)
        for (int j = 0; j < CALIBRATION_ITERATIONS_COUNT; j++);
    auto end_c = getCurrentCPUCycles();
    auto end_t = getCurrentChronoNSec();
    return (end_c - start_c) / (end_t - start_t);
}

/*long double Core::getCyclesPerNsecCoeff() {
    return cyclesPerNSec;
}*/
