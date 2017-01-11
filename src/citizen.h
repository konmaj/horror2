// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_CITIZEN_H
#define HORROR_CITIZEN_H

#include <cstdint>
#include "helper.h"
#include "monster.h"

class Citizen : public Living {
public:

    Citizen(HealthPoints healthPoints, Age age);

    virtual void attackedBy(std::shared_ptr<Monster> &monster);

    Age getAge() const;

private:

    Age age_;
};

class Adult : public Citizen {
public:

    Adult(HealthPoints healthPoints, Age age);
};

class Teenager : public Citizen {
public:

    Teenager(HealthPoints healthPoints, Age age);
};

class Sheriff : public Citizen, public Attacking {
public:

    Sheriff(HealthPoints healthPoints, Age age, AttackPower attackPower);

    void attackedBy(std::shared_ptr<Monster> &monster);
};

std::shared_ptr<Adult> createAdult(HealthPoints healthPoints, Age age);

std::shared_ptr<Teenager> createTeenager(HealthPoints healthPoints, Age age);

std::shared_ptr<Sheriff> createSheriff(HealthPoints healthPoints, Age age, AttackPower attackPower);

#endif //HORROR_CITIZEN_H