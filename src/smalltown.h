#ifndef HORROR_SMALLTOWN_H
#define HORROR_SMALLTOWN_H

#include <tuple>
#include "citizen.h"
#include "monster.h"
#include "helper.h"

template<typename Monster, typename Time>
class SmallTown {
public:

    class Builder;

private:

    Monster monster;
    GroupOfCitizens citizens;
    Time time;

    SmallTown(Monster m, GroupOfCitizens c, Time t) : monster(m), citizens(c), time(t) {}

public:

    std::tuple<std::string, decltype(monster.getHealth()), size_t> getStatus() {
        return std::make_tuple(monster.getName(), monster.getHealth(), citizens.getAlive());
    }

    void tick(Time timeStep);
};


template<typename M, typename Time>
class SmallTown<M, Time>::Builder {
public:

    SmallTown build();
};

#endif //HORROR_SMALLTOWN_H
