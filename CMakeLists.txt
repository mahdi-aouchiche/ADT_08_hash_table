cmake_minimum_required(VERSION 3.0.0)
project(CS014_Lab8 VERSION 1.0.0)

set(CMAKE_CXX_STANDARD 11)

include(CTest)
enable_testing()

add_executable( hash_table
    ./src/main.cpp
)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)