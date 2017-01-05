// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_CITIZEN_H
#define HORROR_CITIZEN_H

#include <cstdint>
#include "helper.h"

class Citizen : public Living, public Attacking {
public:

    Citizen(Age age, HealthPoints healthPoints, AttackPower attackPower);

    Age getAge();

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

class Sheriff : public Citizen {
public:

    Sheriff(HealthPoints healthPoints, Age age, AttackPower attackPower);
};

Adult createAdult(HealthPoints healthPoints, Age age);

Teenager createTeenager(HealthPoints healthPoints, Age age);

Sheriff createSheriff(HealthPoints healthPoints, Age age, AttackPower attackPower);

#endif //HORROR_CITIZEN_H