// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_SMALLTOWN_H
#define HORROR_SMALLTOWN_H

#include <cstdint>
#include <tuple>
#include "citizen.h"
#include "monster.h"
#include "helper.h"

class GroupOfCitizens {
public:

    GroupOfCitizens(std::vector<Citizen> citizens);

    bool isAlive();

    std::vector<Citizen> citizens_;
};

class SmallTown {
public:

    class Builder;

    std::tuple<std::string, HealthPoints, size_t> getStatus();

    void tick(Time timeStep);

private:

    const Monster monster_;
    const GroupOfCitizens citizens_;
    Time time_;
    Time max_time_;
    AttackTime attack_time_;

    SmallTown(Monster m, GroupOfCitizens c, Time t, Time mt, AttackTime at) : monster_(m), citizens_(c), time_(t),
                                                                              max_time_(mt), attack_time_(at) {}

    void performAttack();
};

class SmallTown::Builder {
public:

    Monster default_monster = Monster(0, 0);
    std::vector<Citizen> default_citizens;
    Time default_time = 0;
    Time default_max_time = 0;

    Builder();

    Builder &setMonster(Monster monster);

    Builder &setCitizens(std::vector<Citizen> citizens);

    Builder &addCitizen(Citizen citizen);

    Builder &setStartTime(Time time);

    Builder &setMaxTime(Time time);

    Builder &setAttackTime(AttackTime attackTime);

    SmallTown build();

private:

    Monster monster_;
    std::vector<Citizen> citizens_;
    Time start_time_;
    Time max_time_;
    AttackTime attack_time_;
};

#endif //HORROR_SMALLTOWN_H
