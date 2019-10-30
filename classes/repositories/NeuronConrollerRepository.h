//
// Created by mgorunuch on 30.10.2019.
//

#ifndef BRAIN_NEED_EAT_NEURONCONROLLERREPOSITORY_H
#define BRAIN_NEED_EAT_NEURONCONROLLERREPOSITORY_H

#include <vector>
#include "../../constants.h"
#include "../NeuronController.h"

class NeuronControllerRepository {
public:
    std::vector<NeuronController> controllers;

    explicit NeuronControllerRepository() {
        controllers.reserve(MAX_NEURONS_COUNT);
    }

    NeuronController getNeuron(int id) {
        return controllers[id];
    }

    unsigned long addNeuron(NeuronController controller) {
        controller.setId(controllers.size());
        controllers.push_back(controller);

        return controller.getId();
    }

    std::vector<NeuronController>* getVector() {
        return &controllers;
    }
};

#endif //BRAIN_NEED_EAT_NEURONCONROLLERREPOSITORY_H
