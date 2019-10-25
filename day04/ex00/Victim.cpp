# include "Victim.hpp"

Victim::Victim(void) { return ; }

Victim::Victim( std::string const & name ) : _name(name) {
    std::cout << "Some random victim called " << name << " just popped !" << std::endl;
    return ;
}

Victim::~Victim( void ) { 
    std::cout << "Victim " << this->getName() << " just died for no apparent reason !" << std::endl;
}

Victim::Victim( Victim const & victim) {
    *this = victim;
    return ;
}

Victim        &Victim::operator=(Victim const & victim) {
    this->setName(victim.getName());
    return *this;
}

std::string     Victim::getName(void) const {
    return this->_name;
}

void            Victim::setName(std::string const & name) {
    this->_name = name;
    return ;
}

void            Victim::getPolymorphed(void) const {
    std::cout << this->getName() << " has been turned into a cute little sheep !" << std::endl;
}

std::ostream    &operator<<(std::ostream & out, Victim const & in) {
    out << "I'm " << in.getName() << " and I like otters !" << std::endl;
    return out;
}