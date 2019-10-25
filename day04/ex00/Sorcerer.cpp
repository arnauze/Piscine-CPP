# include "Sorcerer.hpp"

Sorcerer::Sorcerer(void) { return ; }

Sorcerer::Sorcerer(std::string const & name, std::string const & title) : _name(name), _title(title) {
    std::cout << name << ", " << title << ", is born !" << std::endl;
    return ;
}

Sorcerer::~Sorcerer( void ) {
    std::cout << this->getName() << ", " << this->getTitle() << ", is dead. Consequences will never be the same !" << std::endl;
    return ;
}

Sorcerer::Sorcerer( Sorcerer const & sorcerer ) {
    *this = sorcerer;
    return ;
}

Sorcerer                &Sorcerer::operator=(Sorcerer const & sorcerer) {
    this->setName(sorcerer.getName());
    this->setTitle(sorcerer.getTitle());
    return *this;
}

std::string             Sorcerer::getName(void) const {
    return this->_name;
}

std::string             Sorcerer::getTitle(void) const {
    return this->_title;
}

void                    Sorcerer::setName(std::string const & name) {
    this->_name = name;
    return ;
}

void                    Sorcerer::setTitle(std::string const & title) {
    this->_title = title;
    return ;
}

void                    Sorcerer::polymorph(Victim const & victim) const {
    victim.getPolymorphed();
    return ;
}

std::ostream            &operator<<(std::ostream & out, Sorcerer const & sorcerer) {
    out << "I am " << sorcerer.getName() << ", " << sorcerer.getTitle() << ", and I like ponies !" << std::endl;
    return out;
}