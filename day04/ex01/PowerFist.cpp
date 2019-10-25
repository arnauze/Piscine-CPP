# include "PowerFist.hpp"

PowerFist::PowerFist(void) : AWeapon("Power Fist", 8, 50) { return ; }

PowerFist::~PowerFist(void) { return ; }

PowerFist::PowerFist( PowerFist const & pFist ) {
    *this = pFist;
    return ;
}

PowerFist                 &PowerFist::operator=( PowerFist const & pFist ) {
    this->setName(pFist.getName());
    this->setApCost(pFist.getApCost());
    this->setDamage(pFist.getDamage());
    return *this;
}

void                        PowerFist::attack(void) {
    std::cout << "* pschhh... SBAM! *" << std::endl;
    return ;
}