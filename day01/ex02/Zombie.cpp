# include "Zombie.hpp"

Zombie::Zombie(std::string n) : _name(n), _type("warrior") {
    return;
}

Zombie::~Zombie(void) {
    std::cout << this->_name << " has died." << std::endl;
    return;
}

void        Zombie::announce(void) const {
    std::cout << "<" << this->_name << " (" << this->_type << ")> Braiiiiiiiiiiiins..." << std::endl;
    return;
}

void        Zombie::setType(std::string t) {
    this->_type = t;
    return;
}