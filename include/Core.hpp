#ifndef VENUS_PROJECT_CORE_HPP
#define VENUS_PROJECT_CORE_HPP

#include <cstdint>

#include "Collector.hpp"

namespace VenusTestLib {
    class Core {
    public:
        /* STORED AND LOADED REGS */
        // They're public for no getter-setter functions calling -> no stack usage
        uint64_t _rip, _rbp, _rbx, _rsp, _r12, _r13, _r14, _r15;
        /* Static access method. */
        static Core &getInstance();
        // Get CPU cycles and timer methods
        static uint64_t getCurrentCPUCycles();
        static long double getCurrentCPUNSec();
        static uint64_t getCurrentChronoNSec();
        //static long double getCyclesPerNsecCoeff();

    private:
        /* CONSTANTS */
        // Calibration's iterations count (O(n^2))
        static const long CALIBRATION_ITERATIONS_COUNT = CORE_CPU_CALIBRATION_CYCLES_COUNT;

        /* FIELDS */
        // CPU cycles count in the nanosecond coefficient
        static long double cyclesPerNSec;
        // Collection of the tests
        Collector testsCollector;
        // Cached current m_results array to exclude extra functions calls
        Test* currentTest;

        /* METHODS */
        // Private constructor and destructor to prevent instancing.
        Core();
        ~Core();
        // Prevent access to copy and to assignment operator
        Core(const Core &) = delete;
        Core &operator=(const Core &) = delete;
        // Initial CPU cycles per nsec calibration
        static long double calibrateCPUTicks();
    };
}


#endif //VENUS_PROJECT_CORE_HPP
