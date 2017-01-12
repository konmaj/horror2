// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_MONSTER_H
#define HORROR_MONSTER_H

#include <string>
#include <initializer_list>
#include <vector>
#include "helper.h"

class MonsterComponent : public virtual LivingInterface, 
                         public virtual AttackingInterface {
public:

    virtual std::string getName() const = 0;
};

class Monster : public MonsterComponent, public LivingOne, public AttackingOne {
public:

    Monster(HealthPoints healthPoints, AttackPower attackPower);

    std::string getName() const override {
        return "Monster";
    }
};

class Zombie : public Monster {
public:

    Zombie(HealthPoints healthPoints, AttackPower attackPower);

    std::string getName() const override;
};

class Vampire : public Monster {
public:

    Vampire(HealthPoints healthPoints, AttackPower attackPower);

    std::string getName() const override;
};

class Mummy : public Monster {
public:

    Mummy(HealthPoints healthPoints, AttackPower attackPower);

    std::string getName() const override;
};

class GroupOfMonsters : public MonsterComponent {
public:

    GroupOfMonsters(const std::vector<Monster>& monsters);

    GroupOfMonsters(std::initializer_list<Monster> monsters);

    HealthPoints getHealth() const override;

    AttackPower getAttackPower() const override;

    void takeDamage(AttackPower damage) override;

    std::string getName() const override;

private:

    std::vector<Monster> monsters_;
};

Zombie createZombie(HealthPoints health, AttackPower attackPower);

Vampire createVampire(HealthPoints health, AttackPower attackPower);

Mummy createMummy(HealthPoints health, AttackPower attackPower);

GroupOfMonsters createGroupOfMonsters(const std::vector<Monster>& monsters);

GroupOfMonsters createGroupOfMonsters(std::initializer_list<Monster> monsters);

#endif //HORROR_MONSTER_H
