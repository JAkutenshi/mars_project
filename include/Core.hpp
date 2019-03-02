#ifndef VENUS_PROJECT_CORE_HPP
#define VENUS_PROJECT_CORE_HPP

#include <Collector.hpp>
#include <cstdint>

namespace VenusTest {
    class Core {
    public:
        /* STORED AND LOADED REGS */
        // They're public for no getter-setter functions calling -> no stack use
        uint64_t _rip, _rbp, _rbx, _rsp, _r12, _r13, _r14, _r15;

        /* Static access method. */
        static Core &getInstance();

    private:
        /* FIELDS */
        // CPU cycles count in the nanosecond coefficient
        long double cycles_per_nsec;
        // Calibration's iterations count (O(n^2))
        const long calibration_iterations_count = 10000;
        Collector testsCollector;
        // Cached current results array to exclude extra functions calls
        IterationResults* p_CacheResults = nullptr;

        // Private constructor and destructor to prevent instancing.
        Core();
        ~Core();
        // Prevent access to copy and to assignment operator
        Core(const Core &) = delete;
        Core &operator=(const Core &) = delete;
        // Get CPU cycles and timer methods
        uint64_t getCurrentCPUCycles();
        uint64_t getCurrentNanoseconds();
        // Initial CPU cycles per nsec calibration
        void calibrateCPUTicks();
    };
}


#endif //VENUS_PROJECT_CORE_HPP
