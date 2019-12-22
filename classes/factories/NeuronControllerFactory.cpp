//
// Created by mgorunuch on 29.10.2019.
//

#include "NeuronControllerFactory.h"
#include "../repositories/NeuronRepository.h"

NeuronController NeuronControllerFactory::createNeuronController(NeuronRepository* nr) {
    unsigned long neuronId = nr->createExcitatoryNeuron();

    return NeuronController(nr->getNeuron(neuronId));
}
