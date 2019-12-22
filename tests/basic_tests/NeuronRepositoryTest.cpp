//
// Created by mgorunuch on 22.12.2019.
//

#include "gtest/gtest.h"
#include "../../classes/repositories/NeuronRepository.h"

TEST(NeuronRepositoryTest, ShouldCreateExcitatoryNeuron) {
    NeuronRepository nr = NeuronRepository();

    unsigned long id = nr.createExcitatoryNeuron();
    Neuron* neuron = nr.getNeuron(id);

    ASSERT_EQ(neuron->getType(), NeuronTypeExcitatory);
}

TEST(NeuronRepositoryTest, ShouldCreateInhibitoryNeuron) {
    NeuronRepository nr = NeuronRepository();

    unsigned long id = nr.createInhibitoryNeuron();
    Neuron* neuron = nr.getNeuron(id);

    ASSERT_EQ(neuron->getType(), NeuronTypeInhibitory);
}
