#ifndef ZOMBIEHORDE_HPP
# define ZOMBIEHORDE_HPP

# include "Zombie.hpp"
#include <vector>
#include <algorithm>
#include <functional>

class               ZombieHorde {

    public:
        ZombieHorde(int N);
        ~ZombieHorde(void);
        void    annouce(void);

    private:
        Zombie*  _zombies;
        int      _n;
        
};

#endif