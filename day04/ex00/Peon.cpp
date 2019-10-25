# include "Peon.hpp"

Peon::Peon(void) : Victim() { return ; }

Peon::Peon(std::string const & name) : Victim(name) {
    std::cout << "Zog zog." << std::endl;
    return ;
}

Peon::~Peon( void ) {
    std::cout << "Bleuark..." << std::endl;
    return ;
}

Peon::Peon( Peon const & peon ) {
    *this = peon;
    return ;
}

Peon        &Peon::operator=(Peon const & peon ) {
    this->setName(peon.getName());
    return *this;
}

void              Peon::getPolymorphed( void ) const {
    std::cout << this->getName() << " has been turned into a pink pony !" << std::endl;
    return ;
}

std::ostream        &operator<<(std::ostream & out, Peon const & peon) {
    out << "I'm " << peon.getName() << " and I like otters !" << std::endl;
    return out;
}