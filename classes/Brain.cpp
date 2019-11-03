//
// Created by mgorunuch on 29.10.2019.
//

#include <iostream>
#include "Brain.h"

void Brain::proceed() {
    while (true) {
        tkr.incrementTick();
        std::cout << "Tick " << tkr.getCurrentTick()->getTickNumber() << std::endl;

        for(auto &controller: ncr.controllers) {
            controller.proceedTick(tkr.getCurrentTick());
        }

        if (tkr.getCurrentTick()->getTickNumber() > 99) {
            break;
        }
    }
}
