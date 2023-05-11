cmake_minimum_required(VERSION 3.10)
set(CMAKE_CXX_STANDARD 17)
project(TaskMaster)

option(BUILD_TESTS "build tests")
if(BUILD_TESTS)
  enable_testing()
  find_package(GTest REQUIRED)
endif()

add_subdirectory(TaskMaster)
add_executable(main src/main.cpp)

find_package(PostgreSQL REQUIRED)

include_directories(TaskMaster/include)
target_link_libraries(main TaskMaster)

target_link_libraries(main pqxx pq ${PostgreSQL_LIBRARIES})