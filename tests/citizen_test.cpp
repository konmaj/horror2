#include "citizen.h"
#include <iostream>
#include <cassert>
int main() {

    auto citizen = createTeenager(100, 17);
    assert(citizen->getHealth() == 100);
    assert(citizen->getAge() == 17);

    auto citizen2 = createAdult(100, 19);
    assert(citizen2->getHealth() == 100);
    assert(citizen2->getAge() == 19);

    auto sheriff = createSheriff(100, 19, 20);
    assert(sheriff->getHealth() == 100);
    assert(sheriff->getAge() == 19);
    assert(sheriff->getAttackPower() == 20);

    sheriff->takeDamage(60);
    assert(sheriff->getHealth() == 40);
    sheriff->takeDamage(60);
    assert(sheriff->getHealth() == 0);
    sheriff->takeDamage(60);
    assert(sheriff->getHealth() == 0);

    auto mummy = createMummy(20, 20);

    citizen->attackedBy(mummy);
    assert(mummy->getHealth() == 20);

    sheriff = createSheriff(10000, 20, 10);

    sheriff->attackedBy(mummy);
    assert(mummy->getHealth() == 10);

    createGroupOfMonsters({createMummy(10, 10)});

    return 0;
}