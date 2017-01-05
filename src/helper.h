// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_HELPER_H
#define HORROR_HELPER_H

#include <cstdint>
#include <cstddef>
#include <vector>

using Age = int32_t;
using HealthPoints = int32_t;
using AttackPower = int32_t;
using Time = int32_t;

class Living {
public:

    Living(HealthPoints healthPoints);

    HealthPoints getHealth();

    void takeDamage(AttackPower damage);

    bool isAlive();

private:

    HealthPoints healthPoints_;
};

class Attacking {
public:

    Attacking(AttackPower attackPower);

    AttackPower getAttackPower();

private:

    AttackPower attackPower_;
};

class AttackTime {
public:

    bool shouldAttack(Time time);
};

#endif //HORROR_HELPER_H