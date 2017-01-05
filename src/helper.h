// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_HELPER_H
#define HORROR_HELPER_H

#include <cstdint>
#include <cstddef>
#include <vector>

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


// TODO: we should rename AttackTime to something better
class AttackTime {
public:

    virtual bool shouldAttack(Time time) = 0;
};

class HorrorAttackTime : public AttackTime {
public:

    HorrorAttackTime() {}

    bool shouldAttack(Time time);
};

#endif //HORROR_HELPER_H
