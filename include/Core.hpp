#ifndef VENUS_PROJECT_CORE_HPP
#define VENUS_PROJECT_CORE_HPP

#include <Collector.hpp>
#include <cstdint>

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
        static long double getCurrentCPUNsec();
        static uint64_t getCurrentChronoNsec();
        //static long double getCyclesPerNsecCoeff();

    private:
        /* FRIENDS */
        friend Test;

        /* CONSTANTS */
        // Calibration's iterations count (O(n^2))
        static const long calibration_iterations_count = CORE_CPU_CALIBRATION_CYCLES_COUNT;

        /* FIELDS */
        // CPU cycles count in the nanosecond coefficient
        static long double cycles_per_nsec;

    private:
        // Collection of the tests
        Collector testsCollector;
        // Cached current results array to exclude extra functions calls
        IterationResults* p_CacheResults = nullptr;

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
