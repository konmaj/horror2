﻿// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_SMALLTOWN_H
#define HORROR_SMALLTOWN_H

#include <iostream>
#include <cstdint>
#include <tuple>
#include "citizen.h"
#include "monster.h"
#include "helper.h"

class GroupOfCitizens : public Citizen {
public:

    GroupOfCitizens(std::vector<std::shared_ptr<Citizen>> &citizens);

    HealthPoints getHealth();

    void attackedBy(std::shared_ptr<Monster> &monster);

private:

    std::vector<std::shared_ptr<Citizen>> &citizens;
};

class AttackTime {
public:

    static bool shouldAttack(Time time);
};

class SmallTown {
public:

    class Builder;

    class Status;

    Status getStatus();

    void tick(Time timeStep);

private:

    std::shared_ptr<Monster> &monster_;
    std::shared_ptr<GroupOfCitizens> &citizens_;
    Time time_;
    Time max_time_;
    AttackTime attack_time_;

    SmallTown(std::shared_ptr<Monster> &m, std::shared_ptr<GroupOfCitizens> &c, Time t, Time mt, AttackTime at);

    void checkState();
};

class SmallTown::Builder {
public:

    Builder &monster(const std::shared_ptr<Monster> &monster);

    Builder &citizen(const std::shared_ptr<Citizen> &citizen);

    Builder &startTime(const Time time);

    Builder &maxTime(const Time time);

    Builder &attackTime(const AttackTime attackTime);

    SmallTown build();

private:

    std::shared_ptr<Monster> monster_;
    std::vector<std::shared_ptr<Citizen>> citizens_;
    Time start_time_;
    Time max_time_;
    AttackTime attack_time_;
};

class SmallTown::Status {
public:

    Status(const std::string& monsterName, const HealthPoints& healthPoints, const size_t& aliveCount);

    std::string getMonsterName() const;

    HealthPoints getMonsterHealth() const;

    size_t getAliveCitizens() const;

private:

    std::string monsterName_;
    HealthPoints monsterHealth_;
    size_t aliveCount_;
};

#endif //HORROR_SMALLTOWN_H
