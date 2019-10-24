#include "Fixed.class.hpp"

Fixed::Fixed( void ) : _value(0) { 
    std::cout << "Default constructor called" << std::endl;
    return ;
}
Fixed::~Fixed( void ) {
    std::cout << "Destructor called" << std::endl;
    return ;
}
Fixed::Fixed( Fixed const & elem ) {
    std::cout << "Copy constructor called" << std::endl;
    *this = elem;
    return ;
}

Fixed &             Fixed::operator=(Fixed const & elem) {
    std::cout << "Assignation operator called" << std::endl;
    this->_value = elem.getRawBits();
    return *this;
}

int                 Fixed::getRawBits( void ) const {
    std::cout << "getRawBits member function called" << std::endl;
    return this->_value;
}

void                Fixed::setRawBits(int const raw) {
    std::cout << "setRawBits member function called" << std::endl;
    this->_value = raw;
    return ;
}
