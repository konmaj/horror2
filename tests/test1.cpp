#include <cassert>
#include "helper.h"
#include "citizen.h"
#include "monster.h"
#include "smalltown.h"

int main() {
    SmallTown::Builder builder = SmallTown::Builder();

    Mummy mummy = Mummy(10, 1);
    Citizen first_citizen = Adult(1, 20);

    SmallTown smallTown = builder.setMonster(mummy).addCitizen(first_citizen).setStartTime(0).setMaxTime(100).build();

    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);
    smallTown.tick(1);

    return 0;
}
