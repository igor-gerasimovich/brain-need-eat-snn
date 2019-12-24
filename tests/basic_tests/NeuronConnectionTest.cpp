//
// Created by mgorunuch on 24.12.2019.
//

#include "gtest/gtest.h"
#include "../../classes/factories/NeuronControllerFactory.h"
#include "../../classes/repositories/NeuronRepository.h"
#include "../../classes/NeuronConnection.h"

TEST(NeuronConnection, ShouldCanDisableModification) {
    NeuronRepository nr =  NeuronRepository();
    NeuronController nc1 = NeuronControllerFactory::createNeuronController(&nr);
    NeuronController nc2 = NeuronControllerFactory::createNeuronController(&nr);

    NeuronConnection neuronConnection = NeuronConnection(nc1.getId(), nc2.getId());

    Signal signal = Signal(200, nc1.getId());
    Signal signal2 = neuronConnection.modifySignal(signal);

    ASSERT_EQ(signal.getPower(), signal2.getPower());
}


TEST(NeuronConnection, ShouldCanEnableModification) {
    double multiplier = 2;
    NeuronRepository nr =  NeuronRepository();
    NeuronController nc1 = NeuronControllerFactory::createNeuronController(&nr);
    NeuronController nc2 = NeuronControllerFactory::createNeuronController(&nr);

    NeuronConnection neuronConnection = NeuronConnection(nc1.getId(), nc2.getId(), multiplier);

    Signal signal = Signal(200, nc1.getId());
    Signal signal2 = neuronConnection.modifySignal(signal);

    ASSERT_EQ((int)(signal.getPower() * multiplier), signal2.getPower());
}
