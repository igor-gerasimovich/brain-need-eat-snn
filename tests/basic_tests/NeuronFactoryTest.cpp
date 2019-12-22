//
// Created by mgorunuch on 22.12.2019.
//

#include "gtest/gtest.h"
#include "../../classes/Neuron.h"
#include "../../classes/factories/NeuronFactory.h"

TEST(NeuronGenerationFactory, ShouldCreateBasicNeuron) {
    Neuron neuron = NeuronFactory::createNeuron();

    EXPECT_EQ(neuron.getType(), NeuronTypeBasic);
}

TEST(NeuronGenerationFactory, ShouldCreateExcitatoryNeuron) {
    ExcitatoryNeuron neuron = NeuronFactory::createExcitatoryNeuron();

    EXPECT_EQ(neuron.getType(), NeuronTypeExcitatory);
}

TEST(NeuronGenerationFactory, ShouldCreateInhibitoryNeuron) {
    InhibitoryNeuron neuron = NeuronFactory::createInhibitoryNeuron();

    EXPECT_EQ(neuron.getType(), NeuronTypeInhibitory);
}