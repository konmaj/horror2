// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_HELPER_H
#define HORROR_HELPER_H

#include <cstdint>

using HealthPoints = int32_t;
using AttackPower = int32_t;

class Living {
public:

    Living(HealthPoints healthPoints);

    HealthPoints getHealth();

    void takeDamage(AttackPower damage);

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

// This may be useful, but I am not sure, which header file this class should be in.
/*class GroupOfCitizens {
  public:
    GroupOfCitizens();
    size_t getAlive();
};*/

#endif //HORROR_HELPER_H
