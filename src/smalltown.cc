// Konrad Majewski, Mateusz Warzyński
#include "smalltown.h"

const std::string CITIZENS_WON = "CITIZENS WON";
const std::string MONSTER_WON = "MONSTER WON";
const std::string DRAW = "DRAW";

GroupOfCitizens::GroupOfCitizens(const std::vector<std::shared_ptr<Citizen>> &citizens) : Citizen(0, 0),
                                                                                          citizens_(citizens) {
    healthPoints_ = getHealth();
}

HealthPoints GroupOfCitizens::getHealth() {
    HealthPoints health = 0;
    for (auto &citizen : citizens_)
        health += citizen->getHealth();
    return health;
}

void GroupOfCitizens::attackedBy(std::shared_ptr<Monster> &monster) {
    for (auto &citizen : citizens_)
        citizen->attackedBy(monster);
    healthPoints_ = getHealth();
}

size_t GroupOfCitizens::countAlive() {
    size_t count = 0;
    for (auto &citizen : citizens_) {
        if (citizen->isAlive())
            count += 1;
    }
    return count;
}

bool CustomAttackTime::shouldAttack(Time time) {
    return (time % 3 == 0 || time % 13 == 0) && time % 7 != 0;
}

SmallTown SmallTown::Builder::build() {
    std::shared_ptr<GroupOfCitizens> citizens = std::make_shared<GroupOfCitizens>(citizens_);
    return SmallTown(monster_, citizens, start_time_, max_time_, attack_time_);
}

SmallTown::Builder &SmallTown::Builder::citizen(const std::shared_ptr<Citizen> &citizen) {
    if (added_citizens.find(citizen) != added_citizens.end())
        return *this;
    added_citizens.insert(citizen);
    citizens_.emplace_back(citizen);
    return *this;
}

SmallTown::Builder &SmallTown::Builder::monster(const std::shared_ptr<Monster> &monster) {
    monster_ = monster;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::startTime(const Time time) {
    start_time_ = time;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::maxTime(const Time time) {
    max_time_ = time;
    return *this;
}

SmallTown::Builder &SmallTown::Builder::attackTime(const std::shared_ptr<AttackTime> &attack_time) {
    attack_time_ = attack_time;
    return *this;
}

SmallTown::Status::Status(const std::string &monsterName, const HealthPoints &healthPoints, const size_t &aliveCount)
        : monsterName_(monsterName), monsterHealth_(healthPoints), aliveCount_(aliveCount) {}

size_t SmallTown::Status::getAliveCitizens() const {
    return aliveCount_;
}

HealthPoints SmallTown::Status::getMonsterHealth() const {
    return monsterHealth_;
}

std::string SmallTown::Status::getMonsterName() const {
    return monsterName_;
}

SmallTown::SmallTown(std::shared_ptr<Monster> &m, std::shared_ptr<GroupOfCitizens> &c, Time t, Time mt,
                     std::shared_ptr<AttackTime> &at) : monster_(m), citizens_(c), time_(t), max_time_(mt),
                                                        attack_time_(at) {}

SmallTown::Status SmallTown::getStatus() {
    return Status(monster_->getName(), monster_->getHealth(), citizens_->countAlive());
}

void SmallTown::tick(Time timeStep) {
    checkState();
    if (attack_time_->shouldAttack(time_))
        citizens_->attackedBy(monster_);
    time_ += timeStep;
}

void SmallTown::checkState() {
    bool monsterAlive = monster_->isAlive();
    bool citizensAlive = citizens_->isAlive();
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
