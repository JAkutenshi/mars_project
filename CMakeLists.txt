cmake_minimum_required (VERSION 3.2)
project(venus_project VERSION 2.0)

set(CMAKE_CXX_FLAGS "-masm=intel")

include_directories(include)
set(VENUS_SRC
        include/Core.cpp
        include/Collector.cpp
        include/Test.cpp
        include/IterationResults.cpp
        )


add_executable(venus_example src/main.cpp ${VENUS_SRC})

