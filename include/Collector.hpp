#ifndef VENUS_PROJECT_COLLECTOR_HPP
#define VENUS_PROJECT_COLLECTOR_HPP

#include "Test.hpp"
#include <vector>
#include <string>
#include <stdint-gcc.h>

namespace VenusTestLib {
    class Collector {
    private:
        std::vector<Test> tests;

    public:
        Collector();

        Collector(const Test firstTest);

        void addTest(const Test test);
        std::string getJSON();
        std::string getJSON(int i);
        std::string getJSONbyID(int id);
        uint64_t getTestsCount();
    };
}

#endif //VENUS_PROJECT_BENCHMARKCOLLECTOR_HPP
