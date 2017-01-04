// Konrad Majewski, Mateusz Warzyński
#include "monster.h"

Monster::Monster(HealthPoints healthPoints, AttackPower attackPower)
        : Living(healthPoints), Attacking(attackPower) {}

Zombie(HealthPoints healthPoints, AttackPower attackPower)
        : Monster(healthPoints, attackPower) {}

Vampire(HealthPoints healthPoints, AttackPower attackPower)
        : Monster(healthPoints, attackPower) {}

Mummy(HealthPoints healthPoints, AttackPower attackPower)
        : Monster(healthPoints, attackPower) {}

Zombie createZombie(HealthPoints health, AttackPower attackPower) {
    return Zombie(health, attackPower);
}

Vampire createVampire(HealthPoints health, AttackPower attackPower) {
    return Vampire(health, attackPower);
}

Mummy createMummy(HealthPoints health, AttackPower attackPower) {
    return Mummy(health, attackPower);
}