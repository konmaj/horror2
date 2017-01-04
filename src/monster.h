// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_MONSTER_H
#define HORROR_MONSTER_H

#include <vector>
#include <initializer_list>
#include "helper.h"

class Monster : public Living, public Attacking {
public:

    Monster(HealthPoints healthPoints, AttackPower attackPower);
};

class Zombie : public Monster {
public:

    Zombie(HealthPoints healthPoints, AttackPower attackPower);
};

class Vampire : public Monster {
public:

    Vampire(HealthPoints healthPoints, AttackPower attackPower);
};

class Mummy : public Monster {
public:

    Mummy(HealthPoints healthPoints, AttackPower attackPower);
};

class GroupOfMonsters : public Monster {
    std::vector<Monster> monsters_;

public:

    GroupOfMonsters(std::vector<Monster> monsters);

    GroupOfMonsters(std::initializer_list<Monster> monsters);

    HealthPoints getHealth();

    AttackPower getAttackPower();

    void takeDamage(AttackPower damage);
};

Zombie createZombie(HealthPoints health, AttackPower attackPower);

Vampire createVampire(HealthPoints health, AttackPower attackPower);

Mummy createMummy(HealthPoints health, AttackPower attackPower);

GroupOfMonsters createGroupOfMonsters(std::vector<Monster> monsters);

GroupOfMonsters createGroupOfMonsters(std::initializer_list<Monster> monsters);

#endif //HORROR_MONSTER_H
