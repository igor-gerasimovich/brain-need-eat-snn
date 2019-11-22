//
// Created by mgorunuch on 29.10.2019.
//

#ifndef BRAIN_NEED_EAT_NEURON_H
#define BRAIN_NEED_EAT_NEURON_H

#include "vector"
#include "iostream"

class Neuron {
private:
    unsigned long id = 0;
    int current_potential = 0;
    unsigned long disabled_to_tick = 0;
    unsigned long repository_place = 0;

    std::vector<bool> spikesHistory{};
    std::vector<int> powerHistory{};

public:
    explicit Neuron() {
        spikesHistory.reserve(100);
        powerHistory.reserve(100);
    };

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
        if (id == 0) {
            std::cout << "New potential: " << new_potential << std::endl;
        }
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


    // Statistics
    void addToSpikeHistory(bool hasSpike) {
        spikesHistory.push_back(hasSpike);
    }
    std::vector<bool> getSpikesHistory() {
        return spikesHistory;
    }

    void addToPowerHistory(int hasSpike) {
        powerHistory.push_back(hasSpike);
    }
    std::vector<int> getPowerHistory() {
        return powerHistory;
    }
};


#endif //BRAIN_NEED_EAT_NEURON_H
