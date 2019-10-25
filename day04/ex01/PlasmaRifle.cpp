# include "PlasmaRifle.hpp"

PlasmaRifle::PlasmaRifle(void) : AWeapon("Plasma Rifle", 5, 21) { return ; }

PlasmaRifle::~PlasmaRifle(void) { return ; }

PlasmaRifle::PlasmaRifle( PlasmaRifle const & pRifle ) {
    *this = pRifle;
    return ;
}

PlasmaRifle                 &PlasmaRifle::operator=( PlasmaRifle const & pRifle ) {
    this->setName(pRifle.getName());
    this->setApCost(pRifle.getApCost());
    this->setDamage(pRifle.getDamage());
    return *this;
}

void                        PlasmaRifle::attack(void) {
    std::cout << "* piouuu piouuu piouuu *" << std::endl;
    return ;
}