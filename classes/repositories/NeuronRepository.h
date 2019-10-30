//
// Created by mgorunuch on 30.10.2019.
//

#ifndef BRAIN_NEED_EAT_NEURONREPOSITORY_H
#define BRAIN_NEED_EAT_NEURONREPOSITORY_H

#include <vector>
#include "../Neuron.h"
#include "../../constants.h"
#include "../factories/NeuronFactory.h"

class NeuronRepository {
public:
    std::vector<Neuron> neurons;

    explicit NeuronRepository() {
        neurons.reserve(MAX_NEURONS_COUNT);
    }

    Neuron* getNeuron(unsigned long id) {
        return &neurons[id];
    }

    unsigned long addNeuron(Neuron neuron) {
        neuron.setId(neurons.size());
        neurons.push_back(neuron);

        return neuron.getId();
    }

    unsigned long createAndAddNeuron() {
        return addNeuron(NeuronFactory::createNeuron());
    }
};


#endif //BRAIN_NEED_EAT_NEURONREPOSITORY_H
