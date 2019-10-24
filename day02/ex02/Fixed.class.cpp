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

bool                Fixed::operator<(Fixed const & elem) {
    return (this->_value < elem.getRawBits());
}

bool                Fixed::operator<=(Fixed const & elem){
    return (this->_value <= elem.getRawBits());
}

bool                Fixed::operator>(Fixed const & elem) {
    return (this->_value > elem.getRawBits());
}

bool                Fixed::operator>=(Fixed const & elem) {
    return (this->_value >= elem.getRawBits());
}

bool                Fixed::operator==(Fixed const & elem) {
    return (this->_value == elem.getRawBits());
}

bool                Fixed::operator!=(Fixed const & elem) {
    return (this->_value != elem.getRawBits());
}

Fixed               Fixed::operator+(Fixed const & elem) {
    Fixed           newElem;
    newElem.setRawBits(this->_value + elem.getRawBits());
    return newElem;
}

Fixed               Fixed::operator-(Fixed const & elem) {
    Fixed           newElem;
    newElem.setRawBits(this->_value - elem.getRawBits());
    return newElem;
}

Fixed               Fixed::operator*(Fixed const & elem) {
    Fixed           newElem;
    newElem.setRawBits(this->toFloat()* elem.getRawBits());
    return newElem;
}

Fixed               Fixed::operator/(Fixed const & elem) {
    Fixed           newElem;
    newElem.setRawBits(this->toFloat() / elem.getRawBits());
    return newElem;
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

Fixed &             Fixed::operator++(void) {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed               Fixed::operator++(int n) {
    Fixed           newInstance = *this;
    ++*this;
    return newInstance;
}

Fixed &             Fixed::operator--(void) {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed               Fixed::operator--(int n) {
    Fixed           newInstance = *this;
    --*this;
    return newInstance;
}

std::ostream    &           operator<<(std::ostream & o, Fixed const &f) {
    o << f.toFloat();
    return o;
}

Fixed        &Fixed::min(Fixed &a, Fixed &b) {
    return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

const Fixed  &Fixed::min(Fixed const &a, Fixed const &b) {
    return ((a.getRawBits() < b.getRawBits()) ? a : b);
}

Fixed        &Fixed::max(Fixed &a, Fixed &b) {
    return ((a.getRawBits() > b.getRawBits()) ? a : b);
}

const Fixed  &Fixed::max(Fixed const &a, Fixed const &b) {
    return ((a.getRawBits() > b.getRawBits()) ? a : b);
}