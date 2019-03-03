#include "Collector.hpp"

void VenusTestLib::Collector::addTest(const VenusTestLib::Test test) {
    this->tests.push_back(test);
}

std::string VenusTestLib::Collector::getJSON() {
    //ToDo
    return nullptr;
}

std::string VenusTestLib::Collector::getJSON(int i) {
    //ToDo
    return nullptr;
}

std::string VenusTestLib::Collector::getJSONbyID(int id) {
    //ToDo
    return nullptr;
}

uint64_t VenusTestLib::Collector::getTestsCount() {
    return tests.size();
}

VenusTestLib::Collector::Collector() {
    this->tests.clear();
}

VenusTestLib::Collector::Collector(const Test firstTest) {
    this->tests.clear();
    this->tests.push_back(firstTest);
}
