#include "BenchmarkCollector.hpp"

BenchmarkCollector* BenchmarkCollector::getInstance()
{
    if (instance == 0)
    {
        instance = new Singleton();
    }

    return instance;
}
