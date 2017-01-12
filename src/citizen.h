// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_CITIZEN_H
#define HORROR_CITIZEN_H

#include <cstdint>
#include <memory>
#include "helper.h"

class Citizen : public LivingOne {
public:

    Citizen(HealthPoints healthPoints, Age age);

    Age getAge() const;

    virtual ~Citizen() {}

private:

    Age age_;
};

class Adult : public Citizen {
public:

    Adult(HealthPoints healthPoints, Age age);

    virtual ~Adult() {}
};

class Teenager : public Citizen {
public:

    Teenager(HealthPoints healthPoints, Age age);
};

class Sheriff : public Adult, public AttackingOne {
public:

    Sheriff(HealthPoints healthPoints, Age age, AttackPower attackPower);
};

std::shared_ptr<Adult> createAdult(HealthPoints healthPoints, Age age);

std::shared_ptr<Teenager> createTeenager(HealthPoints healthPoints, Age age);

std::shared_ptr<Sheriff>
createSheriff(HealthPoints healthPoints, Age age, AttackPower attackPower);

#endif //HORROR_CITIZEN_H