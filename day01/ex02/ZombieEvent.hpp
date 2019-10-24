#ifndef ZOMBIEEVENT_HPP
# define ZOMBIEEVENT_HPP

# include "Zombie.hpp"

class ZombieEvent
{
    public:
        ZombieEvent(void);
        ~ZombieEvent(void);
        void        setZombieType(Zombie *z, std::string t);
        Zombie*     newZombie(std::string n);
};

#endif