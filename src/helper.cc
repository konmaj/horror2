// Konrad Majewski, Mateusz Warzyński
#include <algorithm>
#include <cassert>
#include "helper.h"

LivingOne::LivingOne(HealthPoints healthPoints) : healthPoints_(healthPoints) {
    assert(healthPoints >= 0);
}

HealthPoints LivingOne::getHealth() const {
    return healthPoints_;
}

void LivingOne::takeDamage(AttackPower damage) {
    assert(damage >= 0);
    healthPoints_ -= std::min(healthPoints_, static_cast<HealthPoints>(damage));
}

AttackingOne::AttackingOne(AttackPower attackPower) : attackPower_(attackPower) {
    assert(attackPower >= 0);
}

AttackPower AttackingOne::getAttackPower() const {
    return attackPower_;
}
