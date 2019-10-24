# include "ZombieHorde.hpp"

ZombieHorde::ZombieHorde(int n) {
    this->_zombies = new Zombie[n];
    this->_n = n;
    return ;
}

ZombieHorde::~ZombieHorde( void ) {
    delete [] this->_zombies;
    return;
}

void ZombieHorde::annouce(void) {
    int i = 0;
    while (i < this->_n) {
        this->_zombies[i].announce();
        i++;
    }
    return;
}