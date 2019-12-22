cmake_minimum_required(VERSION 3.14)
project(brain_need_eat)

set(CMAKE_CXX_STANDARD 14)

file(GLOB classes_src
    "classes/**/*.h"
    "classes/**/*.cpp"
    "classes/*.h"
    "classes/*.cpp"
)

add_executable(brain_need_eat main.cpp ${classes_src})

find_package(PythonLibs 2.7)
target_include_directories(brain_need_eat PRIVATE ${PYTHON_INCLUDE_DIRS})
target_link_libraries(brain_need_eat ${PYTHON_LIBRARIES})

add_subdirectory(tests)
