#ifndef HUMAN_HPP
# define HUMAN_HPP

# include "Human.hpp"

Human::Human( void ) : _brain(Brain()){ return ; }

Human::~Human( void ) { return ; }

std::string            Human::identify( void ) {
    return this->getBrain().identify();
}

Brain &           Human::getBrain(void) {
    return _brain;
}

#endif