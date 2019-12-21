include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(runBasicTests
        ../../classes/Ticker.cpp
        ../../classes/Ticker.h
        ../../classes/Tick.h
        BasicTest.cpp
        TickerTest.cpp)

target_link_libraries(runBasicTests gtest gtest_main)
target_link_libraries(brain_need_eat)