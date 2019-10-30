//
// Created by mgorunuch on 29.10.2019.
//

#include "Brain.h"

void Brain::proceed() {
    int tick = 0;
    while (true) {
        tkr.incrementTick();

        for(auto &controller: ncr.controllers) {
            controller.proceedTick(tkr.getCurrentTick());
        }

        if (tick > 100) {
            break;
        }
    }
}
