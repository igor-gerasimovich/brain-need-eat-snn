//
// Created by mgorunuch on 03.11.2019.
//

#ifndef BRAIN_NEED_EAT_SIGNAL_H
#define BRAIN_NEED_EAT_SIGNAL_H

class Signal {
private:
    int power;

public:
    explicit Signal(int newPower): power(newPower) {}

    int getPower() {
        return power;
    }
};

#endif //BRAIN_NEED_EAT_SIGNAL_H
