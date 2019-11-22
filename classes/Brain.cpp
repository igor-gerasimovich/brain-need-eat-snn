//
// Created by mgorunuch on 29.10.2019.
//

#include <iostream>
#include "Brain.h"
#include "factories/NeuronControllerFactory.h"

void Brain::proceed() {
    while (true) {
        tkr.incrementTick();

        for(auto &controller: ncr.controllers) {
            controller.proceedTick(tkr.getCurrentTick());
        }

        if (tkr.getCurrentTick()->getTickNumber() == 1) {
            ncr.controllers[0].addSignal(Signal(600, 0));
            ncr.controllers[1].addSignal(Signal(600, 0));
            ncr.controllers[2].addSignal(Signal(600, 0));
        }
        if (tkr.getCurrentTick()->getTickNumber() == 9) {
            ncr.controllers[0].addSignal(Signal(600, 0));
        }


        if (tkr.getCurrentTick()->getTickNumber() > 15) {
            break;
        }
    }
}

void Brain::createStructure(int levels, int neuronsPerLevel) {
    for (int i = 0; i < levels; i++) {
        for (int j = 0; j < neuronsPerLevel; j++) {
            NeuronController neuronController = NeuronControllerFactory::createNeuronController(&nr);

            ncr.addNeuron(neuronController);
        }
    }

    for (int i = 0; i + 1 < levels; i++) {
        for (int j = 0; j < neuronsPerLevel; j++) {
            for (int k = 0; k < neuronsPerLevel; k++) {
                NeuronController* fromNC = &ncr.controllers[ (i * neuronsPerLevel) + j ];
                NeuronController* toNC = &ncr.controllers[ ((i + 1) * neuronsPerLevel) + k ];

                fromNC->addNeuronConnection(toNC, toNC->getId());
            }
        }
    }
}
