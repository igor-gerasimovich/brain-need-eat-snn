//
// Created by mgorunuch on 29.10.2019.
//

#ifndef BRAIN_NEED_EAT_NEURONCONTROLLERFACTORY_H
#define BRAIN_NEED_EAT_NEURONCONTROLLERFACTORY_H


#include "../NeuronController.h"
#include "../repositories/NeuronRepository.h"

class NeuronControllerFactory {
public:
    static NeuronController createNeuronController(NeuronRepository* nr);
};


#endif //BRAIN_NEED_EAT_NEURONCONTROLLERFACTORY_H
