#ifndef HORROR_CITIZEN_H
#define HORROR_CITIZEN_H

#include <cassert>

template<typename Age, typename HealthPoints, typename AttackPower>
class Citizen {
    HealthPoints healthPoints;
    Age age;

public:

    Citizen(HealthPoints healthPoints, Age age) : healthPoints(healthPoints), age(age) {}

    HealthPoints getHealth() { return healthPoints; }

    Age getAge() { return age; }

    void takeDamage(AttackPower damage) {
        healthPoints -= damage;
        if (healthPoints < 0)
            healthPoints = 0;
    }
};

template<typename Age, typename HealthPoints, typename AttackPower>
class Adult : public Citizen<Age, HealthPoints, AttackPower> {
public:

    Adult(HealthPoints healthPoints, Age age) : Citizen<Age, HealthPoints, AttackPower>(healthPoints, age) {
        assert(100 >= age && age >= 18);
    }
};

template<typename Age, typename HealthPoints, typename AttackPower>
class Teenager : public Citizen<Age, HealthPoints, AttackPower> {
public:

    Teenager(HealthPoints healthPoints, Age age) : Citizen<Age, HealthPoints, AttackPower>(healthPoints, age) {
        assert(17 >= age && age >= 11);
    }
};

template<typename Age, typename HealthPoints, typename AttackPower>
class Sheriff : public Adult<Age, HealthPoints, AttackPower> {
    AttackPower attackPower;

public:

    Sheriff(HealthPoints healthPoints, Age age, AttackPower attackPower) : Adult<Age, HealthPoints, AttackPower>(
            healthPoints, age), attackPower(attackPower) {}

    AttackPower getAttackPower() { return attackPower; }
};


#endif //HORROR_CITIZEN_H
