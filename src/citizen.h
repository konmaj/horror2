// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_CITIZEN_H
#define HORROR_CITIZEN_H

#include <cstdint>
#include "helper.h"
#include "monster.h"

class Citizen : public Living {
public:

    virtual void attackedBy(std::shared_ptr<Monster> &monster);

    Age getAge() const;

protected:

    Citizen(const HealthPoints &healthPoints, const Age &age);

    Age age_;
};

class Adult : public Citizen {
public:

    Adult(const HealthPoints &healthPoints, const Age &age);
};

class Teenager : public Citizen {
public:

    Teenager(const HealthPoints &healthPoints, const Age &age);
};

class Sheriff : public Citizen, public Attacking {
public:

    Sheriff(const HealthPoints &healthPoints, const Age &age, const AttackPower &attackPower);

    void attackedBy(std::shared_ptr<Monster> &monster);
};

std::shared_ptr<Adult> createAdult(HealthPoints healthPoints, Age age);

std::shared_ptr<Teenager> createTeenager(HealthPoints healthPoints, Age age);

std::shared_ptr<Sheriff> createSheriff(HealthPoints healthPoints, Age age, AttackPower attackPower);

#endif //HORROR_CITIZEN_H