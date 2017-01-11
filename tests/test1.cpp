#include <cassert>
#include "helper.h"
#include "citizen.h"
#include "monster.h"
#include "smalltown.h"
#include <memory>
#include <vector>

void function(std::initializer_list<std::shared_ptr<Citizen>>) {
    return;
}

int main() {

    auto s = createSheriff(100, 35, 20);

    auto smallTown = SmallTown::Builder()
            .monster(createZombie(100, 1))
            .startTime(3)
            .maxTime(27)
            .citizen(s)
            .citizen(s)
            .citizen(createTeenager(50, 14))
            .build();

    smallTown.tick(0);

    assert(s->getHealth() == 99);
    assert(smallTown.getStatus().getMonsterHealth() == 80);
    assert(smallTown.getStatus().getAliveCitizens() == 2);
    //SmallTown::Builder builder = SmallTown::Builder();

    //Mummy mummy = Mummy(10, 1);
    //Vampire vampire = Vampire(15, 4);

    //GroupOfMonsters monsters = GroupOfMonsters({mummy, vampire});
    //assert(monsters.getHealth() == 25);
    //assert(monsters.getAttackPower() == 5);
    //assert(monsters.isAlive());

    //Citizen first_citizen = Adult(1, 20);

    //SmallTown smallTown = builder.monster(mummy).citizen(first_citizen).startTime(0).maxTime(100).build();

    //smallTown.tick(39); // no attack, 0 -> 39
    //smallTown.tick(39); // attack, 39 -> 78
    //smallTown.tick(39); // monster won, attack, 78 -> 117

    //assert(monsters.isAlive());
    //assert(!first_citizen.isAlive());

    return 0;
}