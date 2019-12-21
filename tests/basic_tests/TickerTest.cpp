//
// Created by mgorunuch on 21.12.2019.
//

#include "gtest/gtest.h"
#include "../../classes/Ticker.h"

TEST(TickerTests, IsInitializeWithZero) {
    Ticker ticker = Ticker();

    ASSERT_EQ(ticker.getCurrentTick()->getTickNumber(), 0);
}

TEST(TickerTests, ShouldIncrementTick) {
    Ticker ticker = Ticker();

    unsigned long currentTick = ticker.getCurrentTick()->getTickNumber();
    ticker.incrementTick();

    ASSERT_EQ(ticker.getCurrentTick()->getTickNumber(), currentTick + 1);
}