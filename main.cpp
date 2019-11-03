#include "classes/factories/BrainFactory.h"

int main() {
    Brain brain = BrainFactory::createBrain();
    brain.proceed();
    return 0;
}