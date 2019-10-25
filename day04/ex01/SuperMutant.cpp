# include "SuperMutant.hpp"

SuperMutant::SuperMutant(int hp) : Enemy(hp, "Super Mutant") {
    std::cout << "Gaaah. Me want smash heads !" << std::endl;
    return ;
}

SuperMutant::~SuperMutant( void ) {
    std::cout << "Aaargh ..." << std::endl;
    return ;
}

SuperMutant::SuperMutant( SuperMutant const & mutant ) {
    *this = mutant;
    return ;
}

SuperMutant &SuperMutant::operator=(SuperMutant const & mutant) {
    this->setType(mutant.getType());
    this->setHp(mutant.getHp());
    return *this;
}

void        SuperMutant::takeDamage(int dmg) {
    Enemy::takeDamage(dmg - 3);
    return ;
}