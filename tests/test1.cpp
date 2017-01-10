#include <cassert>
#include "helper.h"
#include "citizen.h"
#include "monster.h"
#include "smalltown.h"

int main() {
    SmallTown::Builder builder = SmallTown::Builder();

    Mummy mummy = Mummy(10, 1);
    Vampire vampire = Vampire(15, 4);

    GroupOfMonsters monsters = GroupOfMonsters({mummy, vampire});
    assert(monsters.getHealth() == 25);
    assert(monsters.getAttackPower() == 5);
    //assert(monsters.isAlive());

    Citizen first_citizen = Adult(1, 20);

    SmallTown smallTown = builder.monster(mummy).citizen(first_citizen).startTime(0).startTime(100).build();

    smallTown.tick(39); // no attack, 0 -> 39
    smallTown.tick(39); // attack, 39 -> 78
    smallTown.tick(39); // monster won, attack, 78 -> 117

    //assert(monsters.isAlive());
    //assert(!first_citizen.isAlive());

    return 0;
}
