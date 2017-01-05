// Konrad Majewski, Mateusz Warzyński
#include <cassert>
#include "citizen.h"

Citizen::Citizen(Age age, HealthPoints healthPoints, AttackPower attackPower)
        : Living(healthPoints), Attacking(attackPower), age_(age) {}

Age Citizen::getAge() {
    return age_;
}

Adult::Adult(HealthPoints healthPoints, Age age)
        : Citizen(age, healthPoints, 0) {
    assert(18 <= age && age <= 100);
}

Teenager::Teenager(HealthPoints healthPoints, Age age)
        : Citizen(age, healthPoints, 0) {
    assert(11 <= age && age <= 17);
}

Sheriff::Sheriff(HealthPoints healthPoints, Age age, AttackPower attackPower)
        : Citizen(healthPoints, age, attackPower) {}

Adult createAdult(HealthPoints healthPoints, Age age) {
    return Adult(healthPoints, age);
}

Teenager createTeenager(HealthPoints healthPoints, Age age) {
    return Teenager(healthPoints, age);
}

Sheriff createSheriff(HealthPoints healthPoints, Age age, AttackPower attackPower) {
    return Sheriff(healthPoints, age, attackPower);
}