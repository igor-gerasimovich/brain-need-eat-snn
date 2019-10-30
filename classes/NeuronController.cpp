//
// Created by mgorunuch on 29.10.2019.
//

#include "NeuronController.h"
#include "../constants.h"

void NeuronController::proceedTick(Tick* tick) {
    if (isDisabled(tick)) {
        // TODO: Clear signals queue
        return;
    }

    if (hasSpike()) {
        proceedSpike(tick);
    }
}

bool NeuronController::isDisabled(Tick* tick) {
    return neuron->getDisabledToTick() > tick->getTickNumber();
}

bool NeuronController::hasSpike() {
    return neuron->getCurrentPotential() >= SPIKE_GENERATION_LEVEL;
}

void NeuronController::proceedSpike(Tick* tick) {
    // TODO: More stuff

    const unsigned long sleepToTick = SLEEP_AFTER_SPIKE_TICKS_COUNT + tick->getTickNumber();
    neuron->setDisabledToTick(sleepToTick);
}
