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

// TODO
/*class GroupOfMonsters : public Monster {
  public:
    GroupOfMonsters(std::vector<Monster> monsters);
    GroupOfMonsters(std::initializer_list<Monster> monsters);

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
        for (auto monster : monsters_)
            monster.takeDamage(damage);
    }

  private:
    std::vector<Monster> monsters_;
};*/

Zombie createZombie(HealthPoints health, AttackPower attackPower);
Vampire createVampire(HealthPoints health, AttackPower attackPower);
Mummy createMummy(HealthPoints health, AttackPower attackPower);

// TODO
/*GroupOfMonsters createGroupOfMonsters(std::vector<Monster> monsters);
GroupOfMonsters cerateGroupOfMOnsters(std::initializer_list<Monster> monsters); */

#endif //HORROR_MONSTER_H
