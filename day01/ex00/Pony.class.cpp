# include "Pony.class.hpp"

Pony::Pony(std::string n, std::string c, std::string g) : name(n), color(c), gender(g) {
    std::cout << "New pony named " << this->name << " of color " << this->color << " and of gender " << this->gender << " created!" << std::endl;
    return;
}

Pony::~Pony( void ) {
    std::cout << this->name << " has died in enormous suffering :D" << std::endl;
    return;
}