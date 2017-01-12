// Konrad Majewski, Mateusz Warzyński
#include "monster.h"

Monster::Monster(HealthPoints healthPoints, AttackPower attackPower) : LivingOne(healthPoints),
                                                                       AttackingOne(attackPower) {}

Zombie::Zombie(HealthPoints healthPoints, AttackPower attackPower) : Monster(healthPoints, attackPower) {}

std::string Zombie::getName() const {
    return "Zombie";
}

Vampire::Vampire(HealthPoints healthPoints, AttackPower attackPower) : Monster(healthPoints, attackPower) {}

std::string Vampire::getName() const {
    return "Vampire";
}

Mummy::Mummy(HealthPoints healthPoints, AttackPower attackPower) : Monster(healthPoints, attackPower) {}

std::string Mummy::getName() const {
    return "Mummy";
}

GroupOfMonsters::GroupOfMonsters(const std::vector<std::shared_ptr<Monster>> &monsters) : monsters_(monsters) {}

GroupOfMonsters::GroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters) : monsters_(monsters) {}

HealthPoints GroupOfMonsters::getHealth() const {
    HealthPoints health = 0;
    for (auto &monster : monsters_)
        health += monster->getHealth();
    return health;
}

AttackPower GroupOfMonsters::getAttackPower() const {
    AttackPower power = 0;
    for (auto &monster : monsters_) {
        if (monster->getHealth() > 0)
            power += monster->getAttackPower();
    }
    return power;
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
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

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(const std::vector<std::shared_ptr<Monster>> &monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}

std::shared_ptr<GroupOfMonsters> createGroupOfMonsters(std::initializer_list<std::shared_ptr<Monster>> monsters) {
    return std::make_shared<GroupOfMonsters>(monsters);
}
