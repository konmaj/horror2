// Konrad Majewski, Mateusz Warzyński
#include "smalltown.h"

GroupOfCitizens::GroupOfCitizens(std::vector<Citizen> citizens) : citizens(citizens) {}

bool GroupOfCitizens::isAlive() {
    for (auto &c : citizens) {
        if (c.isAlive())
            return true;
    }
    return false;
}

AttackPower GroupOfCitizens::getAttackPower() {
    AttackPower power = 0;
    for (auto &c : citizens) {
        if (c.isAlive())
            power += c.getAttackPower();
    }
    return power;
}

void GroupOfCitizens::takeDamage(AttackPower damage) {
    for (auto &c : citizens)
        c.takeDamage(damage);
}

SmallTown::Builder::Builder() : monster_(default_monster), citizens_(default_citizens), start_time_(default_time),
                                max_time_(default_max_time) {
    attack_time_ = AttackTime();
}

SmallTown SmallTown::Builder::build() {
    return SmallTown(monster_, citizens_, start_time_, max_time_, attack_time_);
}

SmallTown::Builder &SmallTown::Builder::setCitizens(std::vector<Citizen> citizens) {
    citizens_ = citizens;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::addCitizen(Citizen citizen) {
    citizens_.emplace_back(citizen);
    return *this;
}

SmallTown::Builder &SmallTown::Builder::setMonster(Monster monster) {
    monster_ = monster;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::setStartTime(Time time) {
    start_time_ = time;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::setMaxTime(Time time) {
    max_time_ = time;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::setAttackTime(AttackTime attack_time) {
    attack_time_ = attack_time;
    return *this;
}

std::tuple<std::string, HealthPoints, size_t> SmallTown::getStatus() {
    // TODO: implement SmallTown::getStatus()
    return std::make_tuple("", 0, 0);
}

void SmallTown::tick(Time timeStep) {
    checkState();
    if (attack_time_.shouldAttack(time_)) {
        citizens_.takeDamage(monster_.getAttackPower());
        monster_.takeDamage(citizens_.getAttackPower());
    }
    time_ += timeStep;
}

void SmallTown::checkState() {
    bool monsterAlive = monster_.isAlive();
    bool citizensAlive = citizens_.isAlive();
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