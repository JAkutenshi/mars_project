#ifndef VENUS_PROJECT_TEST_HPP
#define VENUS_PROJECT_TEST_HPP

#include <stdint-gcc.h>
#include <string>
#include "IterationResults.hpp"
#include "Config.hpp"


namespace VenusTestLib {
    class Test {
    private:
        const uint64_t id;
        const std::string name ="NO_NAME";
        const uint64_t iterationsCount = DEFAULT_ITERATIONS_COUNT;
        const uint64_t iterationsSkip = DEFAULT_ITERATIONS_SKIP;
        IterationResults* p_iterations;

    public:
        virtual ~Test();

        Test(const uint64_t id);

        Test();
    };
}

#endif //VENUS_PROJECT_TEST_HPP
