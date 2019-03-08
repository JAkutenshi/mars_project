#ifndef VENUS_PROJECT_TESTRESULTS_HPP
#define VENUS_PROJECT_TESTRESULTS_HPP


#include <cstdint>
#include <vector>

#include "IterationResults.hpp"

namespace VenusTestLib {
    class TestResults {
    private:
        /* const */ long double m_cpu_time;
        /* const */ long double m_chrono_time;
        /* const */ long double m_bytes;

    public:
        TestResults(const vector<IterationResults>, const uint64_t, const uint64_t);

        long double getCPUTime() const;
        long double getChronoTime() const;
        long double getBytes() const;
    };
}

#endif //VENUS_PROJECT_TESTRESULTS_HPP
