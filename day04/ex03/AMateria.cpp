# include "AMateria.hpp"

AMateria::AMateria(void) : xp(0) { return ; }

AMateria::AMateria(std::string const & type) : xp(0), type(type){ return ; }

AMateria::~AMateria( void ) { return ; }

std::string const           &AMateria::getType() const {
    return this->type;
}

unsigned int                AMateria::getXP() const {
    return this->xp;
}

void                        AMateria::setXP(unsigned int xp) {
    this->xp = xp;
    return ;
}

void                        AMateria::use(ICharacter& target) {
    (void)target;
    this->xp += 10;
    return ;
}

AMateria        &AMateria::operator=(AMateria const & materia) {
    this->setXP(materia.getXP());
    return *this;
}