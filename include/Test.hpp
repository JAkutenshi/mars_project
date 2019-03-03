#ifndef VENUS_PROJECT_TEST_HPP
#define VENUS_PROJECT_TEST_HPP

#include <stdint-gcc.h>
#include "IterationResults.hpp"

namespace VenusTestLib {
    class Test {
    private:
        uint64_t test_id;
        uint64_t iterationsCount;
        uint64_t iterationsSkip;
        IterationResults iterations[];


    public:

    };
}

#endif //VENUS_PROJECT_TEST_HPP
