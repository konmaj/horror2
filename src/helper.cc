// Konrad Majewski, Mateusz Warzyński
#include <cassert>
#include "helper.h"

Living::Living(HealthPoints healthPoints) : healthPoints_(healthPoints) {
    assert(healthPoints >= 0);
}

HealthPoints Living::getHealth() {
    return healthPoints_;
}

void Living::takeDamage(AttackPower damage) {
    assert(damage >= 0);

    if (healthPoints_ < damage) {
        healthPoints_ -= damage;
    } else {
        healthPoints_ = 0;
    }
}

Attacking::Attacking(AttackPower attackPower) : attackPower_(attackPower) {
    assert(attackPower >= 0);
}

AttackPower Attacking::getAttackPower() {
    return attackPower_;
}