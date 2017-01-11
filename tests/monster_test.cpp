#include "monster.h"
#include <iostream>
#include <cassert>
int main() {
    auto m = createMummy(20, 10);
    assert(m->getHealth() == 20);
    assert(m->getAttackPower() == 10);

    auto v = createVampire(20, 10);
    assert(v->getHealth() == 20);
    assert(v->getAttackPower() == 10);

    auto z = createZombie(20, 10);
    assert(z->getHealth() == 20);
    assert(z->getAttackPower() == 10);

    auto g = createGroupOfMonsters({m, v, z});
    assert(g->getAttackPower() == 30);
    assert(g->getHealth() == 60);
    g->takeDamage(10);
    assert(g->getHealth() == 30);
    assert(g->getName() == "GroupOfMonsters");
    g->takeDamage(20);
    assert(g->getHealth() == 0);

    return 0;
}