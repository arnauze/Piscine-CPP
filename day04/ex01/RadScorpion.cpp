# include "RadScorpion.hpp"

RadScorpion::RadScorpion(int hp) : Enemy(hp, "RadScorpion") {
    std::cout << "* click click click *" << std::endl;
    return ;
}

RadScorpion::~RadScorpion( void ) {
    std::cout << "“* SPROTCH *" << std::endl;
    return ;
}

RadScorpion::RadScorpion( RadScorpion const & mutant ) {
    *this = mutant;
    return ;
}

RadScorpion &RadScorpion::operator=(RadScorpion const & mutant) {
    this->setType(mutant.getType());
    this->setHp(mutant.getHp());
    return *this;
}