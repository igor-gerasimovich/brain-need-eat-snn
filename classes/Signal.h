//
// Created by mgorunuch on 03.11.2019.
//

#ifndef BRAIN_NEED_EAT_SIGNAL_H
#define BRAIN_NEED_EAT_SIGNAL_H

class Signal {
private:
    int power;
    long unsigned fromId;

public:
    explicit Signal(int newPower, long unsigned newFromId): power(newPower), fromId(newFromId) {}

    int getPower() {
        return power;
    }

    long unsigned getFomId() {
        return fromId;
    }
};

#endif //BRAIN_NEED_EAT_SIGNAL_H
