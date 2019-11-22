//
// Created by mgorunuch on 29.10.2019.
//

#ifndef BRAIN_NEED_EAT_NEURONCONTROLLER_H
#define BRAIN_NEED_EAT_NEURONCONTROLLER_H


#include <vector>
#include <map>
#include "Tick.h"
#include "Neuron.h"
#include "NeuronConnection.h"
#include "../constants.h"
#include "Signal.h"

class NeuronController {
private:
    unsigned long id = 0;
    Neuron* neuron;
    std::vector<NeuronConnection> neuron_connections;
    std::vector<Signal> queued_signals;
    std::map<int, NeuronController*> neuron_controllers_aliases;

    void appendSignal(Signal signal);
    void appendSignalsQueue();
    void clearSignalsQueue();

    void resetNeuronPotential();

    void sendSignalToNeurons(Signal signal);

public:
    explicit NeuronController(Neuron* neuronRef): neuron(neuronRef) {
        neuron_connections.reserve(MAX_CONNECTIONS_PER_NEURON);
        queued_signals.reserve(MAX_CONNECTIONS_PER_NEURON);

        resetNeuronPotential();
    };

    void setId(unsigned long newId) {
        id = newId;
    }
    unsigned long getId() {
        return id;
    }

    Neuron* getNeuron() {
        return neuron;
    }

    bool hasSpike();
    void proceedTick(Tick* tick);
    void proceedSpike(Tick* tick);
    bool isDisabled(Tick* tick);

    void addNeuronConnection(NeuronController* neuron_controller, unsigned long targetNeuronControllerId);
    void addSignal(Signal signal);

    void proceedBaseLevelRecovery();
};


#endif //BRAIN_NEED_EAT_NEURONCONTROLLER_H
