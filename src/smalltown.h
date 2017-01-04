// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_SMALLTOWN_H
#define HORROR_SMALLTOWN_H

#include <cstdint>
#include <tuple>
#include "citizen.h"
#include "monster.h"
#include "helper.h"

using Time = int32_t;

class SmallTown {
public:
    class Builder;

    std::tuple<std::string, HealthPoints, size_t> getStatus();

    void tick(Time timeStep);

private:
    Monster monster_;
    // TODO
    //GroupOfCitizens citizens_;
    Time time_;

    //SmallTown(Monster m, GroupOfCitizens c, Time t) : monster_(m), citizens_(c), time_(t) {}
};

#endif //HORROR_SMALLTOWN_H
