#include "TestResults.hpp"

using namespace std;
using namespace VenusTestLib;

TestResults::TestResults(const vector<IterationResults> iterations,
        const uint64_t count,
        const uint64_t skip)
{
    if (iterations.size() != count) {
        throw -1;
        // ToDo: create exception classes
    } else {
        // The reason is possible uint64_t overflow
        uint64_t start = count - skip;
        m_cpu_time    = iterations[start].getCPUNSec();
        m_chrono_time = iterations[start].getChronoNSec();
        m_bytes       = iterations[start].getBytes();
        long double coeff;
        for (uint64_t i = start + 1; i < iterations.size(); ++i) {
            coeff = (i - 1) / i;
            m_cpu_time    = m_cpu_time    * coeff + iterations[i].getCPUNSec()    / coeff;
            m_chrono_time = m_chrono_time * coeff + iterations[i].getChronoNSec() / coeff;
            m_bytes       = m_bytes       * coeff + iterations[i].getBytes()      / coeff;
        }
    }
}

long double TestResults::getCPUTime() const {
    return m_cpu_time;
}

long double TestResults::getChronoTime() const {
    return m_chrono_time;
}

long double TestResults::getBytes() const {
    return m_bytes;
}
