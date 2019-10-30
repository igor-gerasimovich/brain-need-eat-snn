//
// Created by mgorunuch on 29.10.2019.
//

#ifndef BRAIN_NEED_EAT_BRAIN_H
#define BRAIN_NEED_EAT_BRAIN_H

#include <utility>
#include <vector>
#include "Tick.h"
#include "NeuronController.h"
#include "repositories/NeuronConrollerRepository.h"
#include "Ticker.h"

class Brain {
private:
    NeuronControllerRepository ncr;
    Ticker tkr;

    void incrementTick();

public:
    explicit Brain(): ncr(NeuronControllerRepository()), tkr(Ticker()) {};

    void proceed();
};


#endif //BRAIN_NEED_EAT_BRAIN_H
