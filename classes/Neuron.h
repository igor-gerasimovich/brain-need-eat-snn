//
// Created by mgorunuch on 29.10.2019.
//

#ifndef BRAIN_NEED_EAT_NEURON_H
#define BRAIN_NEED_EAT_NEURON_H


class Neuron {
private:
    unsigned long id = 0;
    int current_potential = 0;
    unsigned long disabled_to_tick = 0;
    unsigned long repository_place = 0;

public:
    explicit Neuron() = default;

    unsigned long getId() {
        return id;
    }
    void setId(unsigned long newId) {
        id = newId;
    }

    int getCurrentPotential() {
        return current_potential;
    }
    void setCurrentPotential(int new_potential) {
        current_potential = new_potential;
    }

    unsigned long getDisabledToTick() {
        return disabled_to_tick;
    }
    void setDisabledToTick(unsigned long tick_num) {
        disabled_to_tick = tick_num;
    }

    void setRepositoryPlace(unsigned long place_num) {
        repository_place = place_num;
    }
    unsigned long getRepositoryPlace() {
        return repository_place;
    }
};


#endif //BRAIN_NEED_EAT_NEURON_H
