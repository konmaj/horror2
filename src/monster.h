#ifndef HORROR_MONSTER_H
#define HORROR_MONSTER_H

#include <vector>

template<typename HealthPoints, typename AttackPower>
class Monster {
    HealthPoints healthPoints;
    AttackPower attackPower;

public:

    Monster(HealthPoints healthPoints, AttackPower attackPower) : healthPoints(healthPoints),
                                                                  attackPower(attackPower) {};

    HealthPoints getHealth() { return healthPoints; }

    AttackPower getAttackPower() { return attackPower; }

    void takeDamage(AttackPower damage) {
        healthPoints -= damage;
        if (healthPoints < 0)
            healthPoints = 0;
    }
};

template<typename HealthPoints, typename AttackPower>
class Zombie : public Monster<HealthPoints, AttackPower> {
public:

    Zombie(HealthPoints healthPoints, AttackPower attackPower) : Monster<HealthPoints, AttackPower>(healthPoints,
                                                                                                    attackPower) {}
};

template<typename HealthPoints, typename AttackPower>
class Vampire : public Monster<HealthPoints, AttackPower> {
public:

    Vampire(HealthPoints healthPoints, AttackPower attackPower) : Monster<HealthPoints, AttackPower>(healthPoints,
                                                                                                     attackPower) {}
};

template<typename HealthPoints, typename AttackPower>
class Mummy : public Monster<HealthPoints, AttackPower> {
public:

    Mummy(HealthPoints healthPoints, AttackPower attackPower) : Monster<HealthPoints, AttackPower>(healthPoints,
                                                                                                   attackPower) {}
};

template<typename HealthPoints, typename AttackPower>
class GroupOfMonsters {
    std::vector<Monster<HealthPoints, AttackPower>> monsters;

public:

    GroupOfMonsters(std::vector<Monster<HealthPoints, AttackPower>> monsters) : monsters(monsters) {}

    HealthPoints getHealth() {
        HealthPoints health;
        for (auto monster : monsters)
            health += monster.getHealth();
        return health;
    }

    AttackPower getAttackPower() {
        AttackPower power;
        for (auto monster : monsters)
            power += monster.getAttackPower();
        return power;
    }

    void takeDamage(AttackPower damage) {
        for (auto monster : monsters)
            monster.takeDamage(damage);
    }
};

// TODO: Dodatkowo powinny istnieć funkcje fabrykujące dla Zombie, Vampire, Mummy, GroupOfMonsters z sygnaturami pasującymi do przykładu.

#endif //HORROR_MONSTER_H
