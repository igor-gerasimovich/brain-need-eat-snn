//
// Created by mgorunuch on 30.10.2019.
//

#ifndef BRAIN_NEED_EAT_TICKER_H
#define BRAIN_NEED_EAT_TICKER_H


#include "Tick.h"

class Ticker {
private:
    Tick current_tick;

public:
    explicit Ticker(): current_tick(Tick(0)) {}

    void incrementTick();
    Tick* getCurrentTick();
};


#endif //BRAIN_NEED_EAT_TICKER_H
