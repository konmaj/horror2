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

bool CustomAttackTime::shouldAttack(Time time) {
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

SmallTown::Status::Status(const std::string &monsterName, 
                          HealthPoints monsterHealth,
                          size_t aliveCount)
        : monsterName_(monsterName), monsterHealth_(monsterHealth),
          aliveCount_(aliveCount) {}

std::string SmallTown::Status::getMonsterName() const {
    return monsterName_;
}

HealthPoints SmallTown::Status::getMonsterHealth() const {
    return monsterHealth_;
}

size_t SmallTown::Status::getAliveCitizens() const {
    return aliveCount_;
}

SmallTown::Status SmallTown::getStatus() {
    return Status(monster_->getName(), monster_->getHealth(),
                  citizens_->countAlive());
}

void SmallTown::tick(Time timeStep) {
    checkState();
    if (AttackTime::shouldAttack(time_)) {
        for (Citizen& citizen : citizens_) {
            attack(monster_, citizen);
        }
    }
    time_ = (time_ + timeStep) % (maxTime_ + 1);
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

void attack(MonsterComponent& monster, Citizen& citizen) {
    if (citizen.getHealth() > 0)
    citizen.takeDamage(monster.getAttackPower());
    
}

void attack(MonsterComponent& monster, Sheriff& sheriff) {
    sheriff.takeDamage(monster.getAttackPower());
    monster.takeDamge
}
