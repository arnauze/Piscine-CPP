# include "Stack.class.hpp"

Stack::Stack( void ) { return ; }

Stack::~Stack( void ) { return ; }

void            Stack::add( std::string str ) {
    this->_elems.insert(this->_elems.begin(), str);
}

std::string     Stack::pop( void ) {
    std::string retStr;
    retStr = this->_elems.at(0);
    this->_elems.erase(this->_elems.begin());
    return retStr;
}

std::string     Stack::top( void ) {
    return this->_elems.at(0);
}

int             Stack::size( void ) {
    return this->_elems.size();
}

bool            Stack::isEmpty( void ) {
    return this->_elems.size() < 1;
}
