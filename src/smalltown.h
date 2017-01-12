// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_SMALLTOWN_H
#define HORROR_SMALLTOWN_H

#include <cstdint>
#include <iostream>
#include <memory>
#include <set>
#include <vector>
#include "citizen.h"
#include "monster.h"

using Time = int32_t;

class AttackTime {
public:

    virtual bool shouldAttack(Time time) const = 0;

    virtual ~AttackTime() {}
};

class CustomAttackTime : public AttackTime {
    bool shouldAttack(Time time) const override;
};

class SmallTown {
public:

    class Builder;

    class Status;

    Status getStatus() const;

    void tick(Time timeStep);

private:

    SmallTown(const std::shared_ptr<MonsterComponent>& monster,
              const std::vector<std::shared_ptr<Citizen>>& citizens,
              Time startTime,
              Time maxTime,
              const std::shared_ptr<AttackTime>& attackTime);

    void checkState() const;

    size_t countAlives() const;

    std::shared_ptr<MonsterComponent> monster_;
    std::vector<std::shared_ptr<Citizen>> citizens_;
    Time time_;
    Time maxTime_;
    std::shared_ptr<AttackTime> attackTime_;
};

class SmallTown::Builder {
public:

    Builder();

    Builder& monster(const std::shared_ptr<MonsterComponent>& monster);

    Builder& citizen(const std::shared_ptr<Citizen>& citizen);

    Builder& startTime(Time time);

    Builder& maxTime(Time time);

    Builder& attackTime(const std::shared_ptr<AttackTime>& attackTime);

    SmallTown build();

private:

    std::set<std::shared_ptr<Citizen>> addedCitizens_;
    std::shared_ptr<MonsterComponent> monster_;
    std::vector<std::shared_ptr<Citizen>> citizens_;
    Time startTime_;
    Time maxTime_;
    std::shared_ptr<AttackTime> attackTime_;
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

void attack(const std::shared_ptr<MonsterComponent>& monster,
            const std::shared_ptr<Citizen>& citizen);

void attack(const std::shared_ptr<MonsterComponent>& monster,
            const std::shared_ptr<Sheriff>& sheriff);

#endif //HORROR_SMALLTOWN_H
