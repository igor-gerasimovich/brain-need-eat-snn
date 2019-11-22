//
// Created by mgorunuch on 06.11.2019.
//

#ifndef BRAIN_NEED_EAT_DRAWER_H
#define BRAIN_NEED_EAT_DRAWER_H

#include "Neuron.h"
#include "../matplotlibcpp.h"
#include "vector"

class Drawer {
public:
    static void drawNeuronSpikesHistory(Neuron* neuron) {
        auto sh = neuron->getSpikesHistory();

        std::vector<int> intArr{};
        intArr.reserve(100);
        for (const bool s: sh) {
            if (s) {
                intArr.push_back(1);
            } else {
                intArr.push_back(0);
            }
        }

        matplotlibcpp::plot(intArr);
        matplotlibcpp::show();
    }

    static void drawNeuronPowerHistory(Neuron* neuron) {
        auto ph = neuron->getPowerHistory();

        matplotlibcpp::plot(ph);
        matplotlibcpp::title(std::to_string(neuron->getId()));
        matplotlibcpp::show();
    }
};

#endif //BRAIN_NEED_EAT_DRAWER_H
