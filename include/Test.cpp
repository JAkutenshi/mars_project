#include "Test.hpp"
#include "Core.hpp"

using namespace std;
using namespace VenusTestLib;

void Test::addIteration(const IterationResults& results) {
    m_iterations.push_back(results);
}

Test::Test() :
    m_id(Core::getCurrentChronoNSec()),
    m_name(DEFAULT_TESTS_NAME),
    m_iterationsCount(DEFAULT_ITERATIONS_COUNT),
    m_iterationsSkip(DEFAULT_ITERATIONS_SKIP),
    m_iterations(m_iterationsCount, -1) {
    results = nullptr;
}

Test::Test(const string& name) :
    m_id(Core::getCurrentChronoNSec()),
    m_name(name),
    m_iterationsCount(DEFAULT_ITERATIONS_COUNT),
    m_iterationsSkip(DEFAULT_ITERATIONS_SKIP),
    m_iterations(m_iterationsCount, -1) {
    results = nullptr;
}

Test::Test(const string& name,
           const uint64_t count,
           const uint64_t skip) :
    m_id(Core::getCurrentChronoNSec()),
    m_name(name),
    m_iterationsCount(count),
    m_iterationsSkip(skip),
    m_iterations(m_iterationsCount, -1) {
    results = nullptr;
}

Test::Test(const uint64_t count,
           const uint64_t skip) :
    m_id(Core::getCurrentChronoNSec()),
    m_name(DEFAULT_TESTS_NAME),
    m_iterationsCount(count),
    m_iterationsSkip(skip),
    m_iterations(m_iterationsCount, -1) {
    results = nullptr;
}

Test::Test(const Test& test) :
    m_id(test.getId()),
    m_name(test.getName()),
    m_iterationsCount(test.getIterationsCount()),
    m_iterationsSkip(test.getIterationsCount()),
    m_iterations(test.getIterations()) {
    results = nullptr;
}

Test::~Test() {
    if (results != nullptr) {
        delete results;
    }
}

Test& Test::operator=(const Test& test) {
    if (this != &test) {
        m_id = test.getId();
        m_name = test.getName();
        m_iterationsCount = test.getIterationsCount();
        m_iterationsSkip = test.getIterationsSkip();
        m_iterations = test.getIterations();
    }

    return *this;
}

const uint64_t Test::getId() const {
    return id;
}

const std::string& Test::getName() const {
    return name;
}

const uint64_t Test::getIterationsCount() const {
    return iterationsCount;
}

const uint64_t Test::getIterationsSkip() const {
    return iterationsSkip;
}

IterationResults Test::getIterations() const {
    return p_iterations;
}
