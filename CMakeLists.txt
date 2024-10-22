cmake_minimum_required(VERSION 3.28 FATAL_ERROR)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


option(BUILD_TESTS "Build the google tests" ON)

add_subdirectory(TimeLib)
target_include_directories(TimeLib PUBLIC .)

add_executable(time_main main.cpp)
target_link_libraries(time_main TimeLib)

if(BUILD_TESTS)
    enable_testing()
    add_subdirectory(tests)
endif()
