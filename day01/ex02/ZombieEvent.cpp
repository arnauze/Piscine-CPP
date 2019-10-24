#include "ZombieEvent.hpp"

ZombieEvent::ZombieEvent(void) {
    return;
}

ZombieEvent::~ZombieEvent(void) {
    return;
}

void            ZombieEvent::setZombieType(Zombie *z, std::string type) {
    z->setType(type);
    return;
}

Zombie*         ZombieEvent::newZombie(std::string n) {
    Zombie*     newZombie = new Zombie(n);
    return newZombie;
}