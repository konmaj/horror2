// Konrad Majewski, Mateusz Warzyński
#ifndef HORROR_MONSTER_H
#define HORROR_MONSTER_H

#include <vector>
#include <initializer_list>
#include "helper.h"

class Monster : public Living, public Attacking {
public:

    virtual std::string getName() const = 0;

protected:

    Monster(const HealthPoints, const AttackPower);
};

class Zombie : public Monster {
public:

    Zombie(const HealthPoints, const AttackPower);

    std::string getName() const;
};

class Vampire : public Monster {
public:

    Vampire(const HealthPoints, const AttackPower);

    std::string getName() const;
};

class Mummy : public Monster {
public:

    Mummy(const HealthPoints, const AttackPower);

    std::string getName() const;
};

class GroupOfMonsters : public Monster {
    std::vector<std::shared_ptr<Monster>> monsters_;

public:

    GroupOfMonsters(const std::vector<std::shared_ptr<Monster>> &monsters);

    GroupOfMonsters(const std::initializer_list<std::shared_ptr<Monster>> &monsters);

    HealthPoints getHealth();

    AttackPower getAttackPower();

    void takeDamage(AttackPower damage);

    std::string getName() const;
};

std::shared_ptr<Zombie> createZombie(HealthPoints health, AttackPower attackPower);

std::shared_ptr<Vampire> createVampire(HealthPoints health, AttackPower attackPower);

std::shared_ptr<Mummy> createMummy(HealthPoints health, AttackPower attackPower);

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(std::vector<std::shared_ptr<Monster>> &monsters);

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters);

#endif //HORROR_MONSTER_H
