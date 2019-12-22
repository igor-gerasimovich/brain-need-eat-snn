//
// Created by mgorunuch on 29.10.2019.
//

#include "NeuronFactory.h"

Neuron NeuronFactory::createNeuron() {
    return Neuron();
}

ExcitatoryNeuron NeuronFactory::createExcitatoryNeuron() {
    return ExcitatoryNeuron();
}

InhibitoryNeuron NeuronFactory::createInhibitoryNeuron() {
    return InhibitoryNeuron();
}
