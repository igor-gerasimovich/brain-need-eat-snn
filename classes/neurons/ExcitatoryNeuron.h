//
// Created by mgorunuch on 22.12.2019.
//

#ifndef BRAIN_NEED_EAT_EXCITATORYNEURON_H
#define BRAIN_NEED_EAT_EXCITATORYNEURON_H

#include "../Neuron.h"

class ExcitatoryNeuron : public Neuron {
public:
    NeuronType getType() const override {
        return NeuronTypeExcitatory;
    }
};


#endif //BRAIN_NEED_EAT_EXCITATORYNEURON_H
