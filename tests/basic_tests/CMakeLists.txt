include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

file(GLOB classes_src
    "../../classes/**/*.h"
    "../../classes/**/*.cpp"
    "../../classes/*.h"
    "../../classes/*.cpp"
)

file(GLOB tests_src
    "*Test.cpp"
)

add_executable(runBasicTests
    ${classes_src}
    ${tests_src}
)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(brain_need_eat)