// Konrad Majewski, Mateusz Warzyński
#include "monster.h"

Monster::Monster(const HealthPoints &healthPoints, const AttackPower &attackPower) : Living(healthPoints),
                                                                                     Attacking(attackPower) {}

Zombie::Zombie(const HealthPoints &healthPoints, const AttackPower &attackPower) : Monster(healthPoints, attackPower) {}

std::string Zombie::getName() const {
    return "Zombie";
}

Vampire::Vampire(const HealthPoints &healthPoints, const AttackPower &attackPower) : Monster(healthPoints,
                                                                                             attackPower) {}

std::string Vampire::getName() const {
    return "Vampire";
}

Mummy::Mummy(const HealthPoints &healthPoints, const AttackPower &attackPower) : Monster(healthPoints, attackPower) {}

std::string Mummy::getName() const {
    return "Mummy";
}

GroupOfMonsters::GroupOfMonsters(const std::initializer_list<std::shared_ptr<Monster>> &monsters) : Monster(0, 0),
                                                                                                    monsters_(
                                                                                                            monsters) {
    healthPoints_ = getHealth();
    attackPower_ = getAttackPower();
}

GroupOfMonsters::GroupOfMonsters(const std::vector<std::shared_ptr<Monster>> &monsters) : Monster(0, 0),
                                                                                          monsters_(monsters) {
    healthPoints_ = getHealth();
    attackPower_ = getAttackPower();
}

HealthPoints GroupOfMonsters::getHealth() {
    HealthPoints health = 0;
    for (auto &monster : monsters_)
        health += monster->getHealth();
    return health;
}

AttackPower GroupOfMonsters::getAttackPower() {
    AttackPower power = 0;
    for (auto &monster : monsters_) {
        if (monster->isAlive())
            power += monster->getAttackPower();
    }
    return power;
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
    healthPoints_ = 0;
    for (auto &monster : monsters_)
        monster->takeDamage(damage);
}

std::string GroupOfMonsters::getName() const {
    return "GroupOfMonsters";
}

std::shared_ptr<Zombie> createZombie(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Zombie>(health, attackPower);
}

std::shared_ptr<Vampire> createVampire(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Vampire>(health, attackPower);
}

std::shared_ptr<Mummy> createMummy(HealthPoints health, AttackPower attackPower) {
    return std::make_shared<Mummy>(health, attackPower);
}

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(std::vector<std::shared_ptr<Monster>> &monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}