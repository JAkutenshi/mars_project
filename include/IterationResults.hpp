#ifndef VENUS_PROJECT_ITERATIONRESULTS_HPP
#define VENUS_PROJECT_ITERATIONRESULTS_HPP

#include <cstdint>

namespace VenusTestLib {
    class IterationResults {
    private:
        /* const */ uint64_t m_cpu_nsec    = 0;
        /* const */ uint64_t m_chrono_nsec = 0;
        /* const */ uint64_t m_bytes       = 0;
    public:
        IterationResults(uint64_t, uint64_t, uint64_t);

        uint64_t getCPUNSec() const;
        uint64_t getChronoNSec() const;
        uint64_t getBytes() const;
    };
}


#endif //VENUS_PROJECT_ITERATIONRESULTS_HPP
