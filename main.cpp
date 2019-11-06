#include "classes/factories/BrainFactory.h"
#include "classes/Drawer.h"

int main() {
    Brain brain = BrainFactory::createBrain();

    brain.createStructure(3, 4);

    brain.proceed();

    auto testNeuron = brain.ncr.controllers[0].getNeuron();

    Drawer::drawNeuronSpikesHistory(testNeuron);
    Drawer::drawNeuronPowerHistory(testNeuron);

    return 0;
}