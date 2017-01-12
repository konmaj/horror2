// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_SMALLTOWN_H
#define HORROR_SMALLTOWN_H

#include <iostream>
#include <cstdint>
#include <tuple>
#include "citizen.h"
#include "monster.h"
#include "helper.h"

class GroupOfCitizens {
public:

    GroupOfCitizens(std::vector<Citizen> citizens);

    HealthPoints getHealth();

    AttackPower getAttackPower();

    void takeDamage(AttackPower damage);

    std::vector<Citizen> citizens;
};

class AttackTime {
public:

    virtual bool shouldAttack(Time time) = 0;
};

class CustomAttackTime : public AttackTime {
    bool shouldAttack(Time time);
};

class SmallTown {
public:

    class Builder;

    class Status;

    Status getStatus();

    void tick(Time timeStep);

private:

    SmallTown(const Monster& monster, const GroupOfCitizens& groupOfCitizens, Time start, Time mt, AttackTime at) : 
        monster_(m), citizens_(c), time_(t), max_time_(mt), attack_time_(at) {}

    void checkState();

    MonsterComponent monster_;
    GroupOfCitizens citizens_;
    Time time_;
    Time maxTime_;
    AttackTime attackTime_;
};

class SmallTown::Builder {
public:

    Builder();

    Builder &monster(MonsterComponent monster);

    Builder &citizens(std::vector<Citizen> citizens);

    Builder &citizen(Citizen citizen);

    Builder &startTime(Time time);

    Builder &maxTime(Time time);

    Builder &attackTime(AttackTime attackTime);

    SmallTown build();

private:

    MonsterComponent monster_;
    std::vector<Citizen> citizens_;
    Time startTime_;
    Time maxTime_;
    AttackTime attackTime_;
};

class SmallTown::Status {
public:

    Status(const std::string& monsterName, HealthPoints monsterHealth, 
           size_t aliveCount);

    std::string getMonsterName() const;

    HealthPoints getMonsterHealth() const;

    size_t getAliveCitizens() const;

private:

    std::string monsterName_;
    HealthPoints monsterHealth_;
    size_t aliveCount_;
};

void attack(MonsterComponent& monster, Citizen& citizen);

void attack(MonsterComponent& monster, Sheriff& sheriff);

#endif //HORROR_SMALLTOWN_H
