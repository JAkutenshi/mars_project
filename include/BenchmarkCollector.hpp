#ifndef MARS_PROJECT_BENCHMARKCOLLECTOR_HPP
#define MARS_PROJECT_BENCHMARKCOLLECTOR_HPP


class BenchmarkCollector
{

private:
    /* Here will be the instance stored. */
    static BenchmarkCollector* instance = 0;

    /* Private constructor to prevent instancing. */
    BenchmarkCollector();

public:
    /* Static access method. */
    static BenchmarkCollector* getInstance();


};

#endif //MARS_PROJECT_BENCHMARKCOLLECTOR_HPP
