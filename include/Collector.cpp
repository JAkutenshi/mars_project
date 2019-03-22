#include "Collector.hpp"

using namespace std;
using namespace VenusTestLib;

void Collector::addTest(const Test test) {
    tests.push_back(test);
}

string& Collector::getJSON() {
    string json = "{\n  \"tests\": [\n";

    for (uint64_t i = 0; i < tests.size() - 1; ++i) {
        json.append(tests[i].getJSON() + ",\n");
    }
    json.append(tests[tests.size() - 1].getJSON() + "\n  ]\n}");

    return json;
}

uint64_t Collector::getTestsCount() {
    return tests.size();
}

Collector::Collector() : tests() {
}

Collector::Collector(const Test firstTest) : tests() {
    tests.push_back(firstTest);
}
