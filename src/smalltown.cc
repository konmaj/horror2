// Konrad Majewski, Mateusz Warzyński
#include "smalltown.h"

GroupOfCitizens::GroupOfCitizens(std::vector<Citizen> citizens) : citizens_(citizens) {}

bool GroupOfCitizens::isAlive() {
    for (auto &c : citizens_) {
        if (c.isAlive())
            return true;
    }
    return false;
}

SmallTown::Builder::Builder() : monster_(default_monster), citizens_(default_citizens), start_time_(default_time),
                                max_time_(default_time) {}

SmallTown SmallTown::Builder::build() {
    return SmallTown(monster_, citizens_, start_time_, max_time_, attack_time_);
}

SmallTown::Builder &SmallTown::Builder::setCitizens(std::vector<Citizen> citizens) {
    citizens_ = citizens;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::setMonster(Monster monster) {
    monster_ = monster;
    return *this;
}

SmallTown::Builder & SmallTown::Builder::setStartTime(Time time) {
    start_time_ = time;
    return *this;
}

SmallTown::Builder & SmallTown::Builder::setMaxTime(Time time) {
    max_time_ = time;
    return *this;
}

SmallTown::Builder & SmallTown::Builder::setAttackTime(AttackTime *attack_time) {
    attack_time_ = attack_time;
    return *this;
}

std::tuple<std::string, HealthPoints, size_t> SmallTown::getStatus() {
    return std::make_tuple("", 0, 0);
}

void SmallTown::tick(Time timeStep) {
    if (attack_time_->shouldAttack(time_))
        performAttack();
    time_ += timeStep;
}

void SmallTown::performAttack() {
    // TODO: implement SmallTown::performAttack()
}