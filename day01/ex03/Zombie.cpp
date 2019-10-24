# include "Zombie.hpp"

Zombie::Zombie( void ) : _name(this->_getRandomName()), _type("Alliance") {
    return;
}

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

std::string     Zombie::_getRandomName(void) const {

    const char tab[] = "abcdefghijklmnopqrstuvwxyz";
    int         i = -1;
    std::string str(10, 0);

    while (++i < 10) {
        str[i] = tab[std::rand() % 27];
    }

    return str;

}