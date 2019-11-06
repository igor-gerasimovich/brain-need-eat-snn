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
#include "repositories/NeuronRepository.h"

class Brain {
private:
    Ticker tkr;

public:
    NeuronControllerRepository ncr;
    NeuronRepository nr;

    explicit Brain(): ncr(NeuronControllerRepository()), tkr(Ticker()), nr(NeuronRepository()) {};

    void proceed();

    void createStructure(int levels, int neuronsPerLevel);
};


#endif //BRAIN_NEED_EAT_BRAIN_H
