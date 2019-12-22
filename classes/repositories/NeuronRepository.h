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
private:


public:
    std::vector<Neuron*> neurons;
    std::vector<Neuron> baseNeurons;
    std::vector<ExcitatoryNeuron> excitatoryNeurons;
    std::vector<InhibitoryNeuron> inhibitoryNeurons;

    explicit NeuronRepository() {
        neurons.reserve(MAX_NEURONS_COUNT);
        baseNeurons.reserve(MAX_BASE_NEURONS_COUNT);
        excitatoryNeurons.reserve(MAX_EXCITATORY_NEURONS_COUNT);
        inhibitoryNeurons.reserve(MAX_INHIBITORY_NEURONS_COUNT);
    }

    Neuron* getNeuron(unsigned long id) {
        return neurons[id];
    }

    unsigned long createExcitatoryNeuron() {
        ExcitatoryNeuron neuron = NeuronFactory::createExcitatoryNeuron();
        neuron.setId(neurons.size());

        excitatoryNeurons.push_back(neuron);
        neurons.push_back(&excitatoryNeurons[neuron.getId()]);

        return neuron.getId();
    }

    unsigned long createInhibitoryNeuron() {
        InhibitoryNeuron neuron = NeuronFactory::createInhibitoryNeuron();
        neuron.setId(neurons.size());

        inhibitoryNeurons.push_back(neuron);
        neurons.push_back(&inhibitoryNeurons[neuron.getId()]);

        return neuron.getId();
    }
};


#endif //BRAIN_NEED_EAT_NEURONREPOSITORY_H
