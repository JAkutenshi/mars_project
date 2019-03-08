#include "IterationResults.hpp"

using namespace VenusTestLib;

IterationResults::IterationResults(uint64_t cpu_nsec, uint64_t chrono_nsec, uint64_t bytes) :
    m_cpu_nsec(cpu_nsec),
    m_chrono_nsec(chrono_nsec),
    m_bytes(bytes) {}

uint64_t IterationResults::getCPUNSec() const {
    return m_cpu_nsec;
}

uint64_t IterationResults::getChronoNSec() const {
    return m_chrono_nsec;
}

uint64_t IterationResults::getBytes() const {
    return m_bytes;
}
