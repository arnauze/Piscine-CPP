# include "Ice.hpp"

Ice::Ice(void) : AMateria("ice") {
    return ;
}

Ice::~Ice( void ) {
    return ;
}

Ice::Ice( Ice const & ice ) {
    *this = ice;
    return ;
}

Ice                             &Ice::operator=(Ice const & ice ) {
    this->setXP(ice.getXP());
    return *this;
}

AMateria                        *Ice::clone() const {
    AMateria        *newReturn = (AMateria *)new Ice();
    newReturn->setXP(this->getXP());
    return newReturn;
}

void                        Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
    AMateria::use(target);
    return ;
}