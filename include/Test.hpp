#ifndef VENUS_PROJECT_TEST_HPP
#define VENUS_PROJECT_TEST_HPP

#include <stdint-gcc.h>
#include <string>
#include <vector>

#include "Config.hpp"
#include "IterationResults.hpp"
#include "TestResults.hpp"

namespace VenusTestLib {
    class Test {
    private:
        /* const */ uint64_t m_id;
        /* const */ std::string m_name;
        /* const */ uint64_t m_iterationsCount;
        /* const */ uint64_t m_iterationsSkip;
        std::vector<IterationResults> m_iterations;
        TestResults* m_results;

    public:
        void addIteration(const IterationResults&);


        Test();
        Test(const std::string&);
        Test(const std::string&, const uint64_t, const uint64_t);
        Test(const uint64_t, const uint64_t);
        Test(const Test&);
        virtual ~Test();

        Test& operator=(const Test&);

        const uint64_t getId() const;
        const std::string &getName() const;
        const uint64_t getIterationsCount() const;
        const uint64_t getIterationsSkip() const;
        std::vector<IterationResults>& getIterations() const;
        TestResults *getResults() const;


    };
}

#endif //VENUS_PROJECT_TEST_HPP
