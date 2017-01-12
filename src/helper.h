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

class LivingInterface {
public:

    virtual HealthPoints getHealth() const = 0;

    virtual void takeDamage(AttackPower damage) = 0;

    virtual ~LivingInterface() {}
};

class LivingOne : public virtual LivingInterface {
public:

    LivingOne(HealthPoints healthPoints);

    HealthPoints getHealth() const override;

    void takeDamage(AttackPower damage) override;

    virtual ~LivingOne() {}

private:

    HealthPoints healthPoints_;
};

class AttackingInterface {
public:

    virtual AttackPower getAttackPower() const = 0;

    virtual ~AttackingInterface() {}
};

class AttackingOne : public virtual AttackingInterface {
public:

    AttackingOne(AttackPower attackPower);

    AttackPower getAttackPower() const override;

    virtual ~AttackingOne() {}

private:

    AttackPower attackPower_;
};

#endif //HORROR_HELPER_H