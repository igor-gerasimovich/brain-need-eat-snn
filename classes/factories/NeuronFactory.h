//
// Created by mgorunuch on 29.10.2019.
//

#ifndef BRAIN_NEED_EAT_NEURONFACTORY_H
#define BRAIN_NEED_EAT_NEURONFACTORY_H

#include "../Neuron.h"
#include "../neurons/ExcitatoryNeuron.h"
#include "../neurons/InhibitoryNeuron.h"

class NeuronFactory {
public:
    static Neuron createNeuron();

    static ExcitatoryNeuron createExcitatoryNeuron();

    static InhibitoryNeuron createInhibitoryNeuron();
};


#endif //BRAIN_NEED_EAT_NEURONFACTORY_H
