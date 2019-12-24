//
// Created by mgorunuch on 03.11.2019.
//

#ifndef BRAIN_NEED_EAT_NEURONCONNECTION_H
#define BRAIN_NEED_EAT_NEURONCONNECTION_H


#include "Signal.h"

class NeuronConnection {
private:
    unsigned long to_neuron_controller_id;
    unsigned long from_neuron_controller_id;
    bool is_modification_allowed;
    double modification_multiplier;

public:
    std::vector<long unsigned>multipliers{};

    explicit NeuronConnection(
        unsigned long toNeuronControllerId,
        unsigned long fromNeuronControllerId
    ): to_neuron_controller_id(toNeuronControllerId), from_neuron_controller_id(fromNeuronControllerId) {
        multipliers.reserve(300);
        is_modification_allowed = false;
        modification_multiplier = 1;
    }

    explicit NeuronConnection(
        unsigned long toNeuronControllerId,
        unsigned long fromNeuronControllerId,
        double modificationMultiplier
    ): to_neuron_controller_id(toNeuronControllerId), from_neuron_controller_id(fromNeuronControllerId), modification_multiplier(modificationMultiplier) {
        multipliers.reserve(300);
        is_modification_allowed = true;
    }

    Signal modifySignal(Signal signal) {
        if (!is_modification_allowed) {
            return signal;
        }

        int currentPower = signal.getPower();
        signal.setPower((int)(currentPower * modification_multiplier));

        return signal;
    }

    unsigned long getTargetNeuronControllerId() {
        return to_neuron_controller_id;
    }
};


#endif //BRAIN_NEED_EAT_NEURONCONNECTION_H
