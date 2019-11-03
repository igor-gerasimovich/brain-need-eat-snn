//
// Created by mgorunuch on 29.10.2019.
//

#include "NeuronController.h"
#include "../constants.h"

void NeuronController::proceedTick(Tick* tick) {
    if (isDisabled(tick)) {
        clearSignalsQueue();
        return;
    }

    appendSignalsQueue();
    clearSignalsQueue();

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
    Signal generatedSignal = Signal(DEFAULT_NEURON_SPIKE_SIGNAL_POWER);
    sendSignalToNeurons(generatedSignal);

    const unsigned long sleepToTick = SLEEP_AFTER_SPIKE_TICKS_COUNT + tick->getTickNumber();
    neuron->setDisabledToTick(sleepToTick);
}

void NeuronController::addNeuronConnection(NeuronController* neuron_controller, unsigned long targetNeuronControllerId) {
    neuron_controllers_aliases[targetNeuronControllerId] = neuron_controller;
    neuron_connections.emplace_back(targetNeuronControllerId);
}

void NeuronController::addSignal(Signal signal) {
    queued_signals.push_back(signal);
}

void NeuronController::sendSignalToNeurons(Signal signal) {
    for(auto &connection: neuron_connections) {
        NeuronController* controller = neuron_controllers_aliases[connection.getTargetNeuronControllerId()];

        controller->addSignal(signal);
    }
}

void NeuronController::clearSignalsQueue() {
    queued_signals.clear();
}

void NeuronController::appendSignalsQueue() {
    for (auto signal: queued_signals) {
        appendSignal(signal);
    }
}

void NeuronController::appendSignal(Signal signal) {
    auto currentPotential = neuron->getCurrentPotential();

    neuron->setCurrentPotential(currentPotential + signal.getPower());

    if (neuron->getCurrentPotential() < MIN_NEURON_POTENTIAL_LEVEL) {
        neuron->setCurrentPotential(MIN_NEURON_POTENTIAL_LEVEL);
        return;
    }

    if (neuron->getCurrentPotential() > MAX_NEURON_POTENTIAL_LEVEL) {
        neuron->setCurrentPotential(MAX_NEURON_POTENTIAL_LEVEL);
        return;
    }
}

void NeuronController::resetNeuronPotential() {
    neuron->setCurrentPotential(BASE_NEURON_POTENTIAL);
}
