#include <cassert>
#include "helper.h"
#include "citizen.h"
#include "monster.h"
#include "smalltown.h"

int main() {
    SmallTown::Builder builder = SmallTown::Builder();

    auto mummy = createMummy(10, 1);
    auto vampire = createVampire(15, 4);

    GroupOfMonsters monsters = GroupOfMonsters({mummy, vampire});
    assert(monsters.getHealth() == 25);
    assert(monsters.getAttackPower() == 5);

    auto citizen = createAdult(1, 20);

     SmallTown smallTown = builder.monster(mummy).citizen(citizen).startTime(0).startTime(100).build();
     smallTown.tick(39); // no attack, 0 -> 39
     smallTown.tick(39); // attack, 39 -> 78
     smallTown.tick(39); // monster won, attack, 78 -> 117

//    assert(monsters.isAlive());
//    assert(!citizen.isAlive());

    return 0;
}
