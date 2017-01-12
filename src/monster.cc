// Konrad Majewski, Mateusz Warzyński
#include "monster.h"

Monster::Monster(HealthPoints healthPoints, AttackPower attackPower)
        : LivingOne(healthPoints), AttackingOne(attackPower) {}

Zombie::Zombie(HealthPoints healthPoints, AttackPower attackPower)
        : Monster(healthPoints, attackPower) {}

std::string Zombie::getName() const {
    return "Zombie";
}

Vampire::Vampire(HealthPoints healthPoints, AttackPower attackPower)
        : Monster(healthPoints, attackPower) {}

std::string Vampire::getName() const {
    return "Vampire";
}

Mummy::Mummy(HealthPoints healthPoints, AttackPower attackPower)
        : Monster(healthPoints, attackPower) {}

std::string Mummy::getName() const {
    return "Mummy";
}

GroupOfMonsters::GroupOfMonsters(std::initializer_list<Monster> monsters) : monsters_(monsters) {}

GroupOfMonsters::GroupOfMonsters(std::vector<Monster> monsters) : monsters_(monsters) {}

HealthPoints GroupOfMonsters::getHealth() const {
    HealthPoints health = 0;
    for (auto &monster : monsters_)
        health += monster.getHealth();
    return health;
}

AttackPower GroupOfMonsters::getAttackPower()  const {
    AttackPower power = 0;
    for (auto &monster : monsters_) {
        if (monster.getHealth() > 0)
            power += monster.getAttackPower();
    }
    return power;
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
    for (auto &monster : monsters_)
        monster.takeDamage(damage);
}

std::string GroupOfMonsters::getName() const {
    return "GroupOfMonsters";
}

Zombie createZombie(HealthPoints health, AttackPower attackPower) {
    return Zombie(health, attackPower);
}

Vampire createVampire(HealthPoints health, AttackPower attackPower) {
    return Vampire(health, attackPower);
}

Mummy createMummy(HealthPoints health, AttackPower attackPower) {
    return Mummy(health, attackPower);
}

GroupOfMonsters createGroupOfMonsters(std::initializer_list<Monster> monsters) {
    return GroupOfMonsters(monsters);
}

GroupOfMonsters createGroupOfMonsters(std::vector<Monster> monsters) {
    return GroupOfMonsters(monsters);
}
