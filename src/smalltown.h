// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_SMALLTOWN_H
#define HORROR_SMALLTOWN_H

#include <iostream>
#include <cstdint>
#include <tuple>
#include "citizen.h"
#include "monster.h"
#include "helper.h"

const std::string CITIZENS_WON = "CITIZENS WON";
const std::string MONSTER_WON = "MONSTER WON";
const std::string DRAW = "DRAW";

class GroupOfCitizens {
public:

    GroupOfCitizens(std::vector<Citizen> citizens);

    bool isAlive();

    AttackPower getAttackPower();

    void takeDamage(AttackPower damage);

    std::vector<Citizen> citizens;
};

class SmallTown {
public:

    class Builder;

    std::tuple<std::string, HealthPoints, size_t> getStatus();

    void tick(Time timeStep);

private:

    Monster monster_;
    GroupOfCitizens citizens_;
    Time time_;
    Time max_time_;
    AttackTime attack_time_;

    SmallTown(Monster m, GroupOfCitizens c, Time t, Time mt, AttackTime at) : monster_(m), citizens_(c), time_(t),
                                                                              max_time_(mt), attack_time_(at) {}

    void checkState();
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
