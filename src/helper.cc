// Konrad Majewski, Mateusz Warzyński
#include <algorithm>
#include <cassert>
#include "helper.h"

Living::Living(HealthPoints healthPoints) : healthPoints_(healthPoints) {
    assert(healthPoints >= 0);
}

HealthPoints Living::getHealth() const {
    return healthPoints_;
}

void Living::takeDamage(AttackPower damage) {
    assert(damage >= 0);
    healthPoints_ -= std::min(healthPoints_, static_cast<HealthPoints>(damage));
}

bool Living::isAlive() {
    return healthPoints_ > 0;
}

Attacking::Attacking(AttackPower attackPower) : attackPower_(attackPower) {
    assert(attackPower >= 0);
}

AttackPower Attacking::getAttackPower() const {
    return attackPower_;
}

bool AttackTime::shouldAttack(Time time) {
    return time % 3 == 0 && time % 13 == 0 && time % 7 != 0;
}