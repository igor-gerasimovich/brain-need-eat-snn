//
// Created by mgorunuch on 29.10.2019.
//

#ifndef BRAIN_NEED_EAT_NEURONCONTROLLER_H
#define BRAIN_NEED_EAT_NEURONCONTROLLER_H


#include "Tick.h"
#include "Neuron.h"

class NeuronController {
private:
    unsigned long id = 0;
    Neuron* neuron;

public:
    explicit NeuronController(Neuron* neuronRef): neuron(neuronRef) {};

    void setId(unsigned long newId) {
        id = newId;
    }
    unsigned long getId() {
        return id;
    }

    bool hasSpike();
    void proceedTick(Tick* tick);
    void proceedSpike(Tick* tick);
    bool isDisabled(Tick* tick);
};


#endif //BRAIN_NEED_EAT_NEURONCONTROLLER_H
