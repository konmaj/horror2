// Konrad Majewski, Mateusz Warzyński
#include "monster.h"

Monster::Monster(HealthPoints healthPoints, AttackPower attackPower) : Living(healthPoints), Attacking(attackPower) {}

Zombie::Zombie(HealthPoints healthPoints, AttackPower attackPower) : Monster(healthPoints, attackPower) {}

Vampire::Vampire(HealthPoints healthPoints, AttackPower attackPower) : Monster(healthPoints, attackPower) {}

Mummy::Mummy(HealthPoints healthPoints, AttackPower attackPower) : Monster(healthPoints, attackPower) {}

GroupOfMonsters::GroupOfMonsters(std::initializer_list<Monster> monsters) : monsters_(monsters) {}

GroupOfMonsters::GroupOfMonsters(std::vector<Monster> monsters) : monsters_(monsters) {}

HealthPoints GroupOfMonsters::getHealth() {
    HealthPoints health;
    for (auto monster : monsters_)
        health += monster.getHealth();
    return health;
}

AttackPower GroupOfMonsters::getAttackPower()  {
    AttackPower power;
    for (auto monster : monsters_)
        power += monster.getAttackPower();
    return power;
}

void GroupOfMonsters::takeDamage(AttackPower damage) {
    for (auto monster : monsters_)
        monster.takeDamage(damage);
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