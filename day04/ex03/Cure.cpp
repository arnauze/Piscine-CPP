# include "Cure.hpp"

Cure::Cure(void) : AMateria("cure") {
    return ;
}

Cure::~Cure( void ) {
    return ;
}

Cure::Cure( Cure const & cure ) {
    *this = cure;
    return ;
}

Cure                             &Cure::operator=(Cure const & cure ) {
    this->setXP(cure.getXP());
    return *this;
}

AMateria                        *Cure::clone() const {
    AMateria        *newReturn = (AMateria *)new Cure();
    newReturn->setXP(this->getXP());
    return newReturn;
}

void                        Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << " wounds *" << std::endl;
    AMateria::use(target);
    return ;
}