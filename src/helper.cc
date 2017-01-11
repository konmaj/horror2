// Konrad Majewski, Mateusz Warzyński
#include <algorithm>
#include <cassert>
#include "helper.h"

Living::Living(const HealthPoints &healthPoints) : healthPoints_(healthPoints) {
    assert(healthPoints >= 0);
}

HealthPoints Living::getHealth() {
    return healthPoints_;
}

void Living::takeDamage(AttackPower damage) {
    assert(damage >= 0);
    healthPoints_ -= std::min(healthPoints_, static_cast<HealthPoints>(damage));
}

bool Living::isAlive() {
    return getHealth() > 0;
}

Attacking::Attacking(const AttackPower &attackPower) : attackPower_(attackPower) {
    assert(attackPower >= 0);
}

AttackPower Attacking::getAttackPower() {
    return attackPower_;
}
