//
// Created by mgorunuch on 03.11.2019.
//

#ifndef BRAIN_NEED_EAT_NEURONCONNECTION_H
#define BRAIN_NEED_EAT_NEURONCONNECTION_H


class NeuronConnection {
private:
    unsigned long target_neuron_controller_id;

public:
    std::vector<long unsigned>multipliers{};

    explicit NeuronConnection(unsigned long targetNeuronControllerId): target_neuron_controller_id(targetNeuronControllerId) {
        multipliers.reserve(300);
    }

    unsigned long getTargetNeuronControllerId() {
        return target_neuron_controller_id;
    }
};


#endif //BRAIN_NEED_EAT_NEURONCONNECTION_H
