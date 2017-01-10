// Konrad Majewski, Mateusz Warzyński
#include "smalltown.h"

const std::string CITIZENS_WON = "CITIZENS WON";
const std::string MONSTER_WON = "MONSTER WON";
const std::string DRAW = "DRAW";

GroupOfCitizens::GroupOfCitizens(std::vector<Citizen> citizens) : citizens(citizens) {}

// TODO
HealthPoints GroupOfCitizens::getHealth() {
    return 0;
}

AttackPower GroupOfCitizens::getAttackPower() {
    AttackPower power = 0;
    for (auto &c : citizens) {
        if (c.getHealth() > 0)
            // TODO
            power += 0; //c.getAttackPower();
    }
    return power;
}

void GroupOfCitizens::takeDamage(AttackPower damage) {
    for (auto &c : citizens)
        c.takeDamage(damage);
}

bool AttackTime::shouldAttack(Time time) {
    return (time % 3 == 0 || time % 13 == 0) && time % 7 != 0;
}

SmallTown::Builder::Builder() : monster_(default_monster), citizens_(default_citizens), start_time_(default_time),
                                max_time_(default_max_time) {}

SmallTown SmallTown::Builder::build() {
    return SmallTown(monster_, citizens_, start_time_, max_time_, attack_time_);
}

SmallTown::Builder &SmallTown::Builder::citizens(std::vector<Citizen> citizens) {
    citizens_ = citizens;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::citizen(Citizen citizen) {
    citizens_.emplace_back(citizen);
    return *this;
}

SmallTown::Builder &SmallTown::Builder::monster(Monster monster) {
    monster_ = monster;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::startTime(Time time) {
    start_time_ = time;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::maxTime(Time time) {
    max_time_ = time;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::attackTime(AttackTime attack_time) {
    attack_time_ = attack_time;
    return *this;
}

std::tuple<std::string, HealthPoints, size_t> SmallTown::getStatus() {
    // TODO: implement SmallTown::getStatus()
    return std::make_tuple("", 0, 0);
}

void SmallTown::tick(Time timeStep) {
    checkState();
    if (AttackTime::shouldAttack(time_)) {
        citizens_.takeDamage(monster_.getAttackPower());
        monster_.takeDamage(citizens_.getAttackPower());
    }
    time_ += timeStep;
}

void SmallTown::checkState() {
    bool monsterAlive = monster_.getHealth() > 0;
    bool citizensAlive = citizens_.getHealth() > 0;
    if (monsterAlive && citizensAlive)
        return;
    if (monsterAlive) {
        std::cout << MONSTER_WON << std::endl;
        return;
    }
    if (citizensAlive) {
        std::cout << CITIZENS_WON << std::endl;
        return;
    }
    std::cout << DRAW << std::endl;
}