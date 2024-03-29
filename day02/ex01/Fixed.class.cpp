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
    this->_value = elem._value;
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

Fixed::Fixed( int const n ) : _value(n << this->_fractional){
    std::cout << "Int constructor called" << std::endl;
    return ;
}

Fixed::Fixed( float const f ) : _value(roundf(f * (1 << this->_fractional))) {
    std::cout << "Float constructor called" << std::endl;
    return ;
}

float               Fixed::toFloat( void ) const {
    return (this->_value / (float)(1 << this->_fractional));
}


int                 Fixed::toInt( void ) const {
    return (this->_value >> this->_fractional);
}

std::ostream    &           operator<<(std::ostream & o, Fixed const &f) {
    o << f.toFloat();
    return o;
}