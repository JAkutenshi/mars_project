#include "Test.hpp"
#include "Core.hpp"

VenusTestLib::Test::Test() : id(Core::getCurrentChronoNSec()) {
    p_iterations = new IterationResults[iterationsCount];
}

VenusTestLib::Test::Test(const uint64_t id) : id(id) {}

VenusTestLib::Test::~Test() {
    //delete[] iterations;
}


