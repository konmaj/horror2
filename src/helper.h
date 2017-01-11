﻿// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_HELPER_H
#define HORROR_HELPER_H

#include <cstdint>
#include <cstddef>
#include <memory>
#include <vector>

using Age = int32_t;
using HealthPoints = int32_t;
using AttackPower = int32_t;
using Time = int32_t;

class Living {
public:

    Living(HealthPoints healthPoints);

    HealthPoints getHealth();

    bool isAlive();

    void takeDamage(AttackPower damage);

protected:

    HealthPoints healthPoints_;
};

class Attacking {
public:

    Attacking(AttackPower attackPower);

    AttackPower getAttackPower();

protected:

    AttackPower attackPower_;
};

#endif //HORROR_HELPER_H