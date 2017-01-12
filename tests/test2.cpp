#include "helper.h"
#include "citizen.h"
#include "monster.h"
#include "smalltown.h"
#include <iostream>
#include <cassert>


int main() {
    std::shared_ptr<Citizen> citizen = createSheriff(30, 40, 20);
    attack(createZombie(20, 30), citizen);
}