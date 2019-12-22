//
// Created by mgorunuch on 22.12.2019.
//

#ifndef BRAIN_NEED_EAT_INHIBITORYNEURON_H
#define BRAIN_NEED_EAT_INHIBITORYNEURON_H

#include "../Neuron.h"

class InhibitoryNeuron : public Neuron {
public:
    NeuronType getType() const override {
        return NeuronTypeInhibitory;
    }
};


#endif //BRAIN_NEED_EAT_INHIBITORYNEURON_H
