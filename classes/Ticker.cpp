//
// Created by mgorunuch on 30.10.2019.
//

#include "Ticker.h"

void Ticker::incrementTick() {
    current_tick = Tick(current_tick.getTickNumber() + 1);
}

Tick* Ticker::getCurrentTick() {
    return &current_tick;
}
