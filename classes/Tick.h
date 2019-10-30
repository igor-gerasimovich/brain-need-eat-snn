//
// Created by mgorunuch on 29.10.2019.
//

#ifndef BRAIN_NEED_EAT_TICK_H
#define BRAIN_NEED_EAT_TICK_H


class Tick {
private:
    unsigned long tick_number;

public:
    explicit Tick(unsigned long tickNumber): tick_number(tickNumber) {};

    unsigned long getTickNumber() {
        return tick_number;
    }
};


#endif //BRAIN_NEED_EAT_TICK_H
