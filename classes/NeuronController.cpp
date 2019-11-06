//
// Created by mgorunuch on 29.10.2019.
//

#include <iostream>
#include "NeuronController.h"
#include "../constants.h"

void NeuronController::proceedTick(Tick* tick) {
    if (isDisabled(tick)) {
        clearSignalsQueue();
        neuron->addToSpikeHistory(false);
        neuron->addToPowerHistory(0);
        return;
    }

    appendSignalsQueue();
    clearSignalsQueue();

    int powerLoss = neuron->getCurrentPotential() - POWER_LOSS_PER_TICK;
    appendSignal(Signal(std::max(powerLoss, BASE_NEURON_POTENTIAL), 0));

    // std::cout << "NEURON: " << id << "; Current potential: " << neuron->getCurrentPotential() << "; Has spike? " << hasSpike() << std::endl;
    neuron->addToSpikeHistory(hasSpike());
    neuron->addToPowerHistory(neuron->getCurrentPotential());
    if (hasSpike()) {
        // std::cout << "NEURON: " << id << "; Has spike in controller: " << id << " with power " << neuron->getCurrentPotential() << std::endl;

        proceedSpike(tick);
    }
    // std::cout << std::endl;
}

bool NeuronController::isDisabled(Tick* tick) {
    return neuron->getDisabledToTick() > tick->getTickNumber();
}

bool NeuronController::hasSpike() {
    return neuron->getCurrentPotential() >= SPIKE_GENERATION_LEVEL;
}

void NeuronController::proceedSpike(Tick* tick) {
    Signal generatedSignal = Signal(DEFAULT_NEURON_SPIKE_SIGNAL_POWER, id);
    sendSignalToNeurons(generatedSignal);

    const unsigned long sleepToTick = SLEEP_AFTER_SPIKE_TICKS_COUNT + tick->getTickNumber();
    neuron->setDisabledToTick(sleepToTick);

    neuron->setCurrentPotential(BASE_NEURON_POTENTIAL);
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
    // std::cout << "NEURON: " << id << "; Append signal from neuron: " << signal.getFomId() << " to neuron: " << id << " with power: " << signal.getPower() << std::endl;

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
