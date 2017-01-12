// Konrad Majewski, Mateusz Warzyński
#include "smalltown.h"

const std::string CITIZENS_WON = "CITIZENS WON";
const std::string MONSTER_WON = "MONSTER WON";
const std::string DRAW = "DRAW";

bool CustomAttackTime::shouldAttack(Time time) const {
    return (time % 3 == 0 || time % 13 == 0) && time % 7 != 0;
}

SmallTown::Builder::Builder() {
    attackTime_ = std::make_shared<CustomAttackTime>();
}

SmallTown::Builder&
SmallTown::Builder::citizen(const std::shared_ptr<Citizen>& citizen) {
    if (addedCitizens_.find(citizen) != addedCitizens_.end()) {
        return *this;
    }
    addedCitizens_.insert(citizen);
    citizens_.emplace_back(citizen);
    return *this;
}

SmallTown::Builder&
SmallTown::Builder::monster(const std::shared_ptr<MonsterComponent>& monster) {
    monster_ = monster;
    return *this;
}

SmallTown::Builder& SmallTown::Builder::startTime(Time time) {
    startTime_ = time;
    return *this;
}

SmallTown::Builder& SmallTown::Builder::maxTime(Time time) {
    maxTime_ = time;
    return *this;
}

SmallTown::Builder&
SmallTown::Builder::attackTime(const std::shared_ptr<AttackTime>& attackTime) {
    attackTime_ = attackTime;
    return *this;
}

SmallTown SmallTown::Builder::build() {
    return SmallTown(monster_, citizens_, startTime_, maxTime_, attackTime_);
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

SmallTown::Status SmallTown::getStatus() const {
    return Status(monster_->getName(), monster_->getHealth(), aliveCounter_);
}

void SmallTown::tick(Time timeStep) {
    checkState();
    if (attackTime_->shouldAttack(time_)) {
        std::cout << "Atak\n";
        for (auto& citizen : citizens_) {
            attack(monster_, citizen);
        }
    }
    time_ = (time_ + timeStep) % (maxTime_ + 1);
}

void SmallTown::checkState() {
    bool monsterAlive = monster_->getHealth() > 0;
    bool citizensAlive = aliveCounter_ > 0;
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

void attack(const std::shared_ptr<MonsterComponent>& monster,
            const std::shared_ptr<Citizen>& citizen) {
    if (monster->getHealth() > 0) {
        citizen->takeDamage(monster->getAttackPower());
    }
}

void attack(const std::shared_ptr<MonsterComponent>& monster,
            const std::shared_ptr<Sheriff>& sheriff) {
    std::cout << "Hurra!\n";
    if (monster->getHealth() > 0 && sheriff->getHealth() > 0) {
        sheriff->takeDamage(monster->getAttackPower());
        monster->takeDamage(sheriff->getAttackPower());
    }
}
