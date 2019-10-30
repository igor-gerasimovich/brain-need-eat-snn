//
// Created by mgorunuch on 29.10.2019.
//

#include "NeuronControllerFactory.h"
#include "NeuronFactory.h"
#include "../repositories/NeuronConrollerRepository.h"
#include "../repositories/NeuronRepository.h"

NeuronController NeuronControllerFactory::createNeuronController(NeuronRepository* nr) {
    unsigned long neuronId = nr->createAndAddNeuron();

    return NeuronController(nr->getNeuron(neuronId));
}
