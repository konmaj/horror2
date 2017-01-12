// Konrad Majewski, Mateusz Warzyński
#include <cassert>
#include "citizen.h"

Citizen::Citizen(HealthPoints healthPoints, Age age)
        : LivingOne(healthPoints), age_(age) {
    assert(age >= 0);
}

Age Citizen::getAge() const {
    return age_;
}

Adult::Adult(HealthPoints healthPoints, Age age)
        : Citizen(healthPoints, age) {
    assert(18 <= age && age <= 100);
}

Teenager::Teenager(HealthPoints healthPoints, Age age)
        : Citizen(healthPoints, age) {
    assert(11 <= age && age <= 17);
}

Sheriff::Sheriff(HealthPoints healthPoints, Age age, AttackPower attackPower)
        : Adult(healthPoints, age), AttackingOne(attackPower) {}

std::shared_ptr<Adult> createAdult(HealthPoints healthPoints, Age age) {
    return std::make_shared<Adult>(healthPoints, age);
}

std::shared_ptr<Teenager> createTeenager(HealthPoints healthPoints, Age age) {
    return std::make_shared<Teenager>(healthPoints, age);
}

std::shared_ptr<Sheriff> createSheriff(HealthPoints healthPoints, Age age, AttackPower attackPower) {
    return std::make_shared<Sheriff>(healthPoints, age, attackPower);
}