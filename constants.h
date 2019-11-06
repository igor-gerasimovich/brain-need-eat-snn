//
// Created by mgorunuch on 30.10.2019.
//

#ifndef BRAIN_NEED_EAT_CONSTANTS_H
#define BRAIN_NEED_EAT_CONSTANTS_H

int const DEFAULT_NEURON_SPIKE_SIGNAL_POWER = 100;
int const MAX_NEURONS_COUNT = 5000;
int const BASE_NEURON_POTENTIAL = 200;
int const MIN_NEURON_POTENTIAL_LEVEL = -600;
int const MAX_NEURON_POTENTIAL_LEVEL = 600;
unsigned long const MAX_CONNECTIONS_PER_NEURON = 500;

// In future must be recalculated for each neuron
int const SPIKE_GENERATION_LEVEL = 500;
unsigned long const SLEEP_AFTER_SPIKE_TICKS_COUNT = 2;
int const POWER_LOSS_PER_TICK = 100;

#endif //BRAIN_NEED_EAT_CONSTANTS_H
