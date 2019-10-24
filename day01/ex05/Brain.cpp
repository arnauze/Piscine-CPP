#include "Brain.hpp"

Brain::Brain( void ) : _size(20), _power(5), _color("pink"){ std::cout << "Brain created" << std::endl; return ; }
Brain::Brain(int size, int power, std::string color) : _size(size), _power(power), _color(color) { return ; }
Brain::~Brain( void ) { std::cout << "Brain destroyed" << std::endl; return ; }

std::string        Brain::identify( void ) {

    std::ostringstream oss;
    oss << "I'M BRAAAAAAAAIIIIIIIN! MY SIZE IS " << this->_size << " I'M HUGE RIGHT ? I HAVE A POWER OF " << this->_power << " BUT I NEED MOOOOOORE!!!!!! I'M " << this->_color << " AND MY ADDRESS IN MEMORY IS " << this;
    std::string str = oss.str();
    return str;
}